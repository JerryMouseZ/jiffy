from thrift.Thrift import TApplicationException, TMessageType
from thrift.protocol.TBinaryProtocol import TBinaryProtocolAccelerated
from thrift.transport import TTransport, TSocket
from thrift.transport.TTransport import TTransportException

from elasticmem.kv import block_request_service, block_response_service
from elasticmem.kv.kv_ops import KVOps, op_type, KVOpType


class CommandResponseReader:
    def __init__(self, iprot):
        self.iprot = iprot

    def recv_response(self):
        (fname, mtype, rseqid) = self.iprot.readMessageBegin()
        if mtype == TMessageType.EXCEPTION:
            x = TApplicationException()
            x.read(self.iprot)
            self.iprot.readMessageEnd()
            raise x
        args = block_response_service.response_args()
        args.read(self.iprot)
        self.iprot.readMessageEnd()
        if args.seq is not None and args.result is not None:
            return args.seq.client_seq_no, args.result
        raise TApplicationException(TApplicationException.MISSING_RESULT, "Command response failure: unknown result")

    def recv_responses(self, count):
        return [self.recv_response() for _ in range(count)]


class BlockClient:
    def __init__(self, host, port, block_id):
        self.id_ = block_id
        self.socket_ = TSocket.TSocket(host, port)
        self.transport_ = TTransport.TBufferedTransport(self.socket_)
        self.protocol_ = TBinaryProtocolAccelerated(self.transport_)
        self.client_ = block_request_service.Client(self.protocol_)
        ex = None
        for i in range(3):
            try:
                self.transport_.open()
            except TTransportException as e:
                ex = e
                continue
            except Exception:
                raise
            else:
                break
        else:
            raise TTransportException(ex.type, "Connection failed {}:{}: {}".format(host, port, ex.message))

    def __del__(self):
        self.disconnect()

    def disconnect(self):
        if self.transport_.isOpen():
            self.transport_.close()

    def get_response_reader(self, client_id):
        self.client_.register_client_id(self.id_, client_id)
        return CommandResponseReader(self.protocol_)

    def get_client_id(self):
        return self.client_.get_client_id()

    def send_request(self, seq, cmd_id, arguments):
        self.client_.command_request(seq, self.id_, cmd_id, arguments)


class BlockChainClient:
    def __init__(self, chain, request_timeout_s=3.0):
        self.seq = block_request_service.sequence_id(-1, 0, -1)
        self.chain = chain
        self.request_timeout_s = request_timeout_s
        h_host, h_port, _, _, _, h_bid = chain[0].split(':')
        self.head = BlockClient(h_host, int(h_port), int(h_bid))
        self.seq.client_id = self.head.get_client_id()
        if len(chain) == 1:
            self.tail = self.head
        else:
            t_host, t_port, _, _, _, t_bid = chain[-1].split(':')
            self.tail = BlockClient(t_host, int(t_port), int(t_bid))
        self.response_reader = self.tail.get_response_reader(self.seq.client_id)
        self.response_cache = {}

    def disconnect(self):
        self.head.disconnect()
        if self.head != self.tail:
            self.tail.disconnect()

    def _send_cmd(self, client, cmd_id, args):
        op_seq = self.seq.client_seq_no
        client.send_request(self.seq, cmd_id, args)
        self.seq.client_seq_no += 1
        return op_seq

    def send_cmd(self, cmd_id, args):
        if op_type(cmd_id) == KVOpType.accessor:
            return self._send_cmd(self.tail, cmd_id, args)
        else:
            return self._send_cmd(self.head, cmd_id, args)

    def _recv_cmd(self, op_seq):
        if op_seq in self.response_cache:
            result = self.response_cache[op_seq]
            del self.response_cache[op_seq]
            return result

        while True:
            recv_seq, result = self.response_reader.recv_response()
            if op_seq == recv_seq:
                return result
            else:
                self.response_cache[recv_seq] = result

    def recv_cmd(self, op_seq):
        return self._recv_cmd(op_seq)

    def _run_command(self, client, cmd_id, args):
        op_seq = self._send_cmd(client, cmd_id, args)
        return self._recv_cmd(op_seq)

    def run_command(self, cmd_id, args):
        if op_type(cmd_id) == KVOpType.accessor:
            return self._run_command(self.tail, cmd_id, args)
        else:
            return self._run_command(self.head, cmd_id, args)

    def get(self, key):
        return self._run_command(self.tail, KVOps.get, [key])[0]

    def put(self, key, value):
        return self._run_command(self.head, KVOps.put, [key, value])[0]

    def update(self, key, value):
        return self._run_command(self.head, KVOps.update, [key, value])[0]

    def remove(self, key):
        return self._run_command(self.head, KVOps.remove, [key])[0]

    def num_keys(self):
        return self._run_command(self.tail, KVOps.num_keys, [])[0]

    def redirected_get(self, key):
        return self._run_command(self.tail, KVOps.get, [key, '!redirected'])[0]

    def redirected_put(self, key, value):
        return self._run_command(self.head, KVOps.put, [key, value, '!redirected'])[0]

    def redirected_update(self, key, value):
        return self._run_command(self.head, KVOps.update, [key, value, '!redirected'])[0]

    def redirected_remove(self, key):
        return self._run_command(self.head, KVOps.remove, [key, '!redirected'])[0]

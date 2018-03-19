#ifndef ELASTICMEM_KV_RPC_SERVICE_FACTORY_H
#define ELASTICMEM_KV_RPC_SERVICE_FACTORY_H

#include "kv_block.h"
#include "kv_rpc_service.h"
#include "../notification/subscription_map.h"

namespace elasticmem {
namespace storage {

class kv_rpc_service_factory : public kv_rpc_serviceIfFactory {
 public:
  explicit kv_rpc_service_factory(std::vector<std::shared_ptr<kv_block>> &blocks,
                                  std::vector<std::shared_ptr<subscription_map>> &sub_maps);
  kv_rpc_serviceIf *getHandler(const ::apache::thrift::TConnectionInfo &connInfo) override;
  void releaseHandler(kv_rpc_serviceIf *anIf) override;
 private:
  std::vector<std::shared_ptr<kv_block>> &blocks_;
  std::vector<std::shared_ptr<subscription_map>> &sub_maps_;
};

}
}

#endif //ELASTICMEM_KV_RPC_SERVICE_FACTORY_H

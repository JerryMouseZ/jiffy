/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "directory_service_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace elasticmem { namespace directory {

int _krpc_perm_optionsValues[] = {
  rpc_replace,
  rpc_add,
  rpc_remove
};
const char* _krpc_perm_optionsNames[] = {
  "rpc_replace",
  "rpc_add",
  "rpc_remove"
};
const std::map<int, const char*> _rpc_perm_options_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _krpc_perm_optionsValues, _krpc_perm_optionsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const rpc_perm_options val) {
  std::map<int, const char*>::const_iterator it = _rpc_perm_options_VALUES_TO_NAMES.find(val);
  if (it != _rpc_perm_options_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

int _krpc_file_typeValues[] = {
  rpc_none,
  rpc_regular,
  rpc_directory
};
const char* _krpc_file_typeNames[] = {
  "rpc_none",
  "rpc_regular",
  "rpc_directory"
};
const std::map<int, const char*> _rpc_file_type_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _krpc_file_typeValues, _krpc_file_typeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const rpc_file_type val) {
  std::map<int, const char*>::const_iterator it = _rpc_file_type_VALUES_TO_NAMES.find(val);
  if (it != _rpc_file_type_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

int _krpc_storage_modeValues[] = {
  rpc_in_memory,
  rpc_in_memory_grace,
  rpc_flushing,
  rpc_on_disk
};
const char* _krpc_storage_modeNames[] = {
  "rpc_in_memory",
  "rpc_in_memory_grace",
  "rpc_flushing",
  "rpc_on_disk"
};
const std::map<int, const char*> _rpc_storage_mode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _krpc_storage_modeValues, _krpc_storage_modeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const rpc_storage_mode val) {
  std::map<int, const char*>::const_iterator it = _rpc_storage_mode_VALUES_TO_NAMES.find(val);
  if (it != _rpc_storage_mode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

int _krpc_remove_modeValues[] = {
  rpc_delete,
  rpc_flush
};
const char* _krpc_remove_modeNames[] = {
  "rpc_delete",
  "rpc_flush"
};
const std::map<int, const char*> _rpc_remove_mode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _krpc_remove_modeValues, _krpc_remove_modeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const rpc_remove_mode val) {
  std::map<int, const char*>::const_iterator it = _rpc_remove_mode_VALUES_TO_NAMES.find(val);
  if (it != _rpc_remove_mode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


rpc_file_status::~rpc_file_status() throw() {
}


void rpc_file_status::__set_type(const rpc_file_type val) {
  this->type = val;
}

void rpc_file_status::__set_permissions(const rpc_perms val) {
  this->permissions = val;
}

void rpc_file_status::__set_last_write_time(const int64_t val) {
  this->last_write_time = val;
}
std::ostream& operator<<(std::ostream& out, const rpc_file_status& obj)
{
  obj.printTo(out);
  return out;
}


void swap(rpc_file_status &a, rpc_file_status &b) {
  using ::std::swap;
  swap(a.type, b.type);
  swap(a.permissions, b.permissions);
  swap(a.last_write_time, b.last_write_time);
}

rpc_file_status::rpc_file_status(const rpc_file_status& other1) {
  type = other1.type;
  permissions = other1.permissions;
  last_write_time = other1.last_write_time;
}
rpc_file_status& rpc_file_status::operator=(const rpc_file_status& other2) {
  type = other2.type;
  permissions = other2.permissions;
  last_write_time = other2.last_write_time;
  return *this;
}
void rpc_file_status::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "rpc_file_status(";
  out << "type=" << to_string(type);
  out << ", " << "permissions=" << to_string(permissions);
  out << ", " << "last_write_time=" << to_string(last_write_time);
  out << ")";
}


rpc_data_status::~rpc_data_status() throw() {
}


void rpc_data_status::__set_storage_mode(const rpc_storage_mode val) {
  this->storage_mode = val;
}

void rpc_data_status::__set_data_blocks(const std::vector<std::string> & val) {
  this->data_blocks = val;
}
std::ostream& operator<<(std::ostream& out, const rpc_data_status& obj)
{
  obj.printTo(out);
  return out;
}


void swap(rpc_data_status &a, rpc_data_status &b) {
  using ::std::swap;
  swap(a.storage_mode, b.storage_mode);
  swap(a.data_blocks, b.data_blocks);
}

rpc_data_status::rpc_data_status(const rpc_data_status& other10) {
  storage_mode = other10.storage_mode;
  data_blocks = other10.data_blocks;
}
rpc_data_status& rpc_data_status::operator=(const rpc_data_status& other11) {
  storage_mode = other11.storage_mode;
  data_blocks = other11.data_blocks;
  return *this;
}
void rpc_data_status::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "rpc_data_status(";
  out << "storage_mode=" << to_string(storage_mode);
  out << ", " << "data_blocks=" << to_string(data_blocks);
  out << ")";
}


rpc_dir_entry::~rpc_dir_entry() throw() {
}


void rpc_dir_entry::__set_name(const std::string& val) {
  this->name = val;
}

void rpc_dir_entry::__set_status(const rpc_file_status& val) {
  this->status = val;
}
std::ostream& operator<<(std::ostream& out, const rpc_dir_entry& obj)
{
  obj.printTo(out);
  return out;
}


void swap(rpc_dir_entry &a, rpc_dir_entry &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.status, b.status);
}

rpc_dir_entry::rpc_dir_entry(const rpc_dir_entry& other12) {
  name = other12.name;
  status = other12.status;
}
rpc_dir_entry& rpc_dir_entry::operator=(const rpc_dir_entry& other13) {
  name = other13.name;
  status = other13.status;
  return *this;
}
void rpc_dir_entry::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "rpc_dir_entry(";
  out << "name=" << to_string(name);
  out << ", " << "status=" << to_string(status);
  out << ")";
}


directory_rpc_service_exception::~directory_rpc_service_exception() throw() {
}


void directory_rpc_service_exception::__set_msg(const std::string& val) {
  this->msg = val;
}
std::ostream& operator<<(std::ostream& out, const directory_rpc_service_exception& obj)
{
  obj.printTo(out);
  return out;
}


void swap(directory_rpc_service_exception &a, directory_rpc_service_exception &b) {
  using ::std::swap;
  swap(a.msg, b.msg);
}

directory_rpc_service_exception::directory_rpc_service_exception(const directory_rpc_service_exception& other14) : TException() {
  msg = other14.msg;
}
directory_rpc_service_exception& directory_rpc_service_exception::operator=(const directory_rpc_service_exception& other15) {
  msg = other15.msg;
  return *this;
}
void directory_rpc_service_exception::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "directory_rpc_service_exception(";
  out << "msg=" << to_string(msg);
  out << ")";
}

const char* directory_rpc_service_exception::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: directory_rpc_service_exception";
  }
}


rpc_keep_alive::~rpc_keep_alive() throw() {
}


void rpc_keep_alive::__set_path(const std::string& val) {
  this->path = val;
}

void rpc_keep_alive::__set_bytes_added(const int64_t val) {
  this->bytes_added = val;
}
std::ostream& operator<<(std::ostream& out, const rpc_keep_alive& obj)
{
  obj.printTo(out);
  return out;
}


void swap(rpc_keep_alive &a, rpc_keep_alive &b) {
  using ::std::swap;
  swap(a.path, b.path);
  swap(a.bytes_added, b.bytes_added);
  swap(a.__isset, b.__isset);
}

rpc_keep_alive::rpc_keep_alive(const rpc_keep_alive& other16) {
  path = other16.path;
  bytes_added = other16.bytes_added;
  __isset = other16.__isset;
}
rpc_keep_alive& rpc_keep_alive::operator=(const rpc_keep_alive& other17) {
  path = other17.path;
  bytes_added = other17.bytes_added;
  __isset = other17.__isset;
  return *this;
}
void rpc_keep_alive::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "rpc_keep_alive(";
  out << "path=" << to_string(path);
  out << ", " << "bytes_added=" << to_string(bytes_added);
  out << ")";
}


rpc_keep_alive_ack::~rpc_keep_alive_ack() throw() {
}


void rpc_keep_alive_ack::__set_path(const std::string& val) {
  this->path = val;
}

void rpc_keep_alive_ack::__set_tot_bytes(const int64_t val) {
  this->tot_bytes = val;
}
std::ostream& operator<<(std::ostream& out, const rpc_keep_alive_ack& obj)
{
  obj.printTo(out);
  return out;
}


void swap(rpc_keep_alive_ack &a, rpc_keep_alive_ack &b) {
  using ::std::swap;
  swap(a.path, b.path);
  swap(a.tot_bytes, b.tot_bytes);
  swap(a.__isset, b.__isset);
}

rpc_keep_alive_ack::rpc_keep_alive_ack(const rpc_keep_alive_ack& other18) {
  path = other18.path;
  tot_bytes = other18.tot_bytes;
  __isset = other18.__isset;
}
rpc_keep_alive_ack& rpc_keep_alive_ack::operator=(const rpc_keep_alive_ack& other19) {
  path = other19.path;
  tot_bytes = other19.tot_bytes;
  __isset = other19.__isset;
  return *this;
}
void rpc_keep_alive_ack::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "rpc_keep_alive_ack(";
  out << "path=" << to_string(path);
  out << ", " << "tot_bytes=" << to_string(tot_bytes);
  out << ")";
}


directory_lease_service_exception::~directory_lease_service_exception() throw() {
}


void directory_lease_service_exception::__set_msg(const std::string& val) {
  this->msg = val;
}
std::ostream& operator<<(std::ostream& out, const directory_lease_service_exception& obj)
{
  obj.printTo(out);
  return out;
}


void swap(directory_lease_service_exception &a, directory_lease_service_exception &b) {
  using ::std::swap;
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

directory_lease_service_exception::directory_lease_service_exception(const directory_lease_service_exception& other20) : TException() {
  msg = other20.msg;
  __isset = other20.__isset;
}
directory_lease_service_exception& directory_lease_service_exception::operator=(const directory_lease_service_exception& other21) {
  msg = other21.msg;
  __isset = other21.__isset;
  return *this;
}
void directory_lease_service_exception::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "directory_lease_service_exception(";
  out << "msg=" << to_string(msg);
  out << ")";
}

const char* directory_lease_service_exception::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: directory_lease_service_exception";
  }
}

}} // namespace

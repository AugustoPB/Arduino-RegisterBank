#ifndef REG_BANK_INTERFACE_H
#define REG_BANK_INTERFACE_H

#include <utils.h>

#include <fl-lib.hpp>

class RegisterInterface {
 public:
  fl_linked_list_t head_;
  unsigned long name_hash_;
  unsigned int memory_size_;
  void* reg_ptr_;

  RegisterInterface(const unsigned long& name_hash, unsigned int size, void* reg_ptr)
      : name_hash_(name_hash), memory_size_(size), reg_ptr_(reg_ptr) {}

  template <typename Type>
  Type Get() const {
    return *(Type*)reg_ptr_;
  }

  template <typename Type>
  void Set(const Type& value) {
    *(Type*)reg_ptr_ = value;
  }
};

#endif /* REG_BANK_INTERFACE_H */
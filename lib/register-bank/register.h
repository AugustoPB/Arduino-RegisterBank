#ifndef REG_BANK_H
#define REG_BANK_H

#include <fl-lib.hpp>
#include <register_interface.h>
#include <register_bank.h>


template <typename Type, unsigned long NameHash>
class Register : public RegisterInterface{
  Type reg_;
 public:
  
  Register(): RegisterInterface(NameHash, sizeof(Type), &reg_) {
    RegisterBank::Add(this);
  }

  void Set(const Type &value) {
    reg_ = value;
  }

  Type *Get() const {
    return &reg_;
  }

};

#endif/* REG_BANK_H */
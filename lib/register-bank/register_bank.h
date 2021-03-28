#ifndef REGISTER_BANK_H
#define REGISTER_BANK_H

#include <register_interface.h>

#include <fl-lib.hpp>

class RegisterBank {
  static RegisterInterface *root_;

  RegisterBank();

  static bool GoesBefore(RegisterInterface *my, RegisterInterface *other) {
    return my->name_hash_ < other->name_hash_;
  }

  static bool GoesAfter(RegisterInterface *my, RegisterInterface *other) {
    return my->name_hash_ > other->name_hash_;
  }

 public:
  static void Add(RegisterInterface *reg) {
    fl_linked_list_init(reg, head_);

    if (not root_) {
      root_ = reg;
    } else {
      fl_linked_list_insert_after(fl_linked_list_last(root_, head_), reg, head_);
    }
  }

  template <unsigned long NameHash>
  static RegisterInterface *Get() {
    RegisterInterface *reg = root_;

    while (reg) {
      if (reg->name_hash_ == NameHash) return reg;
      reg = fl_linked_list_next(reg, head_);
    }
    return nullptr;
  }
};

#endif /* REGISTER_BANK_H */
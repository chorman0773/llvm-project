//
// Created by chorm on 2020-07-01.
//

#ifndef LLVM_WC65C816REGISTERINFO_H
#define LLVM_WC65C816REGISTERINFO_H

#include "llvm/CodeGen/Register.h"
#include "llvm/CodeGen/RegisterClassInfo.h"
#include "llvm/CodeGen/MachineBasicBlock.h"

namespace llvm{
    enum class wc65c816RegisterSizeValue{
      Size16,
      Size8,
      Indeterminate,
      Forced
    };
    class wc65c816KnownFlagState{
    private:
      size_t reg;
      wc65c816RegisterSizeValue knownSize;
    public:
      wc65c816KnownFlagState(size_t reg);
      void promiseState(wc65c816RegisterSizeValue val);
      void writeState(wc65c816RegisterSizeValue val,MachineBasicBlock& block);
      size_t registerWidth()const;
    };

} // namespace llvm

#endif // LLVM_WC65C816REGISTERINFO_H

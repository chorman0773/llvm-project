//
// Created by chorm on 2020-01-29.
//

#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/TargetRegistry.h"

#include "wc65c816TargetMachine.h"


using namespace llvm;
wc65c816TargetMachine::wc65c816TargetMachine(const Module& M,const std::string& FS)
    : layout("e-p:32:32-f128:16:16-i16:16"),
    instructions(),
    frameInfo(TargetFrameInfo::StackGrowsDown,4,0){}


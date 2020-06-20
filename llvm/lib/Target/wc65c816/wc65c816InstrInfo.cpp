//
// Created by chorm on 2020-02-24.
//

#include "wc65c816InstrInfo.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "wc65c816GenInstrInfo.inc"

#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

wc65c816InstrInfo::wc65c816InstrInfo()
: TargetInstrInfo(~0u,~0u,0x6B,0x6B){}

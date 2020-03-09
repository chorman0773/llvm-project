//
// Created by chorm on 2020-02-24.
//

#include "wc65c816InstrInfo.h"

#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

wc65c816InstrInfo::wc65c816InstrInfo()
: TargetInstrInfo(~0u,~0u,0x6B,0x6B){}

void wc65c816InstrInfo::copyPhysReg(MachineBasicBlock& MBB,MachineBasicBlock::iterator iter,
                                    const DebugLoc& DL,
                                    unsigned DestReg,
                                    unsigned SrcReg,
                                    bool _unused){
    if(DestReg==0&&SrcReg==1){
        // TXA
        BuildMI(MBB,DL,)
    }
}
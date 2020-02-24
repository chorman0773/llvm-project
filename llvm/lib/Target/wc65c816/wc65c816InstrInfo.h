//
// Created by chorm on 2020-02-23.
//

#ifndef SNES_DEV_WC65C816INSTRINFO_H
#define SNES_DEV_WC65C816INSTRINFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"

namespace llvm{
    class wc65c816InstrInfo : public TargetInstrInfo{
    public:
        wc65c816InstrInfo();
        virtual int getSPAdjust(const MachineInstr& MI) const;
        virtual void copyPhysReg(MachineBasicBlock& MBB,MachineBasicBlock::iterator iter,
                const DebugLoc& DL,
                unsigned DestReg,
                unsigned SrcReg,
                bool _unused) const;
        
    };
}

#endif //SNES_DEV_WC65C816INSTRINFO_H

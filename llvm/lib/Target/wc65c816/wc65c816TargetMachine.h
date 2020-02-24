//
// Created by chorm on 2020-01-29.
//

#ifndef SNES_DEV_WC65C816TARGETMACHINE_H
#define SNES_DEV_WC65C816TARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include "wc65c816Instructions.hpp"

namespace llvm{
    class Module;

    class wc65c816TargetMachine: public LLVMTargetMachine{
        const DataLayout layout;
        wc65c816InstrInfo instructions;
        TargetFrameInfo frameInfo;
    protected:
        virtual const TargetAsmInfo* createTargetAsmInfo()const;
    public:
        wc65c816TargetMachine(const Module &M,const std::string &Fs);
        virtual const wc65c816InstrInfo* getInstrInfo() const{
            return &instructions;
        }
        virtual const TargetSubtarget* getSubtargetImpl() const{
            return nullptr;
        }
        virtual const TargetFrameInfo* getFrameInfo() const{
            return &frameInfo;
        }
        virtual const TargetRegisterInfo* getRegisterInfo() const{
            return &instructions.getRegisterInfo();
        }

        virtual const DataLayout* getDataLayout() const{
            return &layout;
        }

        virtual const TargetSubtarget* getSubtargetImpl() const{
            return nullptr;
        }

        virtual bool addInstSelector(PassManagerBase& PM, bool Fast);
        virtual bool addPreEmitPass(PassManagerBase& PM, bool Fast);
    };
}

#endif //SNES_DEV_WC65C816TARGETMACHINE_H

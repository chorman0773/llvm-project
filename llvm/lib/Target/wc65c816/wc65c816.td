include "llvm/Target/Target.td"

include "wc65c816RegisterInfo.td"
include "wc65c816InstrInfo.td"

def wc65c816InstrInfo : InstrInfo;

def wc65c816 : Target{
    let InstructionSet = wc65c816InstrInfo;
}
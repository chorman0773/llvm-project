
class wc65c816HWReg<string name> : Register<name>{
    let Namespace = "wc65c816";
}

def X : wc65c816HWReg<"X">;
def Y : wc65c816HWReg<"Y">;


def A : wc65c816HWReg<"A">;

class wc65c816HWRegs<dag registers,dag flag> : RegisterClass<"wc65c816",[u8, i8, u16, i16],16,registers>{
    dag SizeFlag = flag;
}


class wc65c816Status<string name,u8 bit> : Register<name>{
    let Namespace = "wc65c816";
    u8 Bit = bit;
}

def e : wc65c816Status<"e",8>; // Not accessible via P

def n : wc65c816Status<"m",7>;
def v : wc65c816Status<"v",6>;
def m : wc65c816Status<"m",5>;
def x : wc65c816Status<"x",4>;
def b : wc65c816Status<"b",4>; // Emulation Mode only
def d : wc65c816Status<"d",3>;
def i : wc65c816Status<"i",2>;
def z : wc65c816Status<"z",1>;
def c : wc65c816Status<"c",0>;

def wc65c816StatusFlags : RegisterClass<"wc65c816",[u1],1,(add n v m x d i z c)>;
def wc65c816EmulationStatusFlags : RegisterClass<"wc65c816",[u1],1,(add n v b d i z c)>;

def wc65c816IndexRegs : wc65c816HWRegs<(add X Y),(x)>;
def wc65c816Accumulator : wc65c816HWRegs<(add A),(m)>;


class wc65c816EmuReg<string name, list<Register> subregs = []> : Register<name>{
    let Namespace = "wc65c816";
    let SubRegs = subregs;
}

def __al : wc65c816EmuReg<"__al",

def __eax : wc65c816EmuReg<"__eax">;
def __ebx : wc65c816EmuReg<"__ebx">;
def __ecx : wc65c816EmuReg<"__ecx">;
def __edx : wc65c816EmuReg<"__edx">;
def __esi : wc65c816EmuReg<"__esi">;
def __edi : wc65c816EmuReg<"__edi">;

def __fbase : wc65c816EmuReg<"__fbase">;

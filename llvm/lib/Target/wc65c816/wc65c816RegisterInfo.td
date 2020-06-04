
class wc65c816HWReg<string name> : Register<name>{
    let Namespace = "wc65c816";
}

def X : wc65c816HWReg<"X">;
def Y : wc65c816HWReg<"Y">;


def A : wc65c816HWReg<"A">;

def wc65c816HWRegs : RegisterClass<"wc65c816",[u16],16,(add X Y A)>;

class wc65c816EmuReg<string name> : Register<name>{
    let Namespace = "wc65c816";
}

def __eax : wc65c816EmuReg<"__eax">;
def __ebx : wc65c816EmuReg<"__ebx">;
def __ecx : wc65c816EmuReg<"__ecx">;
def __edx : wc65c816EmuReg<"__edx">;
def __esi : wc65c816EmuReg<"__esi">;
def __edi : wc65c816EmuReg<"__edi">;

def __fbase : wc65c816EmuReg<"__fbase">;

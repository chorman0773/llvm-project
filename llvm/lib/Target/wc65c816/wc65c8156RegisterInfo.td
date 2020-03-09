
class wc65c816HWReg<string name> : Register<name>{
    let Namespace = "wc65c816";
}

def X : wc65c816HWReg<"X">;
def Y : wc65c816HWReg<"Y">;

def A : wc65c816HWReg<"A">;

class wc65c816EmuReg<string name> : Register<name>{
    let Namespace = "wc65c816";
}


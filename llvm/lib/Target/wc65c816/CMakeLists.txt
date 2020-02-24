set(LLVM_TARGET_DEFINITIONS wc65c816.td)

#[[tablegen(LLVM MipsGenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM MipsGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MipsGenCallingConv.inc -gen-callingconv)
tablegen(LLVM MipsGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MipsGenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM MipsGenFastISel.inc -gen-fast-isel)
tablegen(LLVM MipsGenGlobalISel.inc -gen-global-isel)
tablegen(LLVM MipsGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MipsGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM MipsGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM MipsGenRegisterBank.inc -gen-register-bank)
tablegen(LLVM MipsGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MipsGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MipsGenExegesis.inc -gen-exegesis)]]

#[[add_public_tablegen_target(MipsCommonTableGen)]]

add_llvm_target(wc65c816)

add_subdirectory(AsmParser)
add_subdirectory(Disassembler)
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

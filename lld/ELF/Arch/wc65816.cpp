

#include "Symbols.h"
#include "SyntheticSections.h"
#include "Target.h"
#include "Thunks.h"
#include "lld/Common/ErrorHandler.h"
#include "llvm/Object/ELF.h"
#include "llvm/Support/Endian.h"

using namespace llvm;
using namespace llvm::support::endian;
using namespace llvm::ELF;


namespace lld{
    namespace elf{
        namespace{
            static const std::vector<std::vector<uint8_t>>
                nop_instrs = {
                    {0xEA},
                    {0x42, 0xFF} // When opcode-42 debug extensions exist, debug trap 0xFF is defined to be a NOP.
            };
            struct wc65816 final: public TargetInfo{
                RelExpr getRelExpr(RelType type, const Symbol &s,const uint8_t *loc) const;
                wc65816();
                bool inBranchRange(RelType type, uint64_t src, uint64_t dst) const;
                void relocate(uint8_t *loc, const Relocation &rel,
                                      uint64_t val) const;
            };
        } // namespace
        wc65816::wc65816(){
            this->noneRel = R_WC65816_NONE;
            this->trapInstr = {};
            this->nopInstrs = nop_instrs;
        }

        bool wc65816::inBranchRange(RelType type, uint64_t src, uint64_t dst) const {
            switch(type){
                case R_WC65816_LONG:
                case R_WC65816_NONE:
                    return true;
                case R_WC65816_SHORT:
                case R_WC65816_REL16:
                    return (src&0xff0000)==(dst&0xff0000);
                case R_WC65816_REL8:
                    return (src&0xffff00)==(dst&0xffff00);
                case R_WC65816_BANK:
                    return false;
            }
            llvm_unreachable("Unknown or invalid 65816 Relocation type");
        }

        void wc65816::relocate(uint8_t *loc, const Relocation &rel, uint64_t val) const {
            switch(rel.type){
                case R_WC65816_NONE:
                    break;
                case R_WC65816_LONG:
                    write16(loc,val&0xffff);
                    loc+=2;
                    [[clang::fallthrough]];
                case R_WC65816_BANK:
                    *loc = (val&0xff0000)>>16;
                    break;
                case R_WC65816_REL16:
                case R_WC65816_SHORT:
                    write16(loc,val&0xffff);
                    break;
                case R_WC65816_REL8:
                    *loc = val&0xff;
                    break;
                default:
                    llvm_unreachable("Unknown or invalid 65816 Relocation type");
            }
        }

        RelExpr wc65816::getRelExpr(RelType type, const Symbol &s,const uint8_t *loc) const {
            switch(type){
                case R_WC65816_NONE:
                    return RelExpr::R_NONE;
                case R_WC65816_SHORT:
                case R_WC65816_LONG:
                case R_WC65816_BANK:
                    return RelExpr::R_ABS;
            }
        }

        TargetInfo *getwc65c816TargetInfo(){
            static wc65816 tinfo{};
            return &tinfo;
        }
    } // namespace elf
}; // namespace lld



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

static uint32_t wc65816_page_base(uint64_t addr){

}

namespace lld{
    namespace elf{
        namespace{
            struct wc65816 final: public TargetInfo{
                RelExpr getRelExpr(RelType type, const Symbol &s,const uint8_t *loc) const;
                void relocateOne(uint8_t *loc, RelType type, uint64_t val) const;
                wc65816();
                bool inBranchRange(RelType type, uint64_t src, uint64_t dst) const;
            };
        }
        wc65816::wc65816()
    }
};

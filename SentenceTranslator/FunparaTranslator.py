from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class FunparaTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        par_encode: str = SymbolManager_.encode_var(TACLine_.src1.value)
        para_mem: int = SymbolManager_.para()
        dst_reg: REG = SymbolManager_.get_reg(par_encode, "")
        if dst_reg == REG.Cnts:
            replaced_reg: RelacedEeg = SymbolManager_.get_replaced_reg()
            dst_reg = replaced_reg.reg
            SymbolManager_.push_reg(dst_reg)
            asmlines.append(construct_asm(op="push", src=dst_reg))
        asmlines.append(construct_asm("mov", dst_reg, para_mem))
        SymbolManager_.set_avalue_reg(par_encode, dst_reg)
        if SymbolManager_.avalue_mem(par_encode) != -1:
            dst_mem: int = SymbolManager_.avalue_mem(par_encode)
            asmlines.append(construct_asm(op="mov", dst=dst_mem, src=dst_reg))
        return asmlines

from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE
import logging


class FunretTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        ret_src: str = TACLine_.src1.value
        ret_mem: int = SymbolManager_.ret()
        if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
            asmlines.append(construct_asm(op="mov", dst=ret_mem, src=ret_src))
        elif TACLine_.src1.OperType == TACOPERANDTYPE.VAR:
            ret_src_encode: str = SymbolManager_.encode_var(ret_src)
            pos: POSTYPE = SymbolManager_.position(ret_src_encode)
            if pos == POSTYPE.REG:
                ret_src_reg: REG = SymbolManager_.avalue_reg(ret_src_encode)
                asmlines.append(construct_asm(op="mov", dst=ret_mem, src=ret_src_reg))
            elif pos == POSTYPE.MEM:
                ret_src_mem: int = SymbolManager_.avalue_mem(ret_src_encode)
                asmlines.append(construct_asm(op="mov", dst=REG.EDI, src=ret_src_mem))
                asmlines.append(construct_asm(op="mov", dst=ret_mem, src=REG.EDI))
            elif pos == POSTYPE.GLOBAL:
                asmlines.append(construct_asm(op="mov", dst=ret_mem, src=ret_src))
            else:
                logging.error(f"funret default error")

        return asmlines

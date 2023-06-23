import logging
from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE, TACOP
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class ParaTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []

        if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
            src: str = TACLine_.src1.value
            SymbolManager_.set_esp_bias(4)
            asmlines.append(construct_asm(op="push", src=src))
        elif TACLine_.src1.OperType == TACOPERANDTYPE.VAR:
            str_src1: str = SymbolManager_.encode_var(TACLine_.src1.value)
            pos: POSTYPE = SymbolManager_.position(str_src1)
            if pos == POSTYPE.REG:
                reg_src1:REG = SymbolManager_.avalue_reg(str_src1)
                SymbolManager_.push_reg(reg_src1, 0)
                asmlines.append(construct_asm(op="push",src= reg_src1))
            elif pos == POSTYPE.MEM:
                mem_src1 :int= SymbolManager_.avalue_mem(str_src1)
                asmlines.append(construct_asm(op="mov",dst= REG.EDI,src= mem_src1))
                SymbolManager_.push_reg(REG.EDI, 0)
                asmlines.append(construct_asm(op="push",src= REG.EDI))
            elif pos == POSTYPE.GLOBAL:
                src :str= TACLine_.src1.value
                asmlines.append(construct_asm(op="mov",dst= REG.EDI,src= src))
                SymbolManager_.push_reg(REG.EDI, 0)
                asmlines.append(construct_asm(op="push",src= REG.EDI))
            else:
                print("para default error")

        return asmlines

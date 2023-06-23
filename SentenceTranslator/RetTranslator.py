import logging
from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE, TACOP
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class RetTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        str_src1: str = SymbolManager_.encode_var(TACLine_.src1.value)
        SymbolManager_.set_esp_bias(4)
        SymbolManager_.set_avalue_mem(str_src1, SymbolManager_.get_esp() - 4)
        asmlines.append(construct_asm(op="sub", dst=REG.ESP, src="4"))
        return asmlines

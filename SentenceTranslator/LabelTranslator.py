import logging
from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class LabelTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        label_str: str = TACLine_.src1.value
        asmlines.append(construct_asm(op=label_str + ":"))
        return asmlines

import logging

from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class CallTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        fun_name: str = TACLine_.src1.value
        asmlines.append(construct_asm(op="call", src=fun_name))
        fun = SymbolManager_.resolve_fun(fun_name)
        # print("cnm")
        # print(fun.fun_para_type_list)
        if fun != None:
            para_num: int =0 if fun.fun_para_type_list==None else len(fun.fun_para_type_list)
            SymbolManager_.set_esp_bias(-4 * para_num)
            asmlines.append(construct_asm(op="add", dst=REG.ESP, src=str(4 * para_num)))
        else:
            logging.error(f"call func error: " + fun_name)
        return asmlines

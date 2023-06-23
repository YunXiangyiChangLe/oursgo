from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class CreatelistTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        array_str_encode: str = SymbolManager_.encode_var(TACLine_.src1.value)
        #这里的int转化不知道会不会出错。。。
        array_space: int = 4 * int(TACLine_.src2.value)
        SymbolManager_.set_esp_bias(4)
        asmlines.append(construct_asm(op="sub", dst=REG.ESP, src=str(4)))
        array_ptr_mem = SymbolManager_.get_esp() - 4
        SymbolManager_.set_avalue_mem(array_str_encode, array_ptr_mem)
        SymbolManager_.set_esp_bias(array_space)
        asmlines.append(construct_asm(op="sub", dst=REG.ESP, src=str(array_space)))
        asmlines.append(construct_asm(op="mov", dst=array_ptr_mem, src=REG.ESP))

        return asmlines

import logging
from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE, TACOP
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class IfTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        str_op: str = ""
        if TACLine_.op == TACOP.IFEQ:
            str_op = "je"
        elif TACLine_.op == TACOP.IFGE:
            str_op = "jge"
        elif TACLine_.op == TACOP.IFGT:
            str_op = "jg"
        elif TACLine_.op == TACOP.IFLE:
            str_op = "jle"
        elif TACLine_.op == TACOP.IFLT:
            str_op = "jl"
        elif TACLine_.op == TACOP.IFNEQ:
            str_op = "jne"

        str_label: str = TACLine_.dst.value
        str_src1: str = TACLine_.src1.value
        str_src2: str = TACLine_.src2.value
        reg_src1: REG = REG.Cnts
        if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
            reg_src1 = REG.EDI
            asmlines.append(construct_asm(op="mov", dst=reg_src1, src=str_src1))
        else:
            str_src1_encode: str = SymbolManager_.encode_var(str_src1)
            pos: POSTYPE = SymbolManager_.position(str_src1_encode)
            if pos == POSTYPE.REG:
                reg_src1 = SymbolManager_.avalue_reg(str_src1_encode)
            elif pos == POSTYPE.MEM:
                mem_src1: int = SymbolManager_.avalue_mem(str_src1_encode)
                reg_src1 = REG.EDI
                asmlines.append(construct_asm(op="mov", dst=reg_src1, src=mem_src1))
            elif pos == POSTYPE.GLOBAL:
                reg_src1 = REG.EDI
                asmlines.append(construct_asm(op="mov", dst=reg_src1, src=str_src1))
            else:
                logging.error("if src1 default error")

        if TACLine_.src2.OperType == TACOPERANDTYPE.IMM:
            asmlines.append(construct_asm(op="cmp", dst=reg_src1, src=str_src2))
        elif TACLine_.src2.OperType == TACOPERANDTYPE.VAR:
            str_src2_encode: str = SymbolManager_.encode_var(str_src2)
            pos: POSTYPE = SymbolManager_.position(str_src2_encode)
            if pos == POSTYPE.REG:
                reg_src2: REG = SymbolManager_.avalue_reg(str_src2_encode)
                asmlines.append(construct_asm(op="cmp", dst=reg_src1, src=reg_src2))
            elif pos == POSTYPE.MEM:
                mem_src2 :int= SymbolManager_.avalue_mem(str_src2_encode)
                asmlines.append(construct_asm(op="cmp",dst= reg_src1,src= mem_src2))
            elif pos == POSTYPE.GLOBAL:
                asmlines.append(construct_asm(op="cmp",dst= reg_src1,src= str_src2))
            else:
                print("if src2 default error")
        asmlines.append(construct_asm(op=str_op,src= str_label))
        return asmlines

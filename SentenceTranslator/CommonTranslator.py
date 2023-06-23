from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class CommonTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        str_dst_encode: str = SymbolManager_.encode_var(TACLine_.dst.value)
        str_src1: str = TACLine_.src1.value
        str_src2: str = TACLine_.src2.value
        op_string: str = commonop2string(TACLine_.op)
        reg_dst: REG = REG.Cnts
        if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
            reg_dst = SymbolManager_.get_reg(str_dst_encode, "")
            if reg_dst == REG.Cnts:
                replaced_reg: RelacedEeg = SymbolManager_.get_replaced_reg()
                reg_dst = replaced_reg.reg
                SymbolManager_.push_reg(reg_dst)
                asmlines.append(construct_asm(op="push", src=reg_dst))
            asmlines.append(construct_asm(op="mov", dst=reg_dst, src=str_src1))
        else:
            str_src1_encode = SymbolManager_.encode_var(str_src1)
            reg_dst = SymbolManager_.get_reg(str_dst_encode, str_src1_encode)
            if reg_dst == REG.Cnts:
                replaced_reg: RelacedEeg = SymbolManager_.get_replaced_reg()
                reg_dst = replaced_reg.reg
                SymbolManager_.push_reg(reg_dst,1)
                asmlines.append(construct_asm(op="push", src=reg_dst))
            pos: POSTYPE = SymbolManager_.position(str_src1_encode)
            if pos == POSTYPE.REG:
                reg_src1 = SymbolManager_.avalue_reg(str_src1_encode)
                if reg_dst != reg_src1:
                    asmlines.append(construct_asm(op="mov", dst=reg_dst, src=reg_src1))
                else:
                    SymbolManager_.push_reg(reg_src1)
                    asmlines.append(construct_asm(op="push", src=reg_src1))
            elif pos == POSTYPE.MEM:
                mem_src1: int = SymbolManager_.avalue_mem(str_src1_encode)
                asmlines.append(construct_asm(op="mov", dst=reg_dst, src=mem_src1))
            elif pos == POSTYPE.GLOBAL:
                asmlines.append(construct_asm(op="mov", dst=reg_dst, src=str_src1))
            else:
                print("common default error")

        if TACLine_.src2.OperType == TACOPERANDTYPE.IMM:
            asmlines.append(construct_asm(op=op_string, dst=reg_dst, src=str_src2))
        elif TACLine_.src2.OperType == TACOPERANDTYPE.VAR:
            str_src2_encode = SymbolManager_.encode_var(str_src2)
            pos: POSTYPE = SymbolManager_.position(str_src2_encode)
            if pos == POSTYPE.REG:
                reg_src2: REG = SymbolManager_.avalue_reg(str_src2_encode)
                asmlines.append(construct_asm(op=op_string, dst=reg_dst, src=reg_src2))
            elif pos == POSTYPE.MEM:
                mem_src2 = SymbolManager_.avalue_mem(str_src2_encode)
                asmlines.append(construct_asm(op=op_string, dst=reg_dst, src=mem_src2))
            elif pos == POSTYPE.GLOBAL:
                asmlines.append(construct_asm(op=op_string, dst=reg_dst, src=str_src2))
            else:
                print("common default error")

        if reg_dst != REG.EDI:
            SymbolManager_.set_avalue_reg(str_dst_encode, reg_dst)
        if SymbolManager_.avalue_mem(str_dst_encode) != -1:
            dst_mem: int = SymbolManager_.avalue_mem(str_dst_encode)
            asmlines.append(construct_asm(op="mov", dst=dst_mem, src=reg_dst))
        return asmlines





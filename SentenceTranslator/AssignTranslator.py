import logging
from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class AssignTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        str_dst_encode: str = SymbolManager_.encode_var(TACLine_.dst.value)
        pos_dst: POSTYPE = SymbolManager_.position(str_dst_encode)

        replaced_reg: RelacedEeg = None
        dst_reg: REG = SymbolManager_.get_reg(str_dst_encode, "")
        if dst_reg == REG.Cnts:
            replaced_reg = SymbolManager_.get_replaced_reg()
            dst_reg = replaced_reg.reg

        # 如果需要进行备份原来寄存器
        # print("cnm")
        # print(replaced_reg==None)
        if replaced_reg and not replaced_reg.no_use:
            if replaced_reg.mem == -1:
                # 如果该变量内存中没有位置，push备份
                SymbolManager_.push_reg(dst_reg,1)
                asmlines.append(construct_asm(op="push", src=dst_reg))
            else:
                # 如果该变量内存中有位置，直接更新该变量在内存中的值
                asmlines.append(construct_asm(op="mov", dst=replaced_reg.mem, src=replaced_reg.reg))

        if TACLine_.dst.OperType == TACOPERANDTYPE.VAR:
            str_src1: str = TACLine_.src1.value
            if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
                # 如果 src1 是 立即数
                asmlines.append(construct_asm(op="mov", dst=dst_reg, src=str_src1))
            elif TACLine_.src1.OperType == TACOPERANDTYPE.VAR:
                # 如果 src1 是 变量，可能会是 寄存器、栈、全局变量
                encode_str_src1: str = SymbolManager_.encode_var(str_src1)
                pos: POSTYPE = SymbolManager_.position(encode_str_src1)
                if pos == POSTYPE.REG:
                    src_reg: REG = SymbolManager_.avalue_reg(encode_str_src1)
                    asmlines.append(construct_asm(op="mov", dst=dst_reg, src=src_reg))
                elif pos == POSTYPE.MEM:
                    src_mem: int = SymbolManager_.avalue_mem(encode_str_src1)
                    asmlines.append(construct_asm(op="mov", dst=dst_reg, src=src_mem))
                elif pos == POSTYPE.GLOBAL:
                    asmlines.append(construct_asm(op="mov", dst=dst_reg, src=str_src1))
                else:
                    logging.error(f"assign sentence: str1's pos wrong")
                    # LOG(ERROR) << "assign sentence: str1's pos wrong"
            elif TACLine_.src1.OperType == TACOPERANDTYPE.PTR:
                # 由于 TAC 对 operator[] 的处理，暂时可以认为这时指针一定在寄存器中
                encode_str_src1: str = SymbolManager_.encode_var(str_src1)
                src_reg: REG = SymbolManager_.avalue_reg(encode_str_src1)
                asmlines.append(construct_asm(op="mov", dst=str(dst_reg), src=construct_asm_mem(src_reg, 0)))
        elif TACLine_.dst.OperType == TACOPERANDTYPE.PTR:
            str_src1: str = TACLine_.src1.value
            if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
                # 如果 src1 是 立即数
                asmlines.append(construct_asm(op="mov", dst=dst_reg, dst_offset=0, src=str_src1))
            elif TACLine_.src1.OperType == TACOPERANDTYPE.VAR:
                # 如果 src1 是 变量，可能会是 寄存器、栈、全局变量
                encode_str_src1: str = SymbolManager_.encode_var(str_src1)
                pos: POSTYPE = SymbolManager_.position(encode_str_src1)
                if pos == POSTYPE.REG:
                    src_reg = SymbolManager_.avalue_reg(encode_str_src1)
                    asmlines.append(construct_asm(op="mov", dst=dst_reg, dst_offset=0, src=src_reg))
                elif pos == POSTYPE.MEM:
                    src_mem = SymbolManager_.avalue_mem(encode_str_src1)
                    asmlines.append(construct_asm(op="mov", dst=dst_reg, dst_offset=0, src=src_mem))
                elif pos == POSTYPE.GLOBAL:
                    asmlines.append(construct_asm(op="mov", dst=dst_reg, dst_offset=0, src=str_src1))
                else:
                    logging.error(f"assign sentence: str1's pos wrong")
                    # LOG(ERROR) << "assign sentence: str1's pos wrong"
            elif TACLine_.src1.OperType == TACOPERANDTYPE.PTR:
                # 由于 TAC 对 operator[] 的处理，暂时可以认为这时指针一定在寄存器中
                encode_str_src1 = SymbolManager_.encode_var(str_src1)
                src_reg = SymbolManager_.avalue_reg(encode_str_src1)
                asmlines.append(
                    construct_asm(op="mov", dst=construct_asm_mem(dst_reg, 0, "dword"),
                                  src=construct_asm_mem(src_reg, 0)))
        else:
            logging.error(f"assign sentence: dst' TACOPERANDTYPE wrong")
            # LOG(ERROR) << "assign sentence: dst' TACOPERANDTYPE wrong"

        dst_mem: int = SymbolManager_.avalue_mem(str_dst_encode)
        if dst_mem != -1:
            asmlines.append(construct_asm(op="mov", dst=dst_mem, src=dst_reg))

        # 更新 SymbolManager 中变量信息
        SymbolManager_.set_avalue_reg(str_dst_encode, dst_reg)
        return asmlines

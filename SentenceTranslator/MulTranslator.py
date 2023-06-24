import logging
from Include.ASMh import ASMLines
from Include.Common import commonop2string
from Include.ConstructASMh import construct_asm, construct_asm_mem
from Include.REGh import REG
from Include.TACh import TACLine, TACOPERANDTYPE, TACOP, to_string
from SymbolManager import SymbolManager, RelacedEeg, POSTYPE


class MulTranslator:
    def SentenceTranslate_(self, SymbolManager_: SymbolManager, TACLine_: TACLine) -> ASMLines:
        asmlines: ASMLines = []
        str_dst: str = TACLine_.dst.value
        str_src1: str = TACLine_.src1.value
        str_src2: str = TACLine_.src2.value

        eax_val_pre: str = SymbolManager_.rvalue(REG.EAX)
        eax_val_pre_mem: int
        if not SymbolManager_.use_info(eax_val_pre, True).no_use():
            eax_val_pre_mem = SymbolManager_.avalue_mem(eax_val_pre)
            if eax_val_pre_mem == -1:
                # 内存中没有位置, push 保存
                SymbolManager_.push_reg(REG.EAX,1)
                asmlines.append(construct_asm(op="push", src=REG.EAX))
            else:
                # 内存中有位置, 更新内存中的值
                asmlines.append(construct_asm(op="mov", dst=eax_val_pre_mem, src=REG.EAX))

        # EAX = src1 类似 assign
        if TACLine_.src1.OperType == TACOPERANDTYPE.IMM:
            # 如果 src1 是 立即数
            asmlines.append(construct_asm(op="mov", dst=REG.EAX, src=str_src1))
        elif TACLine_.src1.OperType == TACOPERANDTYPE.VAR:
            # 如果 src1 是 变量，可能会是 寄存器、栈、全局变量
            encode_str_src1: str = SymbolManager_.encode_var(str_src1)
            pos: POSTYPE = SymbolManager_.position(encode_str_src1)
            if pos == POSTYPE.REG:
                src_reg: REG = SymbolManager_.avalue_reg(encode_str_src1)
                asmlines.append(construct_asm(op="mov", dst=REG.EAX, src=src_reg))
            elif pos == POSTYPE.MEM:
                src_mem: int = SymbolManager_.avalue_mem(encode_str_src1)
                asmlines.append(construct_asm(op="mov", dst=REG.EAX, src=src_mem))
            elif pos == POSTYPE.GLOBAL:
                asmlines.append(construct_asm(op="mov", dst=REG.EAX, src=str_src1))
            else:
                logging.error("mul sentence: str1's pos wrong")
        SymbolManager_.set_avalue_reg(SymbolManager_.encode_var(str_src1), REG.EAX)

        # 找一个寄存器给 src2，给这个寄存器做备份
        reg_src2: REG = REG.EBX
        reg_src2_pre: str = SymbolManager_.rvalue(reg_src2)
        mem_src2_pre: int
        if not SymbolManager_.use_info(reg_src2_pre, True).no_use():
            mem_src2_pre = SymbolManager_.avalue_mem(reg_src2_pre)
            if mem_src2_pre == -1:
                # 内存中没有位置, push 保存
                SymbolManager_.push_reg(reg_src2)
                asmlines.append(construct_asm(op="push", src=reg_src2))
            else:
                # 内存中有位置, 更新内存中的值
                asmlines.append(construct_asm(op="mov", dst=mem_src2_pre, src=reg_src2))

        # EBX = src2 类似 assign
        if TACLine_.src2.OperType == TACOPERANDTYPE.IMM:
            # 如果 src2 是 立即数
            asmlines.append(construct_asm(op="mov", dst=reg_src2, src=str_src2))
        elif TACLine_.src2.OperType == TACOPERANDTYPE.VAR:
            # 如果 src2 是 变量，可能会是 寄存器、栈、全局变量
            encode_str_src2: str = SymbolManager_.encode_var(str_src2)
            pos: POSTYPE = SymbolManager_.position(encode_str_src2)
            if pos == POSTYPE.REG:
                src_reg: REG = SymbolManager_.avalue_reg(encode_str_src2)
                asmlines.append(construct_asm(op="mov", dst=reg_src2, src=src_reg))
            elif pos == POSTYPE.MEM:
                src_mem: int = SymbolManager_.avalue_mem(encode_str_src2)
                asmlines.append(construct_asm(op="mov", dst=reg_src2, src=src_mem))
            elif pos == POSTYPE.GLOBAL:
                asmlines.append(construct_asm(op="mov", dst=reg_src2, src=str_src2))
            else:
                logging.error("mul sentence: str2's pos wrong")
        SymbolManager_.set_avalue_reg(SymbolManager_.encode_var(str_src2), reg_src2)

        # 在进行 EAX = EAX * src2 之前, 由于 在 EAX 中的 src1 将被覆盖，所以需要再次对 EAX 做一次备份
        eax_src1: str = SymbolManager_.rvalue(REG.EAX)
        eax_src1_mem: int = None
        if not SymbolManager_.use_info(eax_src1, True).no_use():
            eax_src1_mem = SymbolManager_.avalue_mem(eax_src1)
            if eax_src1_mem == -1:
                # 内存中没有位置, push 保存
                SymbolManager_.push_reg(REG.EAX)
                asmlines.append(construct_asm(op="push", src=REG.EAX))
            else:
                # 内存中有位置, 更新内存中的值
                asmlines.append(construct_asm(op="mov", dst=eax_src1_mem, src=REG.EAX))

        # 如果是 div，因为会将 余数存在 EDX，所以需要备份
        edx_symbol: str = SymbolManager_.rvalue(REG.EDX)
        edx_mem: int = None
        if not SymbolManager_.use_info(edx_symbol, True).no_use():
            edx_mem = SymbolManager_.avalue_mem(edx_symbol)
            if edx_mem == -1:
                # 内存中没有位置, push 保存
                SymbolManager_.push_reg(REG.EDX)
                asmlines.append(construct_asm(op="push", src=REG.EDX))
            else:
                # 内存中有位置, 更新内存中的值
                asmlines.append(construct_asm(op="mov", dst=edx_mem, src=REG.EDX))

        # MUL
        op: str = to_string(op=TACLine_.op)
        asmlines.append(construct_asm(op=op,src= reg_src2))
        SymbolManager_.set_avalue_reg(SymbolManager_.encode_var(str_dst), REG.EAX)

        return asmlines

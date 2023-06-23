from Include.ConstructASMh import construct_asm
from SentenceTranslator.AssignTranslator import AssignTranslator
from SentenceTranslator.CallTranslator import CallTranslator
from SentenceTranslator.CommonTranslator import CommonTranslator
from SentenceTranslator.CreatelistTranslator import CreatelistTranslator
from SentenceTranslator.FunparaTranslator import FunparaTranslator
from SentenceTranslator.FunretTranslator import FunretTranslator
from SentenceTranslator.GotoTranslator import GotoTranslator
from SentenceTranslator.IfTranslator import IfTranslator
from SentenceTranslator.LabelTranslator import LabelTranslator
from SentenceTranslator.MulTranslator import MulTranslator
from SentenceTranslator.ParaTranslator import ParaTranslator
from SentenceTranslator.RetTranslator import RetTranslator
from SymbolManager import *
import logging


def BlockTranslate(SymbolManager_: SymbolManager, TACBlock_: TACBlock) -> ASMBlock:
    ASMBlock_: ASMBlock=ASMBlock()
    SymbolManager_.push_reg(REG.EBP, 0)
    ASMBlock_.asmlines.append(construct_asm(op="push", src=REG.EBP))
    ASMBlock_.asmlines.append(construct_asm(op="push", dst=REG.EBP, src=REG.ESP))
    if SymbolManager_.get_name() == "main":
        ASMBlock_.name = "_start"
    else:
        ASMBlock_.name = SymbolManager_.get_name()
        SymbolManager_.push_reg(REG.EAX, 0)
        SymbolManager_.push_reg(REG.EBX, 0)
        SymbolManager_.push_reg(REG.ECX, 0)
        SymbolManager_.push_reg(REG.EDX, 0)
        SymbolManager_.push_reg(REG.ESI, 0)
        ASMBlock_.asmlines.append(construct_asm(op="push", src=REG.EAX))
        ASMBlock_.asmlines.append(construct_asm(op="push", src=REG.EBX))
        ASMBlock_.asmlines.append(construct_asm(op="push", src=REG.ECX))
        ASMBlock_.asmlines.append(construct_asm(op="push", src=REG.EDX))
        ASMBlock_.asmlines.append(construct_asm(op="push", src=REG.ESI))

    SymbolManager_.cal_use_info(TACBlock_)
    SymbolManager_.set_zero_len()
    for i in range(len(TACBlock_)):
        logging.info(
            f"{TACBlock_[i].to_string():<20} {TACBlock_[i].src1.use_info}\t{TACBlock_[i].src2.use_info}\t{TACBlock_[i].dst.use_info}\tscope {TACBlock_[i].scope}")
        SymbolManager_.set_scope(TACBlock_[i].scope)
        if TACBlock_[i].src1.OperType == TACOPERANDTYPE.VAR:
            SymbolManager_.set_use_info(TACBlock_[i].src1.value, TACBlock_[i].src1.use_info)
        if TACBlock_[i].src2.OperType == TACOPERANDTYPE.VAR:
            SymbolManager_.set_use_info(TACBlock_[i].src2.value, TACBlock_[i].src2.use_info)
        if TACBlock_[i].dst.OperType == TACOPERANDTYPE.VAR:
            SymbolManager_.set_use_info(TACBlock_[i].dst.value, TACBlock_[i].dst.use_info)

        trans = None
        if TACBlock_[i].op == TACOP.ASSIGN:
            trans: AssignTranslator = AssignTranslator()
        elif TACBlock_[i].op == TACOP.CALL:
            trans: CallTranslator = CallTranslator()
        elif TACBlock_[i].op == TACOP.FUN_PARA:
            trans: FunparaTranslator = FunparaTranslator()
        elif TACBlock_[i].op == TACOP.FUN_RET:
            trans: FunretTranslator = FunretTranslator()
        elif TACBlock_[i].op == TACOP.PARA:
            trans: ParaTranslator = ParaTranslator()
        elif TACBlock_[i].op == TACOP.RET:
            trans: RetTranslator = RetTranslator()
        elif TACBlock_[i].op == TACOP.GOTO:
            trans: GotoTranslator = GotoTranslator()
        elif TACBlock_[i].op == TACOP.LABEL:
            trans: LabelTranslator = LabelTranslator()
        elif TACBlock_[i].op == TACOP.CREATLIST:
            trans: CreatelistTranslator = CreatelistTranslator()
        elif TACBlock_[i].op == TACOP.IFEQ:
            trans: IfTranslator = IfTranslator()
        elif TACBlock_[i].op == TACOP.IFGE:
            trans: IfTranslator = IfTranslator()
        elif TACBlock_[i].op == TACOP.IFGT:
            trans: IfTranslator = IfTranslator()
        elif TACBlock_[i].op == TACOP.IFLE:
            trans: IfTranslator = IfTranslator()
        elif TACBlock_[i].op == TACOP.IFLT:
            trans: IfTranslator = IfTranslator()
        elif TACBlock_[i].op == TACOP.IFNEQ:
            trans: IfTranslator = IfTranslator()
        elif TACBlock_[i].op == TACOP.DIV or TACBlock_[i].op == TACOP.MUL:
            trans: MulTranslator = MulTranslator()
        else:
            trans: CommonTranslator = CommonTranslator()

        tem_res: ASMLines = trans.SentenceTranslate_(SymbolManager_, TACBlock_[i])
        ASMBlock_.asmlines.extend(tem_res)

    stack_len: int = SymbolManager_.get_stack_len()
    if stack_len > 0:
        SymbolManager_.set_esp_bias(-4 * stack_len)
    elif stack_len < 0:
        logging.error(f"{stack_len} stack overflow")

    if SymbolManager_.get_name() == "main":
        SymbolManager_.pop_reg(REG.EBP)
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.EBP))
        ASMBlock_.asmlines.append(construct_asm(op="mov", dst=REG.EAX, src=str(1)))
        ASMBlock_.asmlines.append(construct_asm(op="mov", dst=REG.EBX, src=str(0)))
        ASMBlock_.asmlines.append(construct_asm(op="int", src="80h"))
    else:
        SymbolManager_.pop_reg(REG.ESI)
        SymbolManager_.pop_reg(REG.EDX)
        SymbolManager_.pop_reg(REG.ECX)
        SymbolManager_.pop_reg(REG.EBX)
        SymbolManager_.pop_reg(REG.EAX)
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.ESI))
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.EDX))
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.ECX))
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.EBX))
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.EAX))
        SymbolManager_.pop_reg(REG.EBP)
        ASMBlock_.asmlines.append(construct_asm(op="pop", src=REG.EBP))
        ASMBlock_.asmlines.append(construct_asm(op="ret"))

    return ASMBlock_

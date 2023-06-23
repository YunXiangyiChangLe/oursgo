from __future__ import annotations

import ctypes
from dataclasses import dataclass
from Include.TACh import *
from Include.REGh import *
from Include.Scopeh import *
from Include.TACOP import *
from Include.UseInfoh import *
from Include.ASMh import *
from dataclasses import dataclass
from typing import List

import inspect


def print_with_line_number(message):
    frame_info = inspect.stack()[1]
    line_number = frame_info.lineno
    print("Line {}: {}".format(line_number, message))


class POSTYPE(Enum):
    GLOBAL = 1
    REG = 2
    MEM = 3
    NONE = 4


@dataclass
class RelacedEeg:
    reg: REG
    val: str
    no_use: bool = True
    mem: int = -1


class SymbolManager:
    def __init__(self, global_scope: Scope, name: str):
        # 符号表
        self.name_: str = name
        self.global_scope_: Scope = global_scope
        self.local_scope_: Scope = None
        self._, self.func_ = global_scope.resolve(name=name)

        # 变量存储信息
        self.rvalue_: List[str] = [''] * (int(REG.Cnts.value) + 4)  # 地址-寄存器 -> 变量
        self.svalue_: List[str] = []  # 地址-内存 -> 变量
        self.avalue_reg_: Dict[str, REG] = {}  # 变量 -> 地址-寄存器
        self.avalue_mem_: Dict[str, int] = {}  # 变量 -> 地址-内存(存与ebp的偏移)

        # 变量名 -> 符号表中的 待用信息 和 活跃信息
        self.use_info_: Dict[str, UseInfo] = {}

        # 函数堆栈模拟
        self.len_: int = 0  # 当前栈的长度 (4 字节)
        self.stack_esp_: int = 0  # 模拟堆栈的栈顶 (与当前函数栈底的相对值)
        self.para_num_: int = 0 if self.func_.fun_para_type_list == None else len(self.func_.fun_para_type_list)
        self.para_now_: int = 0
        self.ret_num_: int = 0 if self.func_.fun_ret_type_list == None else len(self.func_.fun_ret_type_list)
        self.ret_now_: int = 0

    def set_scope(self, local_scope: Scope):
        self.local_scope_ = local_scope

    def encode_var(self, var: str) -> str:
        en_var = ''
        if var and not var[0].isdigit():
            _, symbol = self.local_scope_.resolve(var)
            en_var = f'{id(symbol.scope)}:{var}'
        return en_var

    def cal_use_info(self, block: TACBlock):
        # 初始化符号表中所有变量的待用信息
        self.use_info_.clear()
        # 根据基本块出口来设置变量的活跃信息
        for line in reversed(block):
            self.set_scope(line.scope)
            if line.op == TACOP.FUN_RET:
                _ = UseInfo(0, True)
                self.set_use_info(line.src1.value, _)
            else:
                break
        # 从后往前遍历基本块，将 变量的待用信息和活跃信息 绑定在 TACline 上
        for line in reversed(block):
            self.set_scope(line.scope)
            if line.op == TACOP.CALL:
                continue
            if line.dst.OperType == TACOPERANDTYPE.VAR:
                # 把符号表中 dst 的待用信息和活跃信息 附加到 中间代码上
                line.dst.use_info = self.use_info(line.dst.value)
                # 重置符号表 dst 的待用信息和活跃信息
                _ = UseInfo(0, False)
                self.set_use_info(line.dst.value, _)
            if line.src1.OperType == TACOPERANDTYPE.VAR:
                # 把符号表中 src1 的待用信息和活跃信息 附加到 中间代码上
                line.src1.use_info = self.use_info(line.src1.value)
                # 置位符号表 src1 的待用信息和活跃信息
                _ = UseInfo(line.line, True)
                self.set_use_info(line.src1.value, _)
            if line.src2.OperType == TACOPERANDTYPE.VAR:#gyj加的    
                # 把符号表中 src2 的待用信息和活跃信息 附加到 中间代码上
                line.src2.use_info = self.use_info(line.src2.value)
                # 置位符号表 src2 的待用信息和活跃信息
                _ = UseInfo(line.line, True)
                self.set_use_info(line.src2.value, _)

    def use_info(self, variable: str, encoded: bool = False) -> UseInfo:
        var_en = variable if encoded else self.encode_var(variable)
        _ = UseInfo(0, False)
        return self.use_info_.get(var_en, _)

    def set_use_info(self, variable: str, use_info: UseInfo):
        var_en = self.encode_var(variable)
        if var_en:
            self.use_info_[var_en] = use_info

    def get_free_reg(self) -> REG:
        for i in range(REG.Cnts.value):
            if not self.rvalue_[i]:
                return REG(i)
        return REG.Cnts

    def get_reg(self, dst: str = '', src1: str = '') -> REG:
        if dst or src1:
            if dst:
                if self.avalue_reg(dst) != REG.Cnts:
                    return self.avalue_reg(dst)
                if dst in self.avalue_mem_:
                    return REG.EDI
                if src1 and self.avalue_reg(src1) != REG.Cnts:#gyj加的
                    return self.avalue_reg(src1)
            return self.get_free_reg()
        else:

            # 找到非活跃的寄存器
            return REG.ESI

    def get_replaced_reg(self) -> RelacedEeg:
        # 寻找 不再使用的变量
        for i in range(REG.Cnts.value):
            replaced_val = self.rvalue_[i]
            if replaced_val in self.use_info_ and self.use_info_[replaced_val].no_use():
                return RelacedEeg(REG(i), replaced_val)
                # return {'reg': REG(i), 'val': replaced_val}
        # 寻找 内存中有位置的变量
        for i in range(REG.Cnts.value):
            replaced_val: str = self.rvalue_[i]
            val_mem = self.avalue_mem(replaced_val)
            if val_mem != -1:
                return RelacedEeg(REG(i), self.rvalue_[i], False, val_mem)
                # return {'reg': REG(i), 'val': self.rvalue_[i], 'is_push': False, 'mem': val_mem}
        # 返回需要 push 备份的寄存器
        max_next_use = 0
        max_next_use_reg: REG = None
        for i in range(REG.Cnts.value):
            en_var = self.rvalue(REG(i))
            next_use_i = self.use_info(en_var, True).next_use
            if max_next_use < next_use_i:
                max_next_use = next_use_i
                max_next_use_reg = REG(i)
        # return {'reg': max_next_use_reg, 'val': self.rvalue(max_next_use_reg), 'is_push': False, 'mem': -1}
        # print("cnjasfhkjjfaoi")
        # print_with_line_number(self.rvalue(max_next_use_reg))
        return RelacedEeg(max_next_use_reg, self.rvalue(max_next_use_reg), False, -1)

    def set_zero_len(self):
        self.len_ = 0

    def get_stack_len(self) -> int:
        return self.len_

    def get_name(self) -> str:
        return self.name_

    def rvalue(self, reg: REG) -> str:
        # print_with_line_number(reg)
        # print_with_line_number(reg.value)
        # print_with_line_number(self.rvalue_[reg.value]=='')
        # return "167sbmanger"
        return "167sbmanger" if reg == None else self.rvalue_[reg.value]

    def avalue_reg(self, variable: str) -> REG:
        return self.avalue_reg_.get(variable, REG.Cnts)

    def avalue_mem(self, variable: str) -> int:
        return self.avalue_mem_.get(variable, -1)

    def para(self) -> int:
        bias = -4 * (self.para_num_ - self.para_now_ + 1)
        self.para_now_ += 1
        return bias

    def ret(self) -> int:
        bias = -4 * (self.ret_num_ + self.para_num_ - self.ret_now_ + 1)
        self.ret_now_ += 1
        return bias

    def resolve_fun(self, name) -> Symbol:
        _, p = self.local_scope_.resolve(name)
        if p.isFun():
            return p
        else:
            return None

    def set_avalue_reg(self, variable: str, reg: REG):
        if(reg==None):
            return
        old = self.rvalue_[reg.value]
        if old in self.avalue_reg_ and self.avalue_reg_[old] == reg:
            del self.avalue_reg_[old]
        self.avalue_reg_[variable] = reg
        self.rvalue_[reg.value] = variable

    def set_avalue_mem(self, variable: str, mem: int):
        old = self.svalue_[mem // 4]
        if old in self.avalue_mem_ and self.avalue_mem_[old] == mem:
            del self.avalue_mem_[old]
        self.avalue_mem_[variable] = mem
        self.svalue_[mem // 4] = variable

    def show_reg(self, reg):
        if reg != REG.Cnts:
            print(f"{to_string(reg)}: {self.rvalue_[int(reg)]}")
        else:
            for reg_i in range(int(REG.Cnts)):
                en_var = self.rvalue_[int(reg_i)]
                var_next_use = self.use_info_.get(en_var, {}).next_use
                print(f"{to_string(REG(reg_i))}: {en_var} {var_next_use}")

    def show_mem(self, mem):
        print(f"len of mem: {self.len_}")
        for key, value in self.avalue_mem_.items():
            print(f"mem {value}: {key}")

    # 需要改正
    def position(self, variable: str) -> POSTYPE:
        pos = variable.find(":")
        scope_str = variable[:pos]
        true_name = variable[pos + 1:]
        scope_p_t = int(scope_str)
        scope_p: Scope = ctypes.cast(scope_p_t, ctypes.py_object).value
        if scope_p == self.global_scope_:
            return POSTYPE.GLOBAL
        elif variable in self.avalue_reg_:
            return POSTYPE.REG
        elif variable in self.avalue_mem_:
            return POSTYPE.MEM
        else:
            return POSTYPE.NONE

    def push_reg(self, reg: REG, overwrite: int):
        if overwrite == 1:
            # print_with_line_number(reg.value)
            if (reg == None):
                return
            # print(reg.value)
            var = self.rvalue_[reg.value]
            self.svalue_.append(var)
            self.avalue_mem_[var] = self.stack_esp_
        else:
            self.svalue_.append("Null")
        self.stack_esp_ += 4
        self.len_ += 1

    def pop_reg(self, reg: REG):
        var = self.svalue_.pop()
        old = self.rvalue_[reg.value]
        if old in self.avalue_reg_ and self.avalue_reg_[old] == reg:
            del self.avalue_reg_[old]
        if var != "Null":
            self.avalue_reg_[var] = reg
            self.rvalue_[int(reg)] = var
        self.stack_esp_ -= 4
        self.len_ -= 1

    def set_esp_bias(self, bias: int):
        if bias > 0:
            num = bias // 4
            for i in range(num):
                self.svalue_.append("Null")
            self.len_ += num
        else:
            num = (-bias) // 4
            for i in range(num):
                old = self.svalue_[-1]
                if old in self.avalue_mem_ and self.avalue_mem_[old] == self.stack_esp_ - (i + 1) * 4:
                    del self.avalue_mem_[old]
                self.svalue_.pop()
            self.len_ -= num
        self.stack_esp_ += bias

    def get_esp(self) -> int:
        return self.stack_esp_

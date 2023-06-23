from enum import Enum
from Include.Scopeh import Scope
from typing import List, Dict
from Include.UseInfoh import UseInfo


class TACOP(Enum):
    ADD = 0
    SUB = 1
    MUL = 2
    DIV = 3
    ASSIGN = 4
    CALL = 5
    PARA = 6
    RET = 7
    ENDCALL = 8
    FUN_RET = 9
    FUN_PARA = 10
    GOTO = 11
    IFGT = 12
    IFGE = 13
    IFLT = 14
    IFLE = 15
    IFEQ = 16
    IFNEQ = 17
    LABEL = 18
    CREATLIST = 19


def to_string(op: TACOP) -> str:
    op_dict = {
        TACOP.ADD: "add",
        TACOP.SUB: "sub",
        TACOP.MUL: "mul",
        TACOP.DIV: "div",
        TACOP.ASSIGN: "assign",
        TACOP.CALL: "call",
        TACOP.PARA: "para",
        TACOP.RET: "ret",
        TACOP.ENDCALL: "endcall",
        TACOP.FUN_RET: "funret",
        TACOP.FUN_PARA: "funpara",
        TACOP.GOTO: "goto",
        TACOP.IFGT: "ifgt",
        TACOP.IFGE: "ifge",
        TACOP.IFLT: "iflt",
        TACOP.IFLE: "ifle",
        TACOP.IFEQ: "ifeq",
        TACOP.IFNEQ: "ifneq",
        TACOP.LABEL: "label"
    }
    return op_dict.get(op, "error_op")


class TACOPERANDTYPE(Enum):
    IMM = 1
    VAR = 2
    NULL_ = 3
    PTR = 4
    LABEL = 5


class Operand:
    def __init__(self, value: str = '', type: TACOPERANDTYPE = None):
        self.value = value
        self.use_info = UseInfo()  # 在这里初始化use_info
        self.OperType = type


class TACLine:
    def __init__(self, line: int = 0, op: TACOP = None,
                 src1: Operand = None, src2: Operand = None, dst: Operand = None, scope: Scope = None):
        self.line = line
        self.op = op
        self.src1 = src1
        self.src2 = src2
        self.dst = dst
        self.scope = scope

    def to_string(self) -> str:
        return f"{self.line}:({to_string(self.op)},{self.src1.value},{self.src2.value},{self.dst.value})"


TACBlock = List[TACLine]

TACFile = Dict[str, TACBlock]

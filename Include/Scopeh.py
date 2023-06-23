from __future__ import annotations

from enum import Enum
from typing import List

from Include.TACOP import *


class SymbolType(Enum):
    VAR = 1
    FUN = 2


class Type(Enum):
    BOOL = 1
    INT8 = 2
    INT16 = 3
    INT32 = 4
    INT64 = 5
    INT = 6
    UINT8 = 7
    UINT16 = 8
    UINT32 = 9
    UINT64 = 10
    UINT = 11
    FLOAT32 = 12
    FLOAT64 = 13
    COMPLEX64 = 14
    COMPLEX128 = 15
    BYTE = 16
    RUNE = 17
    STRING = 18


class Scope:
    def __init__(self, enclosing_scope: Scope = None):
        self.enclosing_scope = enclosing_scope
        self.fun_symbols = {}
        self.para_symbols = {}

    def fun_define(self, sym: Symbol):
        self.fun_symbols[sym.name] = sym

    def para_define(self, sym: Symbol):
        self.para_symbols[sym.name] = sym

    def para_delete(self, str: str):
        del self.para_symbols[str]
        
        
    def resolve(self, name: str, ret: Symbol = None):
        #print(name)
        if name in self.fun_symbols:
            ret = self.fun_symbols[name]
            return SUCCESS,ret
        elif name in self.para_symbols:
            ret = self.para_symbols[name]
            return SUCCESS,ret
        elif self.enclosing_scope is not None:
            return self.enclosing_scope.resolve(name, ret)
        else:
            return FAIL,None

    def cur_resolve(self, name):
        if name in self.fun_symbols or name in self.para_symbols:
            return SUCCESS
        else:
            return FAIL


class Symbol:
    def __init__(self, name: str, scope: Scope, symobl_type: SymbolType, type: Type = None,
                 fun_ret_type_list: List[Type] = None, fun_para_type_list: List[Type] = None, is_array: bool = False,
                 array_length: int = 0):
        self.name = name
        self.scope = scope
        self.symobl_type = symobl_type
        self.type = type
        self.fun_ret_type_list = fun_ret_type_list
        self.fun_para_type_list = fun_para_type_list
        self.is_array = is_array
        self.array_length = array_length

    def isVar(self):
        return self.symobl_type == SymbolType.VAR

    def isFun(self):
        return self.symobl_type == SymbolType.FUN

    # 目前只有一种转化，其他的再说。。。
    @staticmethod
    def toType(s: str) -> Type:
        if s == "int":
            return Type.INT
        else:
            pass

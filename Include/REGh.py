from enum import Enum


class REG(Enum):
    EAX = 0
    EBX = 1
    ECX = 2
    EDX = 3
    ESI = 4
    Cnts = 5  # CNTS 不代表寄存器, 数值上等于可用通用 REG 个数
    EDI = 6  # 保留REG
    ESP = 7
    EBP = 8
    EIP = 9


def to_string(reg: REG) -> str:
    reg_dic={
        REG.EAX:"eax",
        REG.EBX:"ebx",
        REG.ECX:"ecx",
        REG.EDX:"esx",
        REG.ESI:"esi",
        REG.EDI:"edi",
        REG.ESP:"esp",
        REG.EBP:"ebp",
        REG.EIP:"eip"
    }
    return reg_dic.get(reg,"error_reg")

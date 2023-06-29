from enum import Enum
from dataclasses import dataclass, field
from typing import List


class ASMOP(Enum):
    MOV = 1
    PUSH = 2
    POP = 3
    CALL = 4
    JMP = 5
    RET = 6


class OprandType(Enum):
    t_NULL = 1
    t_IMM = 2
    t_REG = 3
    t_MEM = 4


ASMLines = List[str]


@dataclass
class ASMBlock:
    name: str = ""
    asmlines: ASMLines = field(default_factory=list)


@dataclass
class ASMSection:
    name: str = ""
    asmblocks: List[ASMBlock] = field(default_factory=list)


ASMFile = List[ASMSection]

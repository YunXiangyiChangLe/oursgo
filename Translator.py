import typing

from Include.TACh import *
from Include.REGh import *
from Include.Scopeh import *
from Include.TACOP import *
from Include.UseInfoh import *
from Include.ASMh import *
from dataclasses import dataclass
from typing import List
from SymbolManager import *
from BlockTranslator import BlockTranslate


# 如何输入待定

class Translator:
    def __init__(self, TACFile_: TACFile, Global_Scope_: Scope):
        self.TACFile_ = TACFile_
        self.Global_Scope = Global_Scope_
        self.ASMFile_: ASMFile = []

    def Translate(self):
        self.dataTranslate()
        self.textTranslate()

    def dataTranslate(self):
        ASMSection_ = ASMSection()
        ASMSection_.name = ""

        ASMBlock_ = ASMBlock()
        ASMBlock_.name = ""
        global_ = self.TACFile_["global"]
        # if(global_==typing.List[Include.TACh.TACLine])
        # print("cnm")
        # print(global_)
        if not isinstance(global_, typing._GenericAlias):
            for i in range(len(global_)):
                ASMLine_ = ""
                if global_[i].op == TACOP.ASSIGN:
                    ASMLine_ = global_[i].dst.value + " equ " + global_[i].src1.value
                    ASMBlock_.asmlines.append(ASMLine_)
                else:
                    print("global op error: " + str(global_[i].op))
            ASMSection_.asmblocks.append(ASMBlock_)
            self.ASMFile_.append(ASMSection_)
        else:
            pass

    def textTranslate(self):
        ASMSection_ = ASMSection()
        ASMSection_.name = ""

        ASMBlock_ = ASMBlock()
        ASMBlock_.name = ""
        ASMBlock_.asmlines.append("global _start")
        ASMBlock_.asmlines.append("extern myprint")
        ASMSection_.asmblocks.append(ASMBlock_)

        for i in self.TACFile_:
            if i == "global" or i == "myprint" or len(self.TACFile_[i]) == 0:
                continue
            print("开始翻译函数")
            SymbolManager_ = SymbolManager(self.Global_Scope, i)
            ASMBlock_ = BlockTranslate(SymbolManager_, self.TACFile_[i])
            ASMSection_.asmblocks.append(ASMBlock_)

        self.ASMFile_.append(ASMSection_)

    def OutputFile(self, filename):
        with open(filename, "w") as outfile:
            for i in range(len(self.ASMFile_)):
                if self.ASMFile_[i].name != "":
                    outfile.write(self.ASMFile_[i].name + ":\n")
                for j in range(len(self.ASMFile_[i].asmblocks)):
                    if self.ASMFile_[i].asmblocks[j].name != "":
                        outfile.write(self.ASMFile_[i].asmblocks[j].name + ":\n")
                    for k in range(len(self.ASMFile_[i].asmblocks[j].asmlines)):
                        outfile.write(self.ASMFile_[i].asmblocks[j].asmlines[k] + "\n")
                    outfile.write("\n")
                outfile.write("\n")

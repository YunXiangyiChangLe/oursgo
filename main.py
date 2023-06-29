from Common.Common import *
from typing import List
from antlr4.FileStream import FileStream
from antlr4.InputStream import InputStream
from ICG.TrcodeGen import TrCodeGen
from Include.ASMh import *
# from Include.REGh import *
from Include.Scopeh import *
from Include.TACh import *
from Include.GoLexer import *
from Include.GoParser import *
from Include.GoParserListener import *
import getopt
import Translator as ts
import os


class CmdParam:
    def __init__(self):
        self.input = []
        self.output = '.'
        self.output_3code = '3code.txt'
        self.output_asm = 'out.asm'
        self.output_bin = 'out.bin'
        self.log_path = './log'
        self.log_file_name: string


def read_cmd_param(argc: int, argv: list[str]):
    cmd_param = CmdParam()
    cmd_param.log_file_name = argv[0]
    i = 1
    while i < argc:
        argv_i = argv[i]
        if argv_i[0] == '-':
            if argv_i == '-h' or argv_i == '-help':
                print('可选参数如下：')
                print('-h (--help):      帮助')
                print('-o (--output):    [default:.]            输出文件路径')
                print("-3 (--3code):     [default: 3code.txt]    输出 3code 文件名")
                print("-a (--asm):       [default: out]          输出 asm 文件名")
                print("-b (--bin):       [default: bin]          输出 bin 文件名")
                print("-l (--log):       [default: log]          输出 log 目录")
                exit(0)
            if argv_i.__len__() == 1:
                print('选项错误')
                exit(0)
            elif i + 1 == argc:
                print('选项' + argv_i + '没有给定值')
                exit(0)
            else:
                i += 1
                if argv_i == '-o' | argv_i == '--output':
                    cmd_param.output = argv[i]
                elif argv_i == '-3' | argv_i == '--3code':
                    cmd_param.output_3code = argv[i]
                elif argv_i == '-a' | argv_i == '--asm':
                    cmd_param.output_asm = argv[i]
                elif argv_i == '-b' | argv_i == '--bin':
                    cmd_param.output_bin = argv[i]
                elif argv_i == '-l' | argv_i == '--log':
                    cmd_param.log_path = argv[i]
                else:
                    print('未知参数' + argv_i + '')
                    exit(0)
        else:
            cmd_param.input.append(argv[i])
        i += 1
    if cmd_param.input.__len__() == 0:
        print('没有输入的 .go文件')
        exit(0)
    os.system('mkdir -p' + cmd_param.output)
    return cmd_param


if __name__ == '__main__':
    f = os.popen("java -jar antlr-4.8-complete.jar -Dlanguage=Python3 GoLexer.g4 GoParser.g4 -o Include")
    print(f.read())

    cmd0 = 'cd ./grammar/java'
    cmd0 += '&& javac *.java'
    cmd0 += '&& cd ../../build'
    os.system(cmd0)

    argv = sys.argv

    cmd_param: CmdParam = read_cmd_param(argv.__len__(), argv)
    filename = cmd_param.input[0]
    print('开始翻译文件：' + filename)
    file = FileStream(fileName=filename)
    print(file.__str__() + '')
    inputStream = InputStream(file.__str__())
    print('词法分析')
    lexer = GoLexer(inputStream)
    tokens = CommonTokenStream(lexer)
    print('语法分析')
    parser = GoParser(tokens)
    listener = TrCodeGen()
    walker = ParseTreeWalker()
    walker.walk(listener, parser.sourceFile())
    path_3code = cmd_param.output + '/' + cmd_param.output_3code
    listener.Go23file_(path_3code)
    print('end')

    # 三地址到汇编部分
    # print("hello")
    tac_file = listener.TACBlocks
    # print(tac_file)
    # print(isinstance(tac_file["global"], typing._GenericAlias))
    # print(isinstance(tac_file["myprint"], typing._GenericAlias))
    translator = ts.Translator(tac_file, listener.globalScope)
    translator.Translate()
    path_asm = "./out.asm"
    translator.OutputFile(path_asm)

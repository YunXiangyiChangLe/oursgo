from collections import deque
import typing
from Include.ASMh import *
# from Include.REGh import *
from Include.Scopeh import *
from Include.TACh import *
from Include.GoLexer import *
from Include.GoParser import *
from Include.GoParserListener import *
from Common.Common import *


class Utils:
    def __init__(self) -> None:
        pass

    def ctx_encoder(values: list):
        ret = ''
        for s in values:
            ret += s.__str__()
            ret += DELIMITER
        return ret

    def ctx_decoder(s: str) -> List[str]:
        ret = []
        each = s.split(DELIMITER)
        for e in each:
            ret.append(e)
        ret.pop(-1)
        return ret


class ForStmt:
    def __init__(self, CurIndex, LoopCon: TACLine = None, UpdateCon: TACLine = None):
        self.CurIndex = CurIndex
        self.LoopCon = LoopCon
        self.UpdateCon = UpdateCon
        self.newParas = []

    def ForStmt(self, CurIndex_):
        self.CurIndex = CurIndex_


class TrCodeGen(GoParserListener):
    def __init__(self):
        self.lineIndex = 0  # 行索引
        self.loaclIndex = 0  # 临时变量索引
        self.ifIndex = 0  # if索引用于处理多个else if的情况
        self.forIndex = 0  # for索引用于处理for循环
        self.currentScope: Scope = Scope()  # 当前的处理域
        self.ptrs: dict = {}
        self.globalScope: Scope = Scope()
        self.curFun = 'global'
        self.allScope:list = []
        self.values = {}
        self.ifvalues = {}
        self.forvalues = {}
        self.TACBlocks: Dict[str, List[TACLine]] = {}
        self.TrCodeText: str = ''

    def defineTmpType(self):  # 临时变量类型
        return Type.INT

    def CreateLocalVar(self):  # 创建临时变量
        CheckResult = True
        while (CheckResult):
            local = 'T' + str(self.loaclIndex)  # 临时变量的命名规则：T*
            self.loaclIndex += 1
            res,_ = self.currentScope.resolve(local)
            if res == SUCCESS:
                CheckResult = True
            else:
                CheckResult = False
        symbol = Symbol(local, self.currentScope,
                        SymbolType.VAR, self.defineTmpType())
        self.currentScope.para_define(symbol)
        return local

    def CreateElseLabel(self):  # 创建elseif的Label
        local = str(self.ifIndex)
        self.ifIndex += 1
        return local

    def CreateForLabel(self):  # 创建For循环的Label
        local = str(self.forIndex)
        self.forIndex += 1
        return local

    def TACOPToString(self, num: TACOP):
        match num:
            case TACOP.ADD:
                return 'ADD'
            case TACOP.SUB:
                return 'SUB'
            case TACOP.DIV:
                return 'DIV'
            case TACOP.MUL:
                return 'MUL'
            case TACOP.ASSIGN:
                return 'ASSIGN'
            case TACOP.CALL:
                return 'CALL'
            case TACOP.PARA:
                return 'PARA'
            case TACOP.RET:
                return 'RET'
            case TACOP.ENDCALL:
                return 'ENDCALL'
            case TACOP.FUN_PARA:
                return 'FUN_PARA'
            case TACOP.FUN_RET:
                return 'FUN_RET'
            case TACOP.IFGE:
                return 'IFGE'
            case TACOP.IFLE:
                return 'IFLE'
            case TACOP.IFGT:
                return 'IFGT'
            case TACOP.IFLT:
                return 'IFLT'
            case TACOP.IFEQ:
                return 'IFEQ'
            case TACOP.GOTO:
                return 'GOTO'
            case TACOP.LABEL:
                return 'LABEL'
            case TACOP.CREATLIST:
                return 'CREATLIST'
            case _:
                return ''

    def ToString(self, num: TACOPERANDTYPE):
        match num:
            case TACOPERANDTYPE.VAR:
                return 'VAR'
            case TACOPERANDTYPE.NULL_:
                return 'NULL_'
            case TACOPERANDTYPE.IMM:
                return 'IMM'
            case TACOPERANDTYPE.PTR:
                return 'PTR'
            case TACOPERANDTYPE.LABEL:
                return 'LABEL'
            case _:
                return '----'

    def OperandTypereslove(self, name: str):
        if name and name in self.ptrs.keys() and self.ptrs.get(name) == True:
            return TACOPERANDTYPE.PTR
        if name and name.__len__() > 0 and ((name[0] >= '0' and name[0] < '9') or name[0] == '-'):
            return TACOPERANDTYPE.IMM
        return TACOPERANDTYPE.VAR

    def is_digit(self, s: str):
        if s[0] == '-':
            s = s[1:]
        if s.isdigit():
            return True
        else:
            return False

    def Go23file_(self, filename):
        with open(filename, 'w') as outfile:
            keys = self.TACBlocks.keys()
            for key in keys:
                if key == list(self.TACBlocks.keys())[0]:
                    continue
                block = self.TACBlocks.get(key)
                for it in block:
                    outfile.write(
                        f"{it.line}\t{self.TACOPToString(it.op)}\t{it.src1.value}\t{it.src2.value}\t{it.dst.value}\n")
                outfile.write("----------------------\n")
            outfile.write("----------------------\n")
            outfile.close()

    def push_line(self, op: TACOP, src1: Operand, src2: Operand, dst: Operand):
        curTACLine: TACLine = TACLine(
            self.lineIndex, op, src1, src2, dst, self.currentScope)
        line = self.TACBlocks[self.curFun]
        if not isinstance(line, typing._GenericAlias):
            self.TACBlocks[self.curFun].append(curTACLine)
        else:
            self.TACBlocks[self.curFun] = []
            self.TACBlocks[self.curFun].append(curTACLine)
        """ self.TrCodeText += self.lineIndex.__str__()+'\t' + self.TACOPToString(op) + '\t' + \
            src1.value.__str__() + '\t' + src2.value.__str__() + '\t' + dst.value+'\t\n' """
        self.lineIndex += 1

    def myPrint(self, currentScope: Scope):
        keys = currentScope.para_symbols.keys()
        for key in keys:
            print('para_symbol: ' + key.__str__())
        keys = currentScope.fun_symbols.keys()
        for key in keys:
            print('fun_symbols: ' + key.__str__())

    def addScope(self):
        scope = Scope( self.currentScope)
        self.allScope.append(scope)
        self.currentScope = scope

    def popScope(self):
        self.myPrint(self.currentScope)
        self.currentScope = self.currentScope.enclosing_scope

    # Enter a parse tree produced by GoParser#sourceFile.
    def enterSourceFile(self, ctx: GoParser.SourceFileContext):
        self.currentScope = self.globalScope
        currentBlock: TACBlock = []
        self.TACBlocks[self.curFun] = currentBlock

    # Exit a parse tree produced by GoParser#sourceFile.
    def exitSourceFile(self, ctx: GoParser.SourceFileContext):
        print('exit source file')

    # Enter a parse tree produced by GoParser#packageClause.
    def enterPackageClause(self, ctx: GoParser.PackageClauseContext):
        pass

    # Exit a parse tree produced by GoParser#packageClause.
    def exitPackageClause(self, ctx: GoParser.PackageClauseContext):
        pass

    # Enter a parse tree produced by GoParser#importDecl.
    def enterImportDecl(self, ctx: GoParser.ImportDeclContext):
        pass

    # Exit a parse tree produced by GoParser#importDecl.
    def exitImportDecl(self, ctx: GoParser.ImportDeclContext):
        pass

    # Enter a parse tree produced by GoParser#importSpec.
    def enterImportSpec(self, ctx: GoParser.ImportSpecContext):
        pass

    # Exit a parse tree produced by GoParser#importSpec.
    def exitImportSpec(self, ctx: GoParser.ImportSpecContext):
        pass

    # Enter a parse tree produced by GoParser#importPath.
    def enterImportPath(self, ctx: GoParser.ImportPathContext):
        pass

    # Exit a parse tree produced by GoParser#importPath.
    def exitImportPath(self, ctx: GoParser.ImportPathContext):
        pass

    # Enter a parse tree produced by GoParser#declaration.
    def enterDeclaration(self, ctx: GoParser.DeclarationContext):
        pass

    # Exit a parse tree produced by GoParser#declaration.
    def exitDeclaration(self, ctx: GoParser.DeclarationContext):
        pass

    # Enter a parse tree produced by GoParser#constDecl.
    def enterConstDecl(self, ctx: GoParser.ConstDeclContext):
        pass

    # Exit a parse tree produced by GoParser#constDecl.
    def exitConstDecl(self, ctx: GoParser.ConstDeclContext):
        pass

    # Enter a parse tree produced by GoParser#constSpec.
    def enterConstSpec(self, ctx: GoParser.ConstSpecContext):
        pass

    # Exit a parse tree produced by GoParser#constSpec.
    def exitConstSpec(self, ctx: GoParser.ConstSpecContext):
        pass

    # Enter a parse tree produced by GoParser#identifierList.
    def enterIdentifierList(self, ctx: GoParser.IdentifierListContext):
        pass

    # Exit a parse tree produced by GoParser#identifierList.
    def exitIdentifierList(self, ctx: GoParser.IdentifierListContext):
        pass

    # Enter a parse tree produced by GoParser#expressionList.
    def enterExpressionList(self, ctx: GoParser.ExpressionListContext):
        pass

    # Exit a parse tree produced by GoParser#expressionList.
    def exitExpressionList(self, ctx: GoParser.ExpressionListContext):
        expression_values = []
        for i in range(0, ctx.expression().__len__()):
            s: str = self.values.get(ctx.expression(i))
            vs = Utils.ctx_decoder(s.__str__())
            for each in vs:
                expression_values.append(each)
        self.values[ctx] = Utils.ctx_encoder(expression_values)

    # Enter a parse tree produced by GoParser#typeDecl.

    def enterTypeDecl(self, ctx: GoParser.TypeDeclContext):
        pass

    # Exit a parse tree produced by GoParser#typeDecl.
    def exitTypeDecl(self, ctx: GoParser.TypeDeclContext):
        pass

    # Enter a parse tree produced by GoParser#typeSpec.
    def enterTypeSpec(self, ctx: GoParser.TypeSpecContext):
        pass

    # Exit a parse tree produced by GoParser#typeSpec.
    def exitTypeSpec(self, ctx: GoParser.TypeSpecContext):
        pass

    # Enter a parse tree produced by GoParser#functionDecl.
    def enterFunctionDecl(self, ctx: GoParser.FunctionDeclContext):
        #self.addScope()
        identifier: string = ctx.IDENTIFIER().getText()
        if self.currentScope and self.currentScope.cur_resolve(identifier) == SUCCESS:
            print('Redeclaration of function' + identifier)
            exit(-1)
        self.curFun = identifier
        currentBlock: List[TACLine] = []
        self.TACBlocks[self.curFun] = currentBlock
        funRetTypeList = []
        funParaList = []
        if ctx.signature().result() == None or ctx.signature().result().parameters().parameterDecl().__len__() == 0:
            # do nothing
            print()
        else:
            n = ctx.signature().result().parameters().parameterDecl().__len__()
            for i in range(0, n):
                eachType = ctx.signature().result().parameters(
                ).parameterDecl(i).type_().typeName().getText()
                eachSType = Symbol.toType(eachType)
                funRetTypeList.append(eachType)

        if ctx.signature().parameters().parameterDecl().__len__() == 0:
            print()
        else:
            n = ctx.signature().parameters().parameterDecl().__len__()
            for i in range(0, n):
                eachType = ctx.signature().parameters().parameterDecl(
                    i).type_().typeName().getText()
                eachSType = Symbol.toType(eachType)
                for j in range(0, ctx.signature().parameters().parameterDecl(i).identifierList().IDENTIFIER().__len__()):
                    funParaList.append(eachSType)
        symbol = Symbol(identifier, self.currentScope,
                        SymbolType.FUN, funRetTypeList, funParaList)
        scope = Scope(self.currentScope)
        if not self.currentScope :
            self.currentScope = Scope()
        self.currentScope.fun_define(symbol)
        self.currentScope = scope
        
        for i in range(0, ctx.signature().parameters().parameterDecl().__len__()):
            for j in range(0, ctx.signature().parameters().parameterDecl(i).identifierList().IDENTIFIER().__len__()):
                fun_para = ctx.signature().parameters().parameterDecl(
                    i).identifierList().IDENTIFIER(j).getText()
                # print(fun_para)
                self.push_line(TACOP.FUN_PARA, Operand(fun_para, self.OperandTypereslove(
                    fun_para)), Operand("", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))

    # Exit a parse tree produced by GoParser#functionDecl.

    def exitFunctionDecl(self, ctx: GoParser.FunctionDeclContext):
        self.curFun = 'global'
        self.popScope()

    # Enter a parse tree produced by GoParser#methodDecl.
    def enterMethodDecl(self, ctx: GoParser.MethodDeclContext):
        pass

    # Exit a parse tree produced by GoParser#methodDecl.
    def exitMethodDecl(self, ctx: GoParser.MethodDeclContext):
        pass

    # Enter a parse tree produced by GoParser#receiver.
    def enterReceiver(self, ctx: GoParser.ReceiverContext):
        pass

    # Exit a parse tree produced by GoParser#receiver.
    def exitReceiver(self, ctx: GoParser.ReceiverContext):
        pass

    # Enter a parse tree produced by GoParser#varDecl.
    def enterVarDecl(self, ctx: GoParser.VarDeclContext):
        pass

    # Exit a parse tree produced by GoParser#varDecl.
    def exitVarDecl(self, ctx: GoParser.VarDeclContext):
        pass

    # Enter a parse tree produced by GoParser#varSpec.
    def enterVarSpec(self, ctx: GoParser.VarSpecContext):
        pass

    # Exit a parse tree produced by GoParser#varSpec.
    def exitVarSpec(self, ctx: GoParser.VarSpecContext):
        is_array = False
        array_length = 0
        if ctx.type_() != None and ctx.type_().typeLit() != None:
            is_array = True
            right_values = []
            right_values = Utils.ctx_decoder(
                self.values.get(ctx.type_().typeLit().arrayType().arrayLength()).__str__())
            if right_values.__len__() != 1:
                print('wrong number of array length input ')
                exit(-1)
            array_length_s = right_values[0]
            if self.is_digit(array_length_s):
                array_length = int(array_length_s)
                if array_length < 1:
                    print('array length should >= 1')
                    exit(-1)
            else:
                print('array decleration need static capacity')
                exit(-1)
        n = ctx.identifierList().IDENTIFIER().__len__()
        for i in range(0, n):
            varname = ctx.identifierList().IDENTIFIER(i).getText()
            type: Type
            if ctx.type_() != None:
                type = self.defineTmpType()
            else:
                if ctx.type_().typeName() != None:
                    stype = ctx.type_().typeName().getText()
                    type = Symbol.toType(stype)
                elif ctx.type_().typeLit() and ctx.type_().typeLit().arrayType():
                    stype = ctx.type_().typeName().getText()
                    type = Symbol.toType(stype)
            if self.currentScope.cur_resolve(varname):
                print('Redeclaration of parameter' + varname + '')
                exit(-1)
            symbol = Symbol(varname, self.currentScope,
                            SymbolType.VAR, type, is_array, array_length)
            if is_array:
                self.push_line(TACOP.CREATLIST, Operand(varname, self.OperandTypereslove(varname)), Operand(to_string(
                    array_length), self.OperandTypereslove(to_string(array_length))), Operand("INT", TACOPERANDTYPE.NULL_))
            self.currentScope.para_define(symbol)
        if ctx.expressionList():
            right_values = []
            right_values = Utils.ctx_decoder(
                self.values.get(ctx.expressionList()))
            if n != right_values.__len__():
                print('wrong number matcher')
                exit(-1)
            for i in range(0, n):
                self.push_line(TACOP.ASSIGN, Operand((right_values)[i], self.OperandTypereslove(right_values[i])), Operand("", TACOPERANDTYPE.NULL_), Operand(
                    ctx.identifierList().IDENTIFIER(i).getText(), self.OperandTypereslove(ctx.identifierList().IDENTIFIER(i).getText())))

    # Enter a parse tree produced by GoParser#block.

    def enterBlock(self, ctx: GoParser.BlockContext):
        if ctx.parentCtx.children[0].getText() == 'for':
            self.push_line(TACOP.LABEL, Operand("FORLOOP" + self.forvalues.get(ctx.parentCtx).CurIndex,
                           TACOPERANDTYPE.LABEL), Operand("", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))
        if ctx.parentCtx.children.__len__() >= 5 and ctx.parentCtx.children[4] == ctx and ctx.parentCtx.children[3].getText() == 'else':
            self.push_line(TACOP.LABEL, Operand("ELSE" + self.ifvalues.get(ctx.parentCtx),
                           TACOPERANDTYPE.LABEL), Operand("", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))
            self.addScope()

    # Exit a parse tree produced by GoParser#block.

    def exitBlock(self, ctx: GoParser.BlockContext):
        if ctx.parentCtx.children[0].getText() == 'for':
            fortmp: ForStmt = self.forvalues.get(ctx.parentCtx)
            updateCondition: TACLine = fortmp.UpdateCon
            loopCondition: TACLine = fortmp.LoopCon
            if updateCondition:
                self.push_line(updateCondition.op, updateCondition.src1,
                           updateCondition.src2, updateCondition.dst)
            if loopCondition:
                self.push_line(loopCondition.op, loopCondition.src1,
                           loopCondition.src2, loopCondition.dst)
        if ctx.parentCtx.children[2] == ctx and ctx.parentCtx.children[0].getText() == 'if':
            self.push_line(TACOP.GOTO, Operand("ENDIF" + self.ifvalues.get(ctx.parentCtx),
                           TACOPERANDTYPE.LABEL), Operand("", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))
        self.popScope()

    # Enter a parse tree produced by GoParser#statementList.
    def enterStatementList(self, ctx: GoParser.StatementListContext):
        pass

    # Exit a parse tree produced by GoParser#statementList.
    def exitStatementList(self, ctx: GoParser.StatementListContext):
        pass

    # Enter a parse tree produced by GoParser#statement.
    def enterStatement(self, ctx: GoParser.StatementContext):
        pass

    # Exit a parse tree produced by GoParser#statement.
    def exitStatement(self, ctx: GoParser.StatementContext):
        pass

    # Enter a parse tree produced by GoParser#simpleStmt.
    def enterSimpleStmt(self, ctx: GoParser.SimpleStmtContext):
        pass

    # Exit a parse tree produced by GoParser#simpleStmt.
    def exitSimpleStmt(self, ctx: GoParser.SimpleStmtContext):
        pass

    # Enter a parse tree produced by GoParser#expressionStmt.
    def enterExpressionStmt(self, ctx: GoParser.ExpressionStmtContext):
        pass

    # Exit a parse tree produced by GoParser#expressionStmt.
    def exitExpressionStmt(self, ctx: GoParser.ExpressionStmtContext):
        pass

    # Enter a parse tree produced by GoParser#sendStmt.
    def enterSendStmt(self, ctx: GoParser.SendStmtContext):
        pass

    # Exit a parse tree produced by GoParser#sendStmt.
    def exitSendStmt(self, ctx: GoParser.SendStmtContext):
        pass

    # Enter a parse tree produced by GoParser#incDecStmt.
    def enterIncDecStmt(self, ctx: GoParser.IncDecStmtContext):
        pass

    # Exit a parse tree produced by GoParser#incDecStmt.
    def exitIncDecStmt(self, ctx: GoParser.IncDecStmtContext):
        if ctx.children[1].getText() == '++':
            left_values = Utils.ctx_decoder(self.values.get(ctx.expression()).__str__())
            print(left_values)
            if left_values.__len__() != 1:
                print('too many parameter for incdec \"++\" ')
                exit(-1)
            if ctx.parentCtx.parentCtx.parentCtx.children[0].getText() == 'for' and ctx.parentCtx.parentCtx == ctx.parentCtx.parentCtx.parentCtx.children[1]:
                varname = left_values[0]
                varvalue = '1'
                fortmp: ForStmt = self.forvalues.get(
                    ctx.parentCtx.parentCtx.parentCtx)
                tmpline: TACLine = TACLine(self.lineIndex, TACOP.ADD, Operand(varname, self.OperandTypereslove(varname)), Operand(
                    varvalue, self.OperandTypereslove(varvalue)), Operand(varname, self.OperandTypereslove(varname)), self.currentScope)
                fortmp.UpdateCon = tmpline
                self.forvalues[
                    ctx.parentCtx.parentCtx.parentCtx] = fortmp
            else:
                varname = left_values[0]
                varvalue = '1'
                self.push_line(TACOP.ADD, Operand(varname, self.OperandTypereslove(varname)), Operand(
                    varvalue, self.OperandTypereslove(varvalue)), Operand(varname, self.OperandTypereslove(varname)))

    # Enter a parse tree produced by GoParser#assignment.
    def enterAssignment(self, ctx: GoParser.AssignmentContext):
        pass

    # Exit a parse tree produced by GoParser#assignment.
    def exitAssignment(self, ctx: GoParser.AssignmentContext):
        if ctx.assign_op().getText() == '=':
            left_values = []
            right_values = []
            left_values = Utils.ctx_decoder(
                self.values.get(ctx.expressionList(0)))
            right_values = Utils.ctx_decoder(
                self.values.get(ctx.expressionList(1)))
            if left_values.__len__() != right_values.__len__():
                print('not equal number parameter for assign')
                exit(-1)
            for i in range(left_values.__len__()):
                varname = left_values[i]
                varvalue = right_values[i]
                self.push_line(TACOP.ASSIGN, Operand(varvalue, self.OperandTypereslove(varvalue)), Operand(
                    "", TACOPERANDTYPE.NULL_), Operand(varname, self.OperandTypereslove(varname)))
                
        if ctx.assign_op().getText() == '+=':
            left_values = []
            right_values = []
            left_values = Utils.ctx_decoder(
                self.values.get(ctx.expressionList(0)))
            right_values = Utils.ctx_decoder(
                self.values.get(ctx.expressionList(1)))
            if left_values.__len__() != 1 or right_values.__len__() != 1:
                print('too many parameter for assign \"+=\" ')
                exit(-1)
            if ctx.parentCtx.parentCtx.parentCtx.children[0].getText() == 'for' and ctx.parentCtx.parentCtx == ctx.parentCtx.parentCtx.parentCtx.children[1]:
                varname = left_values[0]
                varvalue = right_values[0]
                fortmp: ForStmt = self.forvalues.get(
                    ctx.parentCtx.parentCtx.parentCtx)
                tmpline = TACLine(self.lineIndex, TACOP.ADD, Operand(varname, self.OperandTypereslove(varname)), Operand(
                    varvalue, self.OperandTypereslove(varvalue)), Operand(varname, self.OperandTypereslove(varname)), self.currentScope)
                fortmp.UpdateCon = tmpline
                self.forvalues[ctx.parentCtx.parentCtx.parentCtx]= fortmp
            else:
                varname = left_values[0]
                varvalue = right_values[0]
                self.push_line(TACOP.ADD, Operand(varname, self .OperandTypereslove(varname)), Operand(
                    varvalue, self.OperandTypereslove(varvalue)), Operand(varname, self.OperandTypereslove(varname)))

    # Enter a parse tree produced by GoParser#assign_op.
    def enterAssign_op(self, ctx: GoParser.Assign_opContext):
        pass

    # Exit a parse tree produced by GoParser#assign_op.
    def exitAssign_op(self, ctx: GoParser.Assign_opContext):
        pass

    # Enter a parse tree produced by GoParser#shortVarDecl.
    def enterShortVarDecl(self, ctx: GoParser.ShortVarDeclContext):
        pass

    # Exit a parse tree produced by GoParser#shortVarDecl.
    def exitShortVarDecl(self, ctx: GoParser.ShortVarDeclContext):
        n = ctx.identifierList().IDENTIFIER().__len__()
        for i in range(0, n):
            varname = ctx.identifierList().IDENTIFIER(i).getText()
            type: Type
            type = self.defineTmpType()
            symbol = Symbol(varname, self.currentScope, SymbolType.VAR, type)
            self.currentScope.para_define(symbol)
        if ctx.expressionList():
            right_values = []
            right_values = Utils.ctx_decoder(
                self.values.get(ctx.expressionList()))
            if n != right_values.__len__():
                print('wrong number match ')
                exit(-1)
            for i in range(0, n):
                self.push_line(TACOP.ASSIGN, Operand(right_values[i], self.OperandTypereslove(right_values[i])), Operand("", TACOPERANDTYPE. NULL_), Operand(
                    ctx.identifierList().IDENTIFIER(i).getText(), self.OperandTypereslove(ctx.identifierList().IDENTIFIER(i).getText())))
        if ctx.parentCtx.parentCtx.parentCtx.children[0].getText() == 'for' and ctx.parentCtx.parentCtx.parentCtx.children[1] == ctx.parentCtx.parentCtx:
            tmp: ForStmt = self.forvalues.get(
                ctx.parentCtx.parentCtx.parentCtx)
            for i in range(0, n):
                varname = ctx.identifierList().IDENTIFIER(i).getText()
                
                tmp.newParas.append(varname)
            self.forvalues[ctx.parentCtx.parentCtx.parentCtx] = tmp

    # Enter a parse tree produced by GoParser#emptyStmt.
    def enterEmptyStmt(self, ctx: GoParser.EmptyStmtContext):
        pass

    # Exit a parse tree produced by GoParser#emptyStmt.
    def exitEmptyStmt(self, ctx: GoParser.EmptyStmtContext):
        pass

    # Enter a parse tree produced by GoParser#labeledStmt.
    def enterLabeledStmt(self, ctx: GoParser.LabeledStmtContext):
        pass

    # Exit a parse tree produced by GoParser#labeledStmt.
    def exitLabeledStmt(self, ctx: GoParser.LabeledStmtContext):
        pass

    # Enter a parse tree produced by GoParser#returnStmt.
    def enterReturnStmt(self, ctx: GoParser.ReturnStmtContext):
        pass

    # Exit a parse tree produced by GoParser#returnStmt.
    def exitReturnStmt(self, ctx: GoParser.ReturnStmtContext):
        return_values = []
        return_values = Utils.ctx_decoder(
            self.values.get(ctx.expressionList()))
        for i in return_values:
            tmp: Symbol
            res, tmp = self.currentScope.resolve(i, None)
            if (res == FAIL):
                print('Undefined' + i + '')
                exit(-1)
        for i in return_values:
            self.push_line(TACOP.FUN_RET, Operand(i, self.OperandTypereslove(i)), Operand(
                "", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))

    # Enter a parse tree produced by GoParser#breakStmt.
    def enterBreakStmt(self, ctx: GoParser.BreakStmtContext):
        pass

    # Exit a parse tree produced by GoParser#breakStmt.
    def exitBreakStmt(self, ctx: GoParser.BreakStmtContext):
        pass

    # Enter a parse tree produced by GoParser#continueStmt.
    def enterContinueStmt(self, ctx: GoParser.ContinueStmtContext):
        pass

    # Exit a parse tree produced by GoParser#continueStmt.
    def exitContinueStmt(self, ctx: GoParser.ContinueStmtContext):
        pass

    # Enter a parse tree produced by GoParser#gotoStmt.
    def enterGotoStmt(self, ctx: GoParser.GotoStmtContext):
        pass

    # Exit a parse tree produced by GoParser#gotoStmt.
    def exitGotoStmt(self, ctx: GoParser.GotoStmtContext):
        pass

    # Enter a parse tree produced by GoParser#fallthroughStmt.
    def enterFallthroughStmt(self, ctx: GoParser.FallthroughStmtContext):
        pass

    # Exit a parse tree produced by GoParser#fallthroughStmt.
    def exitFallthroughStmt(self, ctx: GoParser.FallthroughStmtContext):
        pass

    # Enter a parse tree produced by GoParser#deferStmt.
    def enterDeferStmt(self, ctx: GoParser.DeferStmtContext):
        pass

    # Exit a parse tree produced by GoParser#deferStmt.
    def exitDeferStmt(self, ctx: GoParser.DeferStmtContext):
        pass

    # Enter a parse tree produced by GoParser#ifStmt.
    def enterIfStmt(self, ctx: GoParser.IfStmtContext):
        iftmp = self.CreateElseLabel()
        self.ifvalues[ctx]= iftmp

    # Exit a parse tree produced by GoParser#ifStmt.
    def exitIfStmt(self, ctx: GoParser.IfStmtContext):
        self.push_line(TACOP.LABEL, Operand("ENDIF" + self.ifvalues.get(ctx), TACOPERANDTYPE.LABEL),
                       Operand("", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))

    # Enter a parse tree produced by GoParser#switchStmt.
    def enterSwitchStmt(self, ctx: GoParser.SwitchStmtContext):
        pass

    # Exit a parse tree produced by GoParser#switchStmt.
    def exitSwitchStmt(self, ctx: GoParser.SwitchStmtContext):
        pass

    # Enter a parse tree produced by GoParser#exprSwitchStmt.
    def enterExprSwitchStmt(self, ctx: GoParser.ExprSwitchStmtContext):
        pass

    # Exit a parse tree produced by GoParser#exprSwitchStmt.
    def exitExprSwitchStmt(self, ctx: GoParser.ExprSwitchStmtContext):
        pass

    # Enter a parse tree produced by GoParser#exprCaseClause.
    def enterExprCaseClause(self, ctx: GoParser.ExprCaseClauseContext):
        pass

    # Exit a parse tree produced by GoParser#exprCaseClause.
    def exitExprCaseClause(self, ctx: GoParser.ExprCaseClauseContext):
        pass

    # Enter a parse tree produced by GoParser#exprSwitchCase.
    def enterExprSwitchCase(self, ctx: GoParser.ExprSwitchCaseContext):
        pass

    # Exit a parse tree produced by GoParser#exprSwitchCase.
    def exitExprSwitchCase(self, ctx: GoParser.ExprSwitchCaseContext):
        pass

    # Enter a parse tree produced by GoParser#typeSwitchStmt.
    def enterTypeSwitchStmt(self, ctx: GoParser.TypeSwitchStmtContext):
        pass

    # Exit a parse tree produced by GoParser#typeSwitchStmt.
    def exitTypeSwitchStmt(self, ctx: GoParser.TypeSwitchStmtContext):
        pass

    # Enter a parse tree produced by GoParser#typeSwitchGuard.
    def enterTypeSwitchGuard(self, ctx: GoParser.TypeSwitchGuardContext):
        pass

    # Exit a parse tree produced by GoParser#typeSwitchGuard.
    def exitTypeSwitchGuard(self, ctx: GoParser.TypeSwitchGuardContext):
        pass

    # Enter a parse tree produced by GoParser#typeCaseClause.
    def enterTypeCaseClause(self, ctx: GoParser.TypeCaseClauseContext):
        pass

    # Exit a parse tree produced by GoParser#typeCaseClause.
    def exitTypeCaseClause(self, ctx: GoParser.TypeCaseClauseContext):
        pass

    # Enter a parse tree produced by GoParser#typeSwitchCase.
    def enterTypeSwitchCase(self, ctx: GoParser.TypeSwitchCaseContext):
        pass

    # Exit a parse tree produced by GoParser#typeSwitchCase.
    def exitTypeSwitchCase(self, ctx: GoParser.TypeSwitchCaseContext):
        pass

    # Enter a parse tree produced by GoParser#typeList.
    def enterTypeList(self, ctx: GoParser.TypeListContext):
        pass

    # Exit a parse tree produced by GoParser#typeList.
    def exitTypeList(self, ctx: GoParser.TypeListContext):
        pass

    # Enter a parse tree produced by GoParser#selectStmt.
    def enterSelectStmt(self, ctx: GoParser.SelectStmtContext):
        pass

    # Exit a parse tree produced by GoParser#selectStmt.
    def exitSelectStmt(self, ctx: GoParser.SelectStmtContext):
        pass

    # Enter a parse tree produced by GoParser#commClause.
    def enterCommClause(self, ctx: GoParser.CommClauseContext):
        pass

    # Exit a parse tree produced by GoParser#commClause.
    def exitCommClause(self, ctx: GoParser.CommClauseContext):
        pass

    # Enter a parse tree produced by GoParser#commCase.
    def enterCommCase(self, ctx: GoParser.CommCaseContext):
        pass

    # Exit a parse tree produced by GoParser#commCase.
    def exitCommCase(self, ctx: GoParser.CommCaseContext):
        pass

    # Enter a parse tree produced by GoParser#recvStmt.
    def enterRecvStmt(self, ctx: GoParser.RecvStmtContext):
        pass

    # Exit a parse tree produced by GoParser#recvStmt.
    def exitRecvStmt(self, ctx: GoParser.RecvStmtContext):
        pass

    # Enter a parse tree produced by GoParser#forStmt.
    def enterForStmt(self, ctx: GoParser.ForStmtContext):
        tmp = self.CreateForLabel()
        newfor: ForStmt = ForStmt(tmp)
        print(newfor.CurIndex + '')
        self.forvalues[ctx] = newfor
        self.addScope()

    # Exit a parse tree produced by GoParser#forStmt.
    def exitForStmt(self, ctx: GoParser.ForStmtContext):
        tmp: ForStmt = self.forvalues.get(ctx)
        self.popScope()
        self.push_line(TACOP.LABEL, Operand("ENDFOR" + self.forvalues.get(ctx).CurIndex,
                       TACOPERANDTYPE.LABEL), Operand("", TACOPERANDTYPE.NULL_), Operand("", TACOPERANDTYPE.NULL_))

    # Enter a parse tree produced by GoParser#forClause.
    def enterForClause(self, ctx: GoParser.ForClauseContext):
        pass

    # Exit a parse tree produced by GoParser#forClause.
    def exitForClause(self, ctx: GoParser.ForClauseContext):
        pass

    # Enter a parse tree produced by GoParser#rangeClause.
    def enterRangeClause(self, ctx: GoParser.RangeClauseContext):
        pass

    # Exit a parse tree produced by GoParser#rangeClause.
    def exitRangeClause(self, ctx: GoParser.RangeClauseContext):
        pass

    # Enter a parse tree produced by GoParser#goStmt.
    def enterGoStmt(self, ctx: GoParser.GoStmtContext):
        pass

    # Exit a parse tree produced by GoParser#goStmt.
    def exitGoStmt(self, ctx: GoParser.GoStmtContext):
        pass

    # Enter a parse tree produced by GoParser#type_.
    def enterType_(self, ctx: GoParser.Type_Context):
        pass

    # Exit a parse tree produced by GoParser#type_.
    def exitType_(self, ctx: GoParser.Type_Context):
        pass

    # Enter a parse tree produced by GoParser#typeName.
    def enterTypeName(self, ctx: GoParser.TypeNameContext):
        pass

    # Exit a parse tree produced by GoParser#typeName.
    def exitTypeName(self, ctx: GoParser.TypeNameContext):
        pass

    # Enter a parse tree produced by GoParser#typeLit.
    def enterTypeLit(self, ctx: GoParser.TypeLitContext):
        pass

    # Exit a parse tree produced by GoParser#typeLit.
    def exitTypeLit(self, ctx: GoParser.TypeLitContext):
        pass

    # Enter a parse tree produced by GoParser#arrayType.
    def enterArrayType(self, ctx: GoParser.ArrayTypeContext):
        pass

    # Exit a parse tree produced by GoParser#arrayType.
    def exitArrayType(self, ctx: GoParser.ArrayTypeContext):
        pass

    # Enter a parse tree produced by GoParser#arrayLength.
    def enterArrayLength(self, ctx: GoParser.ArrayLengthContext):
        pass

    # Exit a parse tree produced by GoParser#arrayLength.
    def exitArrayLength(self, ctx: GoParser.ArrayLengthContext):
        pass

    # Enter a parse tree produced by GoParser#elementType.
    def enterElementType(self, ctx: GoParser.ElementTypeContext):
        pass

    # Exit a parse tree produced by GoParser#elementType.
    def exitElementType(self, ctx: GoParser.ElementTypeContext):
        pass

    # Enter a parse tree produced by GoParser#pointerType.
    def enterPointerType(self, ctx: GoParser.PointerTypeContext):
        pass

    # Exit a parse tree produced by GoParser#pointerType.
    def exitPointerType(self, ctx: GoParser.PointerTypeContext):
        pass

    # Enter a parse tree produced by GoParser#interfaceType.
    def enterInterfaceType(self, ctx: GoParser.InterfaceTypeContext):
        pass

    # Exit a parse tree produced by GoParser#interfaceType.
    def exitInterfaceType(self, ctx: GoParser.InterfaceTypeContext):
        pass

    # Enter a parse tree produced by GoParser#sliceType.
    def enterSliceType(self, ctx: GoParser.SliceTypeContext):
        pass

    # Exit a parse tree produced by GoParser#sliceType.
    def exitSliceType(self, ctx: GoParser.SliceTypeContext):
        pass

    # Enter a parse tree produced by GoParser#mapType.
    def enterMapType(self, ctx: GoParser.MapTypeContext):
        pass

    # Exit a parse tree produced by GoParser#mapType.
    def exitMapType(self, ctx: GoParser.MapTypeContext):
        pass

    # Enter a parse tree produced by GoParser#channelType.
    def enterChannelType(self, ctx: GoParser.ChannelTypeContext):
        pass

    # Exit a parse tree produced by GoParser#channelType.
    def exitChannelType(self, ctx: GoParser.ChannelTypeContext):
        pass

    # Enter a parse tree produced by GoParser#methodSpec.
    def enterMethodSpec(self, ctx: GoParser.MethodSpecContext):
        pass

    # Exit a parse tree produced by GoParser#methodSpec.
    def exitMethodSpec(self, ctx: GoParser.MethodSpecContext):
        pass

    # Enter a parse tree produced by GoParser#functionType.
    def enterFunctionType(self, ctx: GoParser.FunctionTypeContext):
        pass

    # Exit a parse tree produced by GoParser#functionType.
    def exitFunctionType(self, ctx: GoParser.FunctionTypeContext):
        pass

    # Enter a parse tree produced by GoParser#signature.
    def enterSignature(self, ctx: GoParser.SignatureContext):
        pass

    # Exit a parse tree produced by GoParser#signature.
    def exitSignature(self, ctx: GoParser.SignatureContext):
        pass

    # Enter a parse tree produced by GoParser#result.
    def enterResult(self, ctx: GoParser.ResultContext):
        pass

    # Exit a parse tree produced by GoParser#result.
    def exitResult(self, ctx: GoParser.ResultContext):
        pass

    # Enter a parse tree produced by GoParser#parameters.
    def enterParameters(self, ctx: GoParser.ParametersContext):
        pass

    # Exit a parse tree produced by GoParser#parameters.
    def exitParameters(self, ctx: GoParser.ParametersContext):
        pass

    # Enter a parse tree produced by GoParser#parameterDecl.
    def enterParameterDecl(self, ctx: GoParser.ParameterDeclContext):
      if ctx.identifierList():
          n = ctx.identifierList().IDENTIFIER().__len__()
          for i in range(0, n):
              integer: string = ctx.identifierList().IDENTIFIER(i).getText()
              stype = ctx.type_().typeName().getText()
              type: Type = Symbol.toType(stype)
              symbol = Symbol(integer, self.currentScope, SymbolType.VAR, type)
              self.currentScope.para_define(symbol)

    # Exit a parse tree produced by GoParser#parameterDecl.
    def exitParameterDecl(self, ctx: GoParser.ParameterDeclContext):
        pass

    # Enter a parse tree produced by GoParser#LogicalAndOperation.
    def enterLogicalAndOperation(self, ctx: GoParser.LogicalAndOperationContext):
        pass

    # Exit a parse tree produced by GoParser#LogicalAndOperation.
    def exitLogicalAndOperation(self, ctx: GoParser.LogicalAndOperationContext):
        pass

    # Enter a parse tree produced by GoParser#UnaryOperation.
    def enterUnaryOperation(self, ctx: GoParser.UnaryOperationContext):
        pass

    # Exit a parse tree produced by GoParser#UnaryOperation.
    def exitUnaryOperation(self, ctx: GoParser.UnaryOperationContext):
        pass

    # Enter a parse tree produced by GoParser#PrimaryExpression.
    def enterPrimaryExpression(self, ctx: GoParser.PrimaryExpressionContext):
        pass

    # Exit a parse tree produced by GoParser#PrimaryExpression.
    def exitPrimaryExpression(self, ctx: GoParser.PrimaryExpressionContext):
        ExpresionValue = self.values.get(ctx.primaryExpr())
        self.values[ctx] = ExpresionValue

    # Enter a parse tree produced by GoParser#PlusMinusOperation.
    def enterPlusMinusOperation(self, ctx: GoParser.PlusMinusOperationContext):
        pass

    # Exit a parse tree produced by GoParser#PlusMinusOperation.
    def exitPlusMinusOperation(self, ctx: GoParser.PlusMinusOperationContext):
        left = Utils.ctx_decoder(self.values.get(ctx.expression(0)))
        right = Utils.ctx_decoder(self.values.get(ctx.expression(1)))
        if (left.__len__() != 1 or right.__len__() != 1):
            print('wrong literal number1 ')
            exit(-1)
        dst = self.CreateLocalVar()
        plusMinusOperation_values = []
        plusMinusOperation_values.append(dst)

        if ctx.PLUS():
            #print(left[0] + " "+ right[0] + " " + dst)
            self.push_line(TACOP.ADD, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                right[0], self.OperandTypereslove(right[0])), Operand(dst, self.OperandTypereslove(dst)))
        elif ctx.MINUS() != None:
            self.push_line(TACOP.SUB, Operand(left[0], self.OperandTypereslove(right[0])), Operand(
                right[0], self.OperandTypereslove(right[0])), Operand(dst, self.OperandTypereslove(dst)))
        self.values[ctx] = Utils.ctx_encoder(plusMinusOperation_values)

    # Enter a parse tree produced by GoParser#RelationOperation.
    def enterRelationOperation(self, ctx: GoParser.RelationOperationContext):
        pass

    # Exit a parse tree produced by GoParser#RelationOperation.
    def exitRelationOperation(self, ctx: GoParser.RelationOperationContext):
        left = Utils.ctx_decoder(self.values.get(ctx.expression(0)))
        right = Utils.ctx_decoder(self.values.get(ctx.expression(1)))
        if left.__len__() != 1 or right.__len__() != 1:
            print('wrong literal number2')
            exit(-1)
        if ctx.parentCtx.parentCtx.children[0].getText() == 'for' and ctx.parentCtx.parentCtx.children[1] == ctx.parentCtx:
            #tmp = ForStmt()
            tmp = self.forvalues.get(ctx.parentCtx.parentCtx)
            dst = 'ENDFOR' + tmp.CurIndex
            dst_ = 'FORLOOP' + tmp.CurIndex
            tmpline = TACLine()
            if ctx.EQUALS() != None:
                tmpline = TACLine(self.lineIndex, TACOP.IFEQ, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst_, TACOPERANDTYPE.LABEL), self.currentScope)
                self.push_line(TACOP.IFNEQ, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.GREATER() != None:
                tmpline = TACLine(self.lineIndex, TACOP.IFGE, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst_, TACOPERANDTYPE.LABEL), self.currentScope)

                self.push_line(TACOP.IFLT, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.LESS() != None:
                tmpline = TACLine(self.lineIndex, TACOP.IFLT, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst_, TACOPERANDTYPE.LABEL), self.currentScope)

                self.push_line(TACOP.IFGE, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.LESS_OR_EQUALS() != None:
                tmpline = TACLine(self.lineIndex, TACOP.IFLE, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst_, TACOPERANDTYPE.LABEL), self.currentScope)

                self.push_line(TACOP.IFGT, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            tmp.LoopCon = tmpline
            self.forvalues[ctx.parentCtx.parentCtx] = tmp
        if ctx.parentCtx.getText().find('if') == 0 and ctx == ctx.parentCtx.children[1]:
            dst: string
            if ctx.parentCtx.getText().find('else') != -1:
                dst = 'ELSE' + self.ifvalues.get(ctx.parentCtx)
            else:
                dst = 'ENDIF' + self.ifvalues.get(ctx.parentCtx)
            if ctx.EQUALS() != None:
                self.push_line(TACOP.IFNEQ, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.NOT_EQUALS != None:
                self.push_line(TACOP.IFEQ, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.GREATER() != None:
                self.push_line(TACOP.IFLE, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.GREATER_OR_EQUALS() != None:
                self.push_line(TACOP.IFLT, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.LESS() != None:
                self.push_line(TACOP.IFGE, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))
            elif ctx.LESS_OR_EQUALS() != None:
                self.push_line(TACOP.IFGT, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                    right[0], self.OperandTypereslove(right[0])), Operand(dst, TACOPERANDTYPE.LABEL))

    # Enter a parse tree produced by GoParser#MulDivOperation.

    def enterMulDivOperation(self, ctx: GoParser.MulDivOperationContext):
        pass

    # Exit a parse tree produced by GoParser#MulDivOperation.
    def exitMulDivOperation(self, ctx: GoParser.MulDivOperationContext):
        left = Utils.ctx_decoder(self.values.get(ctx.expression(0)))
        right = Utils.ctx_decoder(self.values.get(ctx.expression(1)))
        if left.__len__() != 1 or right.__len__() != 1:
            print('wrong literal number2')
            exit(-1)
        dst = self.CreateLocalVar()
        mulDivOperation_values = []
        mulDivOperation_values.append(dst)
        if ctx.STAR() != None:
            self.push_line(TACOP.MUL, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                right[0], self.OperandTypereslove(right[0])), Operand(dst, self.OperandTypereslove(dst)))
        elif ctx.DIV() != None:
            self.push_line(TACOP.DIV, Operand(left[0], self.OperandTypereslove(left[0])), Operand(
                right[0], self.OperandTypereslove(right[0])), Operand(dst, self.OperandTypereslove(dst)))
        self.values[ctx] = Utils.ctx_encoder(mulDivOperation_values)

    # Enter a parse tree produced by GoParser#LogicalOrOperation.
    def enterLogicalOrOperation(self, ctx: GoParser.LogicalOrOperationContext):
        pass

    # Exit a parse tree produced by GoParser#LogicalOrOperation.
    def exitLogicalOrOperation(self, ctx: GoParser.LogicalOrOperationContext):
        pass

    # Enter a parse tree produced by GoParser#primaryExpr.
    def enterPrimaryExpr(self, ctx: GoParser.PrimaryExprContext):
        pass

    # Exit a parse tree produced by GoParser#primaryExpr.
    def exitPrimaryExpr(self, ctx: GoParser.PrimaryExprContext):
        if ctx.arguments():
            primaryExpr_value = []
            fun_identity = Utils.ctx_decoder(
                self.values.get(ctx.primaryExpr()).__str__())
            identity = fun_identity[0]
            fun_symbol: Symbol
            res, fun_symbol = self.currentScope.resolve(identity, None)
            if res == FAIL:
                print("Undefined function:" + identity)
                exit(-1)
            arguments = Utils.ctx_decoder(self.values.get(ctx.arguments()))
            if fun_symbol.fun_para_type_list and fun_symbol.fun_para_type_list.__len__() != arguments.__len__():
                print("Undefined function: " + identity)
                exit(-1)
            blank = ""
            for ret in fun_symbol.fun_ret_type_list:
                tmp = self.CreateLocalVar()
                self.push_line(TACOP.RET, Operand(tmp, self.OperandTypereslove(tmp)), Operand(
                    blank, TACOPERANDTYPE.NULL_), Operand(blank, TACOPERANDTYPE.NULL_))
                primaryExpr_value.append(tmp)
            for para in arguments:
                self.push_line(TACOP.PARA, Operand(para, self.OperandTypereslove(para)), Operand(
                    blank, TACOPERANDTYPE.NULL_), Operand(blank, TACOPERANDTYPE.NULL_))
            self.push_line(TACOP.CALL, Operand(identity, self.OperandTypereslove(identity)), Operand(
                blank, TACOPERANDTYPE.NULL_), Operand(blank, TACOPERANDTYPE.NULL_))
            self.values[ctx] = Utils.ctx_encoder(primaryExpr_value)
        elif ctx.operand():
            PrimaryExprValue = self.values.get(ctx.operand())
            self.values[ctx] = PrimaryExprValue
        elif ctx.index():
            array_name = []
            array_name = Utils.ctx_decoder(self.values.get(ctx.primaryExpr()).__str__())
            identity = array_name[0]
            array_symbol = Symbol()
            _, array_symbol = self.currentScope.resolve(identity, array_symbol)
            if not array_symbol.is_array:
                print("Only array can be indexed: " + identity + '')
            array_index = []
            array_index = Utils.ctx_decoder(
                self.values.get(ctx.index().expression()))
            index_s = array_index[0]
            if 1 != array_index.__len__():
                print('wrong number of array index input ')
                exit(-1)
            if self.is_digit(index_s):
                idx = int(index_s)
                if idx > array_symbol.array_length - 1 or idx < 0:
                    print('Array index out of bound: ' + identity + '')
                    print(idx + ' ' + array_symbol.array_length + '')
                    exit(-1)
            temp_ptr_offset = self.CreateLocalVar()
            int_size = "4"
            self.push_line(TACOP.MUL, Operand(int_size, self.OperandTypereslove(int_size)), Operand(
                index_s, self.OperandTypereslove(index_s)), Operand(temp_ptr_offset, self.OperandTypereslove(temp_ptr_offset)))
            temp_ptr = self.CreateLocalVar()
            self.push_line(TACOP.ADD,
                           Operand(identity, self.OperandTypereslove(identity)),
                           Operand(temp_ptr_offset,
                                   self.OperandTypereslove(temp_ptr_offset)),
                           Operand(temp_ptr, self.OperandTypereslove(temp_ptr)))
            self.ptrs[temp_ptr] = True
            self.values[ctx] = temp_ptr

    # Enter a parse tree produced by GoParser#conversion.

    def enterConversion(self, ctx: GoParser.ConversionContext):
        pass

    # Exit a parse tree produced by GoParser#conversion.
    def exitConversion(self, ctx: GoParser.ConversionContext):
        pass

    # Enter a parse tree produced by GoParser#nonNamedType.
    def enterNonNamedType(self, ctx: GoParser.NonNamedTypeContext):
        pass

    # Exit a parse tree produced by GoParser#nonNamedType.
    def exitNonNamedType(self, ctx: GoParser.NonNamedTypeContext):
        pass

    # Enter a parse tree produced by GoParser#operand.
    def enterOperand(self, ctx: GoParser.OperandContext):
        pass

    # Exit a parse tree produced by GoParser#operand.
    def exitOperand(self, ctx: GoParser.OperandContext):
        if ctx.literal() != None:
            OperandValue = self.values.get(ctx.literal())
            self.values[ctx] = OperandValue
        if ctx.expression() != None:
            OperandValue = self.values.get(ctx.expression())
            self.values[ctx] = OperandValue
        if ctx.operandName() != None:
            OperandValue = self.values.get(ctx.operandName())
            self.values[ctx] = OperandValue

    # Enter a parse tree produced by GoParser#literal.

    def enterLiteral(self, ctx: GoParser.LiteralContext):
        pass

    # Exit a parse tree produced by GoParser#literal.
    def exitLiteral(self, ctx: GoParser.LiteralContext):
        if ctx.basicLit() != None:
            LiteralValue = self.values.get(ctx.basicLit())
            self.values[ctx] = LiteralValue.__str__() + DELIMITER

    # Enter a parse tree produced by GoParser#basicLit.
    def enterBasicLit(self, ctx: GoParser.BasicLitContext):
        pass

    # Exit a parse tree produced by GoParser#basicLit.
    def exitBasicLit(self, ctx: GoParser.BasicLitContext):
        if ctx.integer() != None:
            BasicLitValue = self.values.get(ctx.integer())
            self.values[ctx] = BasicLitValue

    # Enter a parse tree produced by GoParser#integer.
    def enterInteger(self, ctx: GoParser.IntegerContext):
        pass

    # Exit a parse tree produced by GoParser#integer.
    def exitInteger(self, ctx: GoParser.IntegerContext):
        self.values[ctx] = ctx.DECIMAL_LIT().getText()

    # Enter a parse tree produced by GoParser#operandName.

    def enterOperandName(self, ctx: GoParser.OperandNameContext):
        pass

    # Exit a parse tree produced by GoParser#operandName.
    def exitOperandName(self, ctx: GoParser.OperandNameContext):
        # tmp = Symbol()
        if self.currentScope.resolve(ctx.IDENTIFIER().getText(), None) == FAIL:
            print('Undefined: ' + ctx.IDENTIFIER().getText())
            exit(-1)
        self.values[ctx] = ctx.IDENTIFIER().getText() + DELIMITER

    # Enter a parse tree produced by GoParser#qualifiedIdent.
    def enterQualifiedIdent(self, ctx: GoParser.QualifiedIdentContext):
        pass

    # Exit a parse tree produced by GoParser#qualifiedIdent.
    def exitQualifiedIdent(self, ctx: GoParser.QualifiedIdentContext):
        pass

    # Enter a parse tree produced by GoParser#compositeLit.
    def enterCompositeLit(self, ctx: GoParser.CompositeLitContext):
        pass

    # Exit a parse tree produced by GoParser#compositeLit.
    def exitCompositeLit(self, ctx: GoParser.CompositeLitContext):
        pass

    # Enter a parse tree produced by GoParser#literalType.
    def enterLiteralType(self, ctx: GoParser.LiteralTypeContext):
        pass

    # Exit a parse tree produced by GoParser#literalType.
    def exitLiteralType(self, ctx: GoParser.LiteralTypeContext):
        pass

    # Enter a parse tree produced by GoParser#literalValue.
    def enterLiteralValue(self, ctx: GoParser.LiteralValueContext):
        pass

    # Exit a parse tree produced by GoParser#literalValue.
    def exitLiteralValue(self, ctx: GoParser.LiteralValueContext):
        pass

    # Enter a parse tree produced by GoParser#elementList.
    def enterElementList(self, ctx: GoParser.ElementListContext):
        pass

    # Exit a parse tree produced by GoParser#elementList.
    def exitElementList(self, ctx: GoParser.ElementListContext):
        pass

    # Enter a parse tree produced by GoParser#keyedElement.
    def enterKeyedElement(self, ctx: GoParser.KeyedElementContext):
        pass

    # Exit a parse tree produced by GoParser#keyedElement.
    def exitKeyedElement(self, ctx: GoParser.KeyedElementContext):
        pass

    # Enter a parse tree produced by GoParser#key.
    def enterKey(self, ctx: GoParser.KeyContext):
        pass

    # Exit a parse tree produced by GoParser#key.
    def exitKey(self, ctx: GoParser.KeyContext):
        pass

    # Enter a parse tree produced by GoParser#element.
    def enterElement(self, ctx: GoParser.ElementContext):
        pass

    # Exit a parse tree produced by GoParser#element.
    def exitElement(self, ctx: GoParser.ElementContext):
        pass

    # Enter a parse tree produced by GoParser#structType.
    def enterStructType(self, ctx: GoParser.StructTypeContext):
        pass

    # Exit a parse tree produced by GoParser#structType.
    def exitStructType(self, ctx: GoParser.StructTypeContext):
        pass

    # Enter a parse tree produced by GoParser#fieldDecl.
    def enterFieldDecl(self, ctx: GoParser.FieldDeclContext):
        pass

    # Exit a parse tree produced by GoParser#fieldDecl.
    def exitFieldDecl(self, ctx: GoParser.FieldDeclContext):
        pass

    # Enter a parse tree produced by GoParser#string_.
    def enterString_(self, ctx: GoParser.String_Context):
        pass

    # Exit a parse tree produced by GoParser#string_.
    def exitString_(self, ctx: GoParser.String_Context):
        pass

    # Enter a parse tree produced by GoParser#embeddedField.
    def enterEmbeddedField(self, ctx: GoParser.EmbeddedFieldContext):
        pass

    # Exit a parse tree produced by GoParser#embeddedField.
    def exitEmbeddedField(self, ctx: GoParser.EmbeddedFieldContext):
        pass

    # Enter a parse tree produced by GoParser#functionLit.
    def enterFunctionLit(self, ctx: GoParser.FunctionLitContext):
        pass

    # Exit a parse tree produced by GoParser#functionLit.
    def exitFunctionLit(self, ctx: GoParser.FunctionLitContext):
        pass

    # Enter a parse tree produced by GoParser#index.
    def enterIndex(self, ctx: GoParser.IndexContext):
        pass

    # Exit a parse tree produced by GoParser#index.
    def exitIndex(self, ctx: GoParser.IndexContext):
        pass

    # Enter a parse tree produced by GoParser#slice_.
    def enterSlice_(self, ctx: GoParser.Slice_Context):
        pass

    # Exit a parse tree produced by GoParser#slice_.
    def exitSlice_(self, ctx: GoParser.Slice_Context):
        pass

    # Enter a parse tree produced by GoParser#typeAssertion.
    def enterTypeAssertion(self, ctx: GoParser.TypeAssertionContext):
        pass

    # Exit a parse tree produced by GoParser#typeAssertion.
    def exitTypeAssertion(self, ctx: GoParser.TypeAssertionContext):
        pass

    # Enter a parse tree produced by GoParser#arguments.
    def enterArguments(self, ctx: GoParser.ArgumentsContext):
        pass

    # Exit a parse tree produced by GoParser#arguments.
    def exitArguments(self, ctx: GoParser.ArgumentsContext):
        if ctx.expressionList():
            self.values[ctx] = self.values.get(ctx.expressionList())

    # Enter a parse tree produced by GoParser#methodExpr.
    def enterMethodExpr(self, ctx: GoParser.MethodExprContext):
        pass

    # Exit a parse tree produced by GoParser#methodExpr.
    def exitMethodExpr(self, ctx: GoParser.MethodExprContext):
        pass

    # Enter a parse tree produced by GoParser#receiverType.
    def enterReceiverType(self, ctx: GoParser.ReceiverTypeContext):
        pass

    # Exit a parse tree produced by GoParser#receiverType.
    def exitReceiverType(self, ctx: GoParser.ReceiverTypeContext):
        pass

    # Enter a parse tree produced by GoParser#eoss.
    def enterEoss(self, ctx: GoParser.EossContext):
        pass

    # Exit a parse tree produced by GoParser#eoss.
    def exitEoss(self, ctx: GoParser.EossContext):
        pass

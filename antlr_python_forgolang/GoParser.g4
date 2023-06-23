/*
 [The "BSD licence"] Copyright (c) 2017 Sasa Coh, Michał Błotniak Copyright (c) 2019 Ivan Kochurkin,
 kvanttt@gmail.com, Positive Technologies Copyright (c) 2019 Dmitry Rassadin,
 flipparassa@gmail.com,Positive Technologies All rights reserved. Copyright (c) 2021 Martin Mirchev,
 mirchevmartin2203@gmail.com

 Redistribution and use in source and binary forms, with or without modification, are permitted
 provided that the following conditions are met: 1. Redistributions of source code must retain the
 above copyright notice, this list of conditions and the following disclaimer. 2. Redistributions in
 binary form must reproduce the above copyright notice, this list of conditions and the following
 disclaimer in the documentation and/or other materials provided with the distribution. 3. The name
 of the author may not be used to endorse or promote products derived from this software without
 specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * A Go grammar for ANTLR 4 derived from the Go Language Specification https://golang.org/ref/spec
 */

parser grammar GoParser;



options {
	tokenVocab = GoLexer;// import GoLexer;
	language = Cpp; //生成目标语言的代码
	// superClass = GoParserBase;
}

sourceFile:
	packageClause eoss* (importDecl eoss*)* //go语法开头package和import的块
											
	(
		( functionDecl  //函数声明
		| methodDecl    //方法声明
		| declaration   //普通声明
		) eoss*
	)* EOF;

packageClause: PACKAGE packageName = IDENTIFIER//关键字PACKAGE
; 

importDecl:
	IMPORT (importSpec | L_PAREN (importSpec eoss)* R_PAREN) //import下属的以括号包裹的多个包（可以为空），或者为没有括号包括的单个包
	;

importSpec: alias = (DOT | IDENTIFIER)? importPath //带点的多级引用，这个不是很清楚其中的作用
;

importPath: string_;

declaration: constDecl //常量声明 
			| typeDecl //结构体声明
			| varDecl  //变量声明
			;

constDecl: CONST (
				constSpec  //单一常量声明
				| L_PAREN (constSpec eoss)* R_PAREN  //多个常量声明
				);

constSpec: identifierList (type_? ASSIGN expressionList)? 
		//变量名 （变量类型） = 某个表达式
;

identifierList: IDENTIFIER (COMMA IDENTIFIER)* //变量链，可以用于连续赋值
;

expressionList: expression (COMMA expression)* //表达式链，用于计算值或者为左侧变量赋值
;
typeDecl: TYPE (typeSpec | L_PAREN (typeSpec eoss)* R_PAREN) //type类型名声明，用于创造类型和结构体等
;

typeSpec: IDENTIFIER ASSIGN? type_ //在type_中包含了如结构体声明等
;

// Function declarations

functionDecl: FUNC IDENTIFIER (signature block?);  //函数声明 FUNC即func，indentifier为函数名or变量名，signature为变量名加 返回值类型（可选），block为函数块（可选）

methodDecl: FUNC receiver IDENTIFIER ( signature block?) //方法声明，除了receiver引用同上
;

receiver: parameters //所以receiver就是一个位置不同的变量
;

varDecl: VAR (varSpec | L_PAREN (varSpec eoss)* R_PAREN) //变量声明，以var开头，同样可以用（）包裹多个变量
;

varSpec:
	identifierList (
		type_ (ASSIGN expressionList)?
		| ASSIGN expressionList
	) //变量声明的部分
;

block: L_CURLY eoss* statementList? R_CURLY //{}包裹的语句链条
;

statementList: (statement eoss+)+  //语句（多个语句）
;

statement:
	declaration
	| labeledStmt //类中参数赋值
	| simpleStmt //++ or --
	| goStmt
	| returnStmt
	| breakStmt
	| continueStmt
	| gotoStmt
	| fallthroughStmt
	| block
	| ifStmt
	| switchStmt
	| selectStmt
	| forStmt
	| deferStmt;

simpleStmt:
	sendStmt  //轻量级多线程接收
	| incDecStmt //++ or --
	| assignment
	| expressionStmt
	| shortVarDecl;

expressionStmt: expression;

sendStmt: channel = expression RECEIVE expression //轻量级多线程接收
;

incDecStmt: expression (PLUS_PLUS | MINUS_MINUS);

assignment: expressionList assign_op expressionList;

assign_op: (
		PLUS
		| MINUS
		| OR
		| CARET
		| STAR
		| DIV
		| MOD
		| LSHIFT
		| RSHIFT
		| AMPERSAND
		| BIT_CLEAR
	)? ASSIGN;

shortVarDecl: identifierList DECLARE_ASSIGN expressionList;

emptyStmt: EOSSS | SEMI;

labeledStmt: IDENTIFIER COLON statement? //类中某些参数的赋值手段
;

returnStmt: RETURN expressionList? //
;

breakStmt: BREAK IDENTIFIER?;

continueStmt: CONTINUE IDENTIFIER?;

gotoStmt: GOTO IDENTIFIER;

fallthroughStmt: FALLTHROUGH;

deferStmt: DEFER expression;

ifStmt:
	IF ( expression
			| eoss expression
			| simpleStmt eoss expression
			) block (
		ELSE (ifStmt | block)
	)?;

switchStmt: exprSwitchStmt | typeSwitchStmt;

exprSwitchStmt:
	SWITCH (expression?
					| simpleStmt? eoss expression?
					) L_CURLY exprCaseClause* R_CURLY;

exprCaseClause: exprSwitchCase COLON statementList?;

exprSwitchCase: CASE expressionList | DEFAULT;

typeSwitchStmt:
	SWITCH ( typeSwitchGuard
					| eoss typeSwitchGuard
					| simpleStmt eoss typeSwitchGuard)
					 L_CURLY typeCaseClause* R_CURLY;

typeSwitchGuard: (IDENTIFIER DECLARE_ASSIGN)? primaryExpr DOT L_PAREN TYPE R_PAREN;

typeCaseClause: typeSwitchCase COLON statementList?;

typeSwitchCase: CASE typeList | DEFAULT;

typeList: (type_ | NIL_LIT) (COMMA (type_ | NIL_LIT))*;

selectStmt: SELECT L_CURLY commClause* R_CURLY;

commClause: commCase COLON statementList?;

commCase: CASE (sendStmt | recvStmt) | DEFAULT;

recvStmt: (expressionList ASSIGN | identifierList DECLARE_ASSIGN)? recvExpr = expression;

forStmt: FOR (expression | forClause | rangeClause)? block;

forClause:
	initStmt = simpleStmt? eoss expression? eoss postStmt = simpleStmt?;

rangeClause: (
		expressionList ASSIGN
		| identifierList DECLARE_ASSIGN
	)? RANGE expression;

goStmt: GO expression;

type_: typeName | typeLit | L_PAREN type_ R_PAREN;

typeName: qualifiedIdent | IDENTIFIER;

typeLit:
	arrayType
	| structType
	| pointerType
	| functionType
	| interfaceType
	| sliceType
	| mapType
	| channelType;

arrayType: L_BRACKET arrayLength R_BRACKET elementType;

arrayLength: expression;

elementType: type_;

pointerType: STAR type_;

interfaceType:
	INTERFACE L_CURLY ((methodSpec | typeName) eoss)* R_CURLY;

sliceType: L_BRACKET R_BRACKET elementType;

// It's possible to replace `type` with more restricted typeLit list and also pay attention to nil maps
mapType: MAP L_BRACKET type_ R_BRACKET elementType;

channelType: (CHAN | CHAN RECEIVE | RECEIVE CHAN) elementType;

methodSpec:
	IDENTIFIER parameters result
	| IDENTIFIER parameters;

functionType: FUNC signature;

signature:  //函数的变量或对象的调用调用（一组或多组），与函数返回值的定义（可选）
	parameters result
	| parameters;

result: parameters | type_;

parameters:
	L_PAREN (parameterDecl (COMMA parameterDecl)* COMMA?)? R_PAREN //函数的变量调用（一组或多组）
	;

parameterDecl: identifierList? ELLIPSIS? type_ //函数的变量调用（一组）
;

expression:
	primaryExpr #PrimaryExpression
	| unary_op = (
		PLUS
		| MINUS
		| EXCLAMATION
		| CARET
		| STAR
		| AMPERSAND
		| RECEIVE
	) expression # UnaryOperation
	| expression mul_op = (
		STAR
		| DIV
		| MOD
		| LSHIFT
		| RSHIFT
		| AMPERSAND
		| BIT_CLEAR
	) expression #MulDivOperation
	| expression add_op = (PLUS | MINUS | OR | CARET) expression #PlusMinusOperation
	| expression rel_op = (
		EQUALS
		| NOT_EQUALS
		| LESS
		| LESS_OR_EQUALS
		| GREATER
		| GREATER_OR_EQUALS
	) expression #RelationOperation
	| expression LOGICAL_AND expression #LogicalAndOperation
	| expression LOGICAL_OR expression #LogicalOrOperation
	;

primaryExpr:
	operand
	| conversion
	| methodExpr
	| primaryExpr (
		(DOT IDENTIFIER)
		| index
		| slice_
		| typeAssertion
		| arguments
	);


conversion: nonNamedType L_PAREN expression COMMA? R_PAREN;

nonNamedType: typeLit | L_PAREN nonNamedType R_PAREN;

operand: literal | operandName | L_PAREN expression R_PAREN;

literal: basicLit | compositeLit | functionLit;

basicLit:
	NIL_LIT
	| integer
	| string_
	| FLOAT_LIT;

integer:
	DECIMAL_LIT
	| BINARY_LIT
	| OCTAL_LIT
	| HEX_LIT
	| IMAGINARY_LIT
	| RUNE_LIT;

operandName: IDENTIFIER;

qualifiedIdent: IDENTIFIER DOT IDENTIFIER;

compositeLit: literalType literalValue;

literalType:
	structType
	| arrayType
	| L_BRACKET ELLIPSIS R_BRACKET elementType
	| sliceType
	| mapType
	| typeName;

literalValue: L_CURLY (elementList COMMA?)? R_CURLY;

elementList: keyedElement (COMMA keyedElement)*;

keyedElement: (key COLON)? element;

key: expression | literalValue;

element: expression | literalValue;

structType: STRUCT L_CURLY (fieldDecl eoss)* R_CURLY;

fieldDecl: (
		identifierList type_
		| embeddedField
	) tag = string_?;

string_: 
		  RAW_STRING_LIT //原样字符串，由反引号包裹
		| INTERPRETED_STRING_LIT; //

embeddedField: STAR? typeName;

functionLit: FUNC signature block; // function

index: L_BRACKET expression R_BRACKET;

slice_:
	L_BRACKET (
		expression? COLON expression?
		| expression? COLON expression COLON expression
	) R_BRACKET;

typeAssertion: DOT L_PAREN type_ R_PAREN;

arguments:
	L_PAREN (
		(expressionList | nonNamedType (COMMA expressionList)?) ELLIPSIS? COMMA?
	)? R_PAREN;

methodExpr: nonNamedType DOT IDENTIFIER;

//receiverType: typeName | '(' ('*' typeName | receiverType) ')';

receiverType: type_; //不知道是什么，看起来没用上

eoss: //代表了一整个行终结符
	SEMI //;
	| EOSSS   //换行、分号、注释的开头结尾等
	| HUANHANG  //换行/n
	| HUANHANGG //超级换行/n/r
	// | {closingBracket()}?
	;



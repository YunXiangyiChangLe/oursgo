
// Generated from /home/aurora1/homework3/h3/grammar/GoParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "GoParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GoParser.
 */
class  GoParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSourceFile(GoParser::SourceFileContext *ctx) = 0;
  virtual void exitSourceFile(GoParser::SourceFileContext *ctx) = 0;

  virtual void enterPackageClause(GoParser::PackageClauseContext *ctx) = 0;
  virtual void exitPackageClause(GoParser::PackageClauseContext *ctx) = 0;

  virtual void enterImportDecl(GoParser::ImportDeclContext *ctx) = 0;
  virtual void exitImportDecl(GoParser::ImportDeclContext *ctx) = 0;

  virtual void enterImportSpec(GoParser::ImportSpecContext *ctx) = 0;
  virtual void exitImportSpec(GoParser::ImportSpecContext *ctx) = 0;

  virtual void enterImportPath(GoParser::ImportPathContext *ctx) = 0;
  virtual void exitImportPath(GoParser::ImportPathContext *ctx) = 0;

  virtual void enterDeclaration(GoParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(GoParser::DeclarationContext *ctx) = 0;

  virtual void enterConstDecl(GoParser::ConstDeclContext *ctx) = 0;
  virtual void exitConstDecl(GoParser::ConstDeclContext *ctx) = 0;

  virtual void enterConstSpec(GoParser::ConstSpecContext *ctx) = 0;
  virtual void exitConstSpec(GoParser::ConstSpecContext *ctx) = 0;

  virtual void enterIdentifierList(GoParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(GoParser::IdentifierListContext *ctx) = 0;

  virtual void enterExpressionList(GoParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(GoParser::ExpressionListContext *ctx) = 0;

  virtual void enterTypeDecl(GoParser::TypeDeclContext *ctx) = 0;
  virtual void exitTypeDecl(GoParser::TypeDeclContext *ctx) = 0;

  virtual void enterTypeSpec(GoParser::TypeSpecContext *ctx) = 0;
  virtual void exitTypeSpec(GoParser::TypeSpecContext *ctx) = 0;

  virtual void enterFunctionDecl(GoParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(GoParser::FunctionDeclContext *ctx) = 0;

  virtual void enterMethodDecl(GoParser::MethodDeclContext *ctx) = 0;
  virtual void exitMethodDecl(GoParser::MethodDeclContext *ctx) = 0;

  virtual void enterReceiver(GoParser::ReceiverContext *ctx) = 0;
  virtual void exitReceiver(GoParser::ReceiverContext *ctx) = 0;

  virtual void enterVarDecl(GoParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(GoParser::VarDeclContext *ctx) = 0;

  virtual void enterVarSpec(GoParser::VarSpecContext *ctx) = 0;
  virtual void exitVarSpec(GoParser::VarSpecContext *ctx) = 0;

  virtual void enterBlock(GoParser::BlockContext *ctx) = 0;
  virtual void exitBlock(GoParser::BlockContext *ctx) = 0;

  virtual void enterStatementList(GoParser::StatementListContext *ctx) = 0;
  virtual void exitStatementList(GoParser::StatementListContext *ctx) = 0;

  virtual void enterStatement(GoParser::StatementContext *ctx) = 0;
  virtual void exitStatement(GoParser::StatementContext *ctx) = 0;

  virtual void enterSimpleStmt(GoParser::SimpleStmtContext *ctx) = 0;
  virtual void exitSimpleStmt(GoParser::SimpleStmtContext *ctx) = 0;

  virtual void enterExpressionStmt(GoParser::ExpressionStmtContext *ctx) = 0;
  virtual void exitExpressionStmt(GoParser::ExpressionStmtContext *ctx) = 0;

  virtual void enterSendStmt(GoParser::SendStmtContext *ctx) = 0;
  virtual void exitSendStmt(GoParser::SendStmtContext *ctx) = 0;

  virtual void enterIncDecStmt(GoParser::IncDecStmtContext *ctx) = 0;
  virtual void exitIncDecStmt(GoParser::IncDecStmtContext *ctx) = 0;

  virtual void enterAssignment(GoParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(GoParser::AssignmentContext *ctx) = 0;

  virtual void enterAssign_op(GoParser::Assign_opContext *ctx) = 0;
  virtual void exitAssign_op(GoParser::Assign_opContext *ctx) = 0;

  virtual void enterShortVarDecl(GoParser::ShortVarDeclContext *ctx) = 0;
  virtual void exitShortVarDecl(GoParser::ShortVarDeclContext *ctx) = 0;

  virtual void enterEmptyStmt(GoParser::EmptyStmtContext *ctx) = 0;
  virtual void exitEmptyStmt(GoParser::EmptyStmtContext *ctx) = 0;

  virtual void enterLabeledStmt(GoParser::LabeledStmtContext *ctx) = 0;
  virtual void exitLabeledStmt(GoParser::LabeledStmtContext *ctx) = 0;

  virtual void enterReturnStmt(GoParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(GoParser::ReturnStmtContext *ctx) = 0;

  virtual void enterBreakStmt(GoParser::BreakStmtContext *ctx) = 0;
  virtual void exitBreakStmt(GoParser::BreakStmtContext *ctx) = 0;

  virtual void enterContinueStmt(GoParser::ContinueStmtContext *ctx) = 0;
  virtual void exitContinueStmt(GoParser::ContinueStmtContext *ctx) = 0;

  virtual void enterGotoStmt(GoParser::GotoStmtContext *ctx) = 0;
  virtual void exitGotoStmt(GoParser::GotoStmtContext *ctx) = 0;

  virtual void enterFallthroughStmt(GoParser::FallthroughStmtContext *ctx) = 0;
  virtual void exitFallthroughStmt(GoParser::FallthroughStmtContext *ctx) = 0;

  virtual void enterDeferStmt(GoParser::DeferStmtContext *ctx) = 0;
  virtual void exitDeferStmt(GoParser::DeferStmtContext *ctx) = 0;

  virtual void enterIfStmt(GoParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(GoParser::IfStmtContext *ctx) = 0;

  virtual void enterSwitchStmt(GoParser::SwitchStmtContext *ctx) = 0;
  virtual void exitSwitchStmt(GoParser::SwitchStmtContext *ctx) = 0;

  virtual void enterExprSwitchStmt(GoParser::ExprSwitchStmtContext *ctx) = 0;
  virtual void exitExprSwitchStmt(GoParser::ExprSwitchStmtContext *ctx) = 0;

  virtual void enterExprCaseClause(GoParser::ExprCaseClauseContext *ctx) = 0;
  virtual void exitExprCaseClause(GoParser::ExprCaseClauseContext *ctx) = 0;

  virtual void enterExprSwitchCase(GoParser::ExprSwitchCaseContext *ctx) = 0;
  virtual void exitExprSwitchCase(GoParser::ExprSwitchCaseContext *ctx) = 0;

  virtual void enterTypeSwitchStmt(GoParser::TypeSwitchStmtContext *ctx) = 0;
  virtual void exitTypeSwitchStmt(GoParser::TypeSwitchStmtContext *ctx) = 0;

  virtual void enterTypeSwitchGuard(GoParser::TypeSwitchGuardContext *ctx) = 0;
  virtual void exitTypeSwitchGuard(GoParser::TypeSwitchGuardContext *ctx) = 0;

  virtual void enterTypeCaseClause(GoParser::TypeCaseClauseContext *ctx) = 0;
  virtual void exitTypeCaseClause(GoParser::TypeCaseClauseContext *ctx) = 0;

  virtual void enterTypeSwitchCase(GoParser::TypeSwitchCaseContext *ctx) = 0;
  virtual void exitTypeSwitchCase(GoParser::TypeSwitchCaseContext *ctx) = 0;

  virtual void enterTypeList(GoParser::TypeListContext *ctx) = 0;
  virtual void exitTypeList(GoParser::TypeListContext *ctx) = 0;

  virtual void enterSelectStmt(GoParser::SelectStmtContext *ctx) = 0;
  virtual void exitSelectStmt(GoParser::SelectStmtContext *ctx) = 0;

  virtual void enterCommClause(GoParser::CommClauseContext *ctx) = 0;
  virtual void exitCommClause(GoParser::CommClauseContext *ctx) = 0;

  virtual void enterCommCase(GoParser::CommCaseContext *ctx) = 0;
  virtual void exitCommCase(GoParser::CommCaseContext *ctx) = 0;

  virtual void enterRecvStmt(GoParser::RecvStmtContext *ctx) = 0;
  virtual void exitRecvStmt(GoParser::RecvStmtContext *ctx) = 0;

  virtual void enterForStmt(GoParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(GoParser::ForStmtContext *ctx) = 0;

  virtual void enterForClause(GoParser::ForClauseContext *ctx) = 0;
  virtual void exitForClause(GoParser::ForClauseContext *ctx) = 0;

  virtual void enterRangeClause(GoParser::RangeClauseContext *ctx) = 0;
  virtual void exitRangeClause(GoParser::RangeClauseContext *ctx) = 0;

  virtual void enterGoStmt(GoParser::GoStmtContext *ctx) = 0;
  virtual void exitGoStmt(GoParser::GoStmtContext *ctx) = 0;

  virtual void enterType_(GoParser::Type_Context *ctx) = 0;
  virtual void exitType_(GoParser::Type_Context *ctx) = 0;

  virtual void enterTypeName(GoParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(GoParser::TypeNameContext *ctx) = 0;

  virtual void enterTypeLit(GoParser::TypeLitContext *ctx) = 0;
  virtual void exitTypeLit(GoParser::TypeLitContext *ctx) = 0;

  virtual void enterArrayType(GoParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(GoParser::ArrayTypeContext *ctx) = 0;

  virtual void enterArrayLength(GoParser::ArrayLengthContext *ctx) = 0;
  virtual void exitArrayLength(GoParser::ArrayLengthContext *ctx) = 0;

  virtual void enterElementType(GoParser::ElementTypeContext *ctx) = 0;
  virtual void exitElementType(GoParser::ElementTypeContext *ctx) = 0;

  virtual void enterPointerType(GoParser::PointerTypeContext *ctx) = 0;
  virtual void exitPointerType(GoParser::PointerTypeContext *ctx) = 0;

  virtual void enterInterfaceType(GoParser::InterfaceTypeContext *ctx) = 0;
  virtual void exitInterfaceType(GoParser::InterfaceTypeContext *ctx) = 0;

  virtual void enterSliceType(GoParser::SliceTypeContext *ctx) = 0;
  virtual void exitSliceType(GoParser::SliceTypeContext *ctx) = 0;

  virtual void enterMapType(GoParser::MapTypeContext *ctx) = 0;
  virtual void exitMapType(GoParser::MapTypeContext *ctx) = 0;

  virtual void enterChannelType(GoParser::ChannelTypeContext *ctx) = 0;
  virtual void exitChannelType(GoParser::ChannelTypeContext *ctx) = 0;

  virtual void enterMethodSpec(GoParser::MethodSpecContext *ctx) = 0;
  virtual void exitMethodSpec(GoParser::MethodSpecContext *ctx) = 0;

  virtual void enterFunctionType(GoParser::FunctionTypeContext *ctx) = 0;
  virtual void exitFunctionType(GoParser::FunctionTypeContext *ctx) = 0;

  virtual void enterSignature(GoParser::SignatureContext *ctx) = 0;
  virtual void exitSignature(GoParser::SignatureContext *ctx) = 0;

  virtual void enterResult(GoParser::ResultContext *ctx) = 0;
  virtual void exitResult(GoParser::ResultContext *ctx) = 0;

  virtual void enterParameters(GoParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(GoParser::ParametersContext *ctx) = 0;

  virtual void enterParameterDecl(GoParser::ParameterDeclContext *ctx) = 0;
  virtual void exitParameterDecl(GoParser::ParameterDeclContext *ctx) = 0;

  virtual void enterLogicalAndOperation(GoParser::LogicalAndOperationContext *ctx) = 0;
  virtual void exitLogicalAndOperation(GoParser::LogicalAndOperationContext *ctx) = 0;

  virtual void enterUnaryOperation(GoParser::UnaryOperationContext *ctx) = 0;
  virtual void exitUnaryOperation(GoParser::UnaryOperationContext *ctx) = 0;

  virtual void enterPrimaryExpression(GoParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(GoParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterPlusMinusOperation(GoParser::PlusMinusOperationContext *ctx) = 0;
  virtual void exitPlusMinusOperation(GoParser::PlusMinusOperationContext *ctx) = 0;

  virtual void enterRelationOperation(GoParser::RelationOperationContext *ctx) = 0;
  virtual void exitRelationOperation(GoParser::RelationOperationContext *ctx) = 0;

  virtual void enterMulDivOperation(GoParser::MulDivOperationContext *ctx) = 0;
  virtual void exitMulDivOperation(GoParser::MulDivOperationContext *ctx) = 0;

  virtual void enterLogicalOrOperation(GoParser::LogicalOrOperationContext *ctx) = 0;
  virtual void exitLogicalOrOperation(GoParser::LogicalOrOperationContext *ctx) = 0;

  virtual void enterPrimaryExpr(GoParser::PrimaryExprContext *ctx) = 0;
  virtual void exitPrimaryExpr(GoParser::PrimaryExprContext *ctx) = 0;

  virtual void enterConversion(GoParser::ConversionContext *ctx) = 0;
  virtual void exitConversion(GoParser::ConversionContext *ctx) = 0;

  virtual void enterNonNamedType(GoParser::NonNamedTypeContext *ctx) = 0;
  virtual void exitNonNamedType(GoParser::NonNamedTypeContext *ctx) = 0;

  virtual void enterOperand(GoParser::OperandContext *ctx) = 0;
  virtual void exitOperand(GoParser::OperandContext *ctx) = 0;

  virtual void enterLiteral(GoParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(GoParser::LiteralContext *ctx) = 0;

  virtual void enterBasicLit(GoParser::BasicLitContext *ctx) = 0;
  virtual void exitBasicLit(GoParser::BasicLitContext *ctx) = 0;

  virtual void enterInteger(GoParser::IntegerContext *ctx) = 0;
  virtual void exitInteger(GoParser::IntegerContext *ctx) = 0;

  virtual void enterOperandName(GoParser::OperandNameContext *ctx) = 0;
  virtual void exitOperandName(GoParser::OperandNameContext *ctx) = 0;

  virtual void enterQualifiedIdent(GoParser::QualifiedIdentContext *ctx) = 0;
  virtual void exitQualifiedIdent(GoParser::QualifiedIdentContext *ctx) = 0;

  virtual void enterCompositeLit(GoParser::CompositeLitContext *ctx) = 0;
  virtual void exitCompositeLit(GoParser::CompositeLitContext *ctx) = 0;

  virtual void enterLiteralType(GoParser::LiteralTypeContext *ctx) = 0;
  virtual void exitLiteralType(GoParser::LiteralTypeContext *ctx) = 0;

  virtual void enterLiteralValue(GoParser::LiteralValueContext *ctx) = 0;
  virtual void exitLiteralValue(GoParser::LiteralValueContext *ctx) = 0;

  virtual void enterElementList(GoParser::ElementListContext *ctx) = 0;
  virtual void exitElementList(GoParser::ElementListContext *ctx) = 0;

  virtual void enterKeyedElement(GoParser::KeyedElementContext *ctx) = 0;
  virtual void exitKeyedElement(GoParser::KeyedElementContext *ctx) = 0;

  virtual void enterKey(GoParser::KeyContext *ctx) = 0;
  virtual void exitKey(GoParser::KeyContext *ctx) = 0;

  virtual void enterElement(GoParser::ElementContext *ctx) = 0;
  virtual void exitElement(GoParser::ElementContext *ctx) = 0;

  virtual void enterStructType(GoParser::StructTypeContext *ctx) = 0;
  virtual void exitStructType(GoParser::StructTypeContext *ctx) = 0;

  virtual void enterFieldDecl(GoParser::FieldDeclContext *ctx) = 0;
  virtual void exitFieldDecl(GoParser::FieldDeclContext *ctx) = 0;

  virtual void enterString_(GoParser::String_Context *ctx) = 0;
  virtual void exitString_(GoParser::String_Context *ctx) = 0;

  virtual void enterEmbeddedField(GoParser::EmbeddedFieldContext *ctx) = 0;
  virtual void exitEmbeddedField(GoParser::EmbeddedFieldContext *ctx) = 0;

  virtual void enterFunctionLit(GoParser::FunctionLitContext *ctx) = 0;
  virtual void exitFunctionLit(GoParser::FunctionLitContext *ctx) = 0;

  virtual void enterIndex(GoParser::IndexContext *ctx) = 0;
  virtual void exitIndex(GoParser::IndexContext *ctx) = 0;

  virtual void enterSlice_(GoParser::Slice_Context *ctx) = 0;
  virtual void exitSlice_(GoParser::Slice_Context *ctx) = 0;

  virtual void enterTypeAssertion(GoParser::TypeAssertionContext *ctx) = 0;
  virtual void exitTypeAssertion(GoParser::TypeAssertionContext *ctx) = 0;

  virtual void enterArguments(GoParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(GoParser::ArgumentsContext *ctx) = 0;

  virtual void enterMethodExpr(GoParser::MethodExprContext *ctx) = 0;
  virtual void exitMethodExpr(GoParser::MethodExprContext *ctx) = 0;

  virtual void enterReceiverType(GoParser::ReceiverTypeContext *ctx) = 0;
  virtual void exitReceiverType(GoParser::ReceiverTypeContext *ctx) = 0;

  virtual void enterEoss(GoParser::EossContext *ctx) = 0;
  virtual void exitEoss(GoParser::EossContext *ctx) = 0;


};


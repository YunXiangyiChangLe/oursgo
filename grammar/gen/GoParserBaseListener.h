
// Generated from /home/aurora1/homework3/h3/grammar/GoParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "GoParserListener.h"


/**
 * This class provides an empty implementation of GoParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GoParserBaseListener : public GoParserListener {
public:

  virtual void enterSourceFile(GoParser::SourceFileContext * /*ctx*/) override { }
  virtual void exitSourceFile(GoParser::SourceFileContext * /*ctx*/) override { }

  virtual void enterPackageClause(GoParser::PackageClauseContext * /*ctx*/) override { }
  virtual void exitPackageClause(GoParser::PackageClauseContext * /*ctx*/) override { }

  virtual void enterImportDecl(GoParser::ImportDeclContext * /*ctx*/) override { }
  virtual void exitImportDecl(GoParser::ImportDeclContext * /*ctx*/) override { }

  virtual void enterImportSpec(GoParser::ImportSpecContext * /*ctx*/) override { }
  virtual void exitImportSpec(GoParser::ImportSpecContext * /*ctx*/) override { }

  virtual void enterImportPath(GoParser::ImportPathContext * /*ctx*/) override { }
  virtual void exitImportPath(GoParser::ImportPathContext * /*ctx*/) override { }

  virtual void enterDeclaration(GoParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(GoParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterConstDecl(GoParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(GoParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterConstSpec(GoParser::ConstSpecContext * /*ctx*/) override { }
  virtual void exitConstSpec(GoParser::ConstSpecContext * /*ctx*/) override { }

  virtual void enterIdentifierList(GoParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(GoParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterExpressionList(GoParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(GoParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterTypeDecl(GoParser::TypeDeclContext * /*ctx*/) override { }
  virtual void exitTypeDecl(GoParser::TypeDeclContext * /*ctx*/) override { }

  virtual void enterTypeSpec(GoParser::TypeSpecContext * /*ctx*/) override { }
  virtual void exitTypeSpec(GoParser::TypeSpecContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(GoParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(GoParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterMethodDecl(GoParser::MethodDeclContext * /*ctx*/) override { }
  virtual void exitMethodDecl(GoParser::MethodDeclContext * /*ctx*/) override { }

  virtual void enterReceiver(GoParser::ReceiverContext * /*ctx*/) override { }
  virtual void exitReceiver(GoParser::ReceiverContext * /*ctx*/) override { }

  virtual void enterVarDecl(GoParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(GoParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarSpec(GoParser::VarSpecContext * /*ctx*/) override { }
  virtual void exitVarSpec(GoParser::VarSpecContext * /*ctx*/) override { }

  virtual void enterBlock(GoParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(GoParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatementList(GoParser::StatementListContext * /*ctx*/) override { }
  virtual void exitStatementList(GoParser::StatementListContext * /*ctx*/) override { }

  virtual void enterStatement(GoParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(GoParser::StatementContext * /*ctx*/) override { }

  virtual void enterSimpleStmt(GoParser::SimpleStmtContext * /*ctx*/) override { }
  virtual void exitSimpleStmt(GoParser::SimpleStmtContext * /*ctx*/) override { }

  virtual void enterExpressionStmt(GoParser::ExpressionStmtContext * /*ctx*/) override { }
  virtual void exitExpressionStmt(GoParser::ExpressionStmtContext * /*ctx*/) override { }

  virtual void enterSendStmt(GoParser::SendStmtContext * /*ctx*/) override { }
  virtual void exitSendStmt(GoParser::SendStmtContext * /*ctx*/) override { }

  virtual void enterIncDecStmt(GoParser::IncDecStmtContext * /*ctx*/) override { }
  virtual void exitIncDecStmt(GoParser::IncDecStmtContext * /*ctx*/) override { }

  virtual void enterAssignment(GoParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(GoParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterAssign_op(GoParser::Assign_opContext * /*ctx*/) override { }
  virtual void exitAssign_op(GoParser::Assign_opContext * /*ctx*/) override { }

  virtual void enterShortVarDecl(GoParser::ShortVarDeclContext * /*ctx*/) override { }
  virtual void exitShortVarDecl(GoParser::ShortVarDeclContext * /*ctx*/) override { }

  virtual void enterEmptyStmt(GoParser::EmptyStmtContext * /*ctx*/) override { }
  virtual void exitEmptyStmt(GoParser::EmptyStmtContext * /*ctx*/) override { }

  virtual void enterLabeledStmt(GoParser::LabeledStmtContext * /*ctx*/) override { }
  virtual void exitLabeledStmt(GoParser::LabeledStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(GoParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(GoParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterBreakStmt(GoParser::BreakStmtContext * /*ctx*/) override { }
  virtual void exitBreakStmt(GoParser::BreakStmtContext * /*ctx*/) override { }

  virtual void enterContinueStmt(GoParser::ContinueStmtContext * /*ctx*/) override { }
  virtual void exitContinueStmt(GoParser::ContinueStmtContext * /*ctx*/) override { }

  virtual void enterGotoStmt(GoParser::GotoStmtContext * /*ctx*/) override { }
  virtual void exitGotoStmt(GoParser::GotoStmtContext * /*ctx*/) override { }

  virtual void enterFallthroughStmt(GoParser::FallthroughStmtContext * /*ctx*/) override { }
  virtual void exitFallthroughStmt(GoParser::FallthroughStmtContext * /*ctx*/) override { }

  virtual void enterDeferStmt(GoParser::DeferStmtContext * /*ctx*/) override { }
  virtual void exitDeferStmt(GoParser::DeferStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(GoParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(GoParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterSwitchStmt(GoParser::SwitchStmtContext * /*ctx*/) override { }
  virtual void exitSwitchStmt(GoParser::SwitchStmtContext * /*ctx*/) override { }

  virtual void enterExprSwitchStmt(GoParser::ExprSwitchStmtContext * /*ctx*/) override { }
  virtual void exitExprSwitchStmt(GoParser::ExprSwitchStmtContext * /*ctx*/) override { }

  virtual void enterExprCaseClause(GoParser::ExprCaseClauseContext * /*ctx*/) override { }
  virtual void exitExprCaseClause(GoParser::ExprCaseClauseContext * /*ctx*/) override { }

  virtual void enterExprSwitchCase(GoParser::ExprSwitchCaseContext * /*ctx*/) override { }
  virtual void exitExprSwitchCase(GoParser::ExprSwitchCaseContext * /*ctx*/) override { }

  virtual void enterTypeSwitchStmt(GoParser::TypeSwitchStmtContext * /*ctx*/) override { }
  virtual void exitTypeSwitchStmt(GoParser::TypeSwitchStmtContext * /*ctx*/) override { }

  virtual void enterTypeSwitchGuard(GoParser::TypeSwitchGuardContext * /*ctx*/) override { }
  virtual void exitTypeSwitchGuard(GoParser::TypeSwitchGuardContext * /*ctx*/) override { }

  virtual void enterTypeCaseClause(GoParser::TypeCaseClauseContext * /*ctx*/) override { }
  virtual void exitTypeCaseClause(GoParser::TypeCaseClauseContext * /*ctx*/) override { }

  virtual void enterTypeSwitchCase(GoParser::TypeSwitchCaseContext * /*ctx*/) override { }
  virtual void exitTypeSwitchCase(GoParser::TypeSwitchCaseContext * /*ctx*/) override { }

  virtual void enterTypeList(GoParser::TypeListContext * /*ctx*/) override { }
  virtual void exitTypeList(GoParser::TypeListContext * /*ctx*/) override { }

  virtual void enterSelectStmt(GoParser::SelectStmtContext * /*ctx*/) override { }
  virtual void exitSelectStmt(GoParser::SelectStmtContext * /*ctx*/) override { }

  virtual void enterCommClause(GoParser::CommClauseContext * /*ctx*/) override { }
  virtual void exitCommClause(GoParser::CommClauseContext * /*ctx*/) override { }

  virtual void enterCommCase(GoParser::CommCaseContext * /*ctx*/) override { }
  virtual void exitCommCase(GoParser::CommCaseContext * /*ctx*/) override { }

  virtual void enterRecvStmt(GoParser::RecvStmtContext * /*ctx*/) override { }
  virtual void exitRecvStmt(GoParser::RecvStmtContext * /*ctx*/) override { }

  virtual void enterForStmt(GoParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(GoParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterForClause(GoParser::ForClauseContext * /*ctx*/) override { }
  virtual void exitForClause(GoParser::ForClauseContext * /*ctx*/) override { }

  virtual void enterRangeClause(GoParser::RangeClauseContext * /*ctx*/) override { }
  virtual void exitRangeClause(GoParser::RangeClauseContext * /*ctx*/) override { }

  virtual void enterGoStmt(GoParser::GoStmtContext * /*ctx*/) override { }
  virtual void exitGoStmt(GoParser::GoStmtContext * /*ctx*/) override { }

  virtual void enterType_(GoParser::Type_Context * /*ctx*/) override { }
  virtual void exitType_(GoParser::Type_Context * /*ctx*/) override { }

  virtual void enterTypeName(GoParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(GoParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterTypeLit(GoParser::TypeLitContext * /*ctx*/) override { }
  virtual void exitTypeLit(GoParser::TypeLitContext * /*ctx*/) override { }

  virtual void enterArrayType(GoParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(GoParser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterArrayLength(GoParser::ArrayLengthContext * /*ctx*/) override { }
  virtual void exitArrayLength(GoParser::ArrayLengthContext * /*ctx*/) override { }

  virtual void enterElementType(GoParser::ElementTypeContext * /*ctx*/) override { }
  virtual void exitElementType(GoParser::ElementTypeContext * /*ctx*/) override { }

  virtual void enterPointerType(GoParser::PointerTypeContext * /*ctx*/) override { }
  virtual void exitPointerType(GoParser::PointerTypeContext * /*ctx*/) override { }

  virtual void enterInterfaceType(GoParser::InterfaceTypeContext * /*ctx*/) override { }
  virtual void exitInterfaceType(GoParser::InterfaceTypeContext * /*ctx*/) override { }

  virtual void enterSliceType(GoParser::SliceTypeContext * /*ctx*/) override { }
  virtual void exitSliceType(GoParser::SliceTypeContext * /*ctx*/) override { }

  virtual void enterMapType(GoParser::MapTypeContext * /*ctx*/) override { }
  virtual void exitMapType(GoParser::MapTypeContext * /*ctx*/) override { }

  virtual void enterChannelType(GoParser::ChannelTypeContext * /*ctx*/) override { }
  virtual void exitChannelType(GoParser::ChannelTypeContext * /*ctx*/) override { }

  virtual void enterMethodSpec(GoParser::MethodSpecContext * /*ctx*/) override { }
  virtual void exitMethodSpec(GoParser::MethodSpecContext * /*ctx*/) override { }

  virtual void enterFunctionType(GoParser::FunctionTypeContext * /*ctx*/) override { }
  virtual void exitFunctionType(GoParser::FunctionTypeContext * /*ctx*/) override { }

  virtual void enterSignature(GoParser::SignatureContext * /*ctx*/) override { }
  virtual void exitSignature(GoParser::SignatureContext * /*ctx*/) override { }

  virtual void enterResult(GoParser::ResultContext * /*ctx*/) override { }
  virtual void exitResult(GoParser::ResultContext * /*ctx*/) override { }

  virtual void enterParameters(GoParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(GoParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParameterDecl(GoParser::ParameterDeclContext * /*ctx*/) override { }
  virtual void exitParameterDecl(GoParser::ParameterDeclContext * /*ctx*/) override { }

  virtual void enterLogicalAndOperation(GoParser::LogicalAndOperationContext * /*ctx*/) override { }
  virtual void exitLogicalAndOperation(GoParser::LogicalAndOperationContext * /*ctx*/) override { }

  virtual void enterUnaryOperation(GoParser::UnaryOperationContext * /*ctx*/) override { }
  virtual void exitUnaryOperation(GoParser::UnaryOperationContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(GoParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(GoParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterPlusMinusOperation(GoParser::PlusMinusOperationContext * /*ctx*/) override { }
  virtual void exitPlusMinusOperation(GoParser::PlusMinusOperationContext * /*ctx*/) override { }

  virtual void enterRelationOperation(GoParser::RelationOperationContext * /*ctx*/) override { }
  virtual void exitRelationOperation(GoParser::RelationOperationContext * /*ctx*/) override { }

  virtual void enterMulDivOperation(GoParser::MulDivOperationContext * /*ctx*/) override { }
  virtual void exitMulDivOperation(GoParser::MulDivOperationContext * /*ctx*/) override { }

  virtual void enterLogicalOrOperation(GoParser::LogicalOrOperationContext * /*ctx*/) override { }
  virtual void exitLogicalOrOperation(GoParser::LogicalOrOperationContext * /*ctx*/) override { }

  virtual void enterPrimaryExpr(GoParser::PrimaryExprContext * /*ctx*/) override { }
  virtual void exitPrimaryExpr(GoParser::PrimaryExprContext * /*ctx*/) override { }

  virtual void enterConversion(GoParser::ConversionContext * /*ctx*/) override { }
  virtual void exitConversion(GoParser::ConversionContext * /*ctx*/) override { }

  virtual void enterNonNamedType(GoParser::NonNamedTypeContext * /*ctx*/) override { }
  virtual void exitNonNamedType(GoParser::NonNamedTypeContext * /*ctx*/) override { }

  virtual void enterOperand(GoParser::OperandContext * /*ctx*/) override { }
  virtual void exitOperand(GoParser::OperandContext * /*ctx*/) override { }

  virtual void enterLiteral(GoParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(GoParser::LiteralContext * /*ctx*/) override { }

  virtual void enterBasicLit(GoParser::BasicLitContext * /*ctx*/) override { }
  virtual void exitBasicLit(GoParser::BasicLitContext * /*ctx*/) override { }

  virtual void enterInteger(GoParser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(GoParser::IntegerContext * /*ctx*/) override { }

  virtual void enterOperandName(GoParser::OperandNameContext * /*ctx*/) override { }
  virtual void exitOperandName(GoParser::OperandNameContext * /*ctx*/) override { }

  virtual void enterQualifiedIdent(GoParser::QualifiedIdentContext * /*ctx*/) override { }
  virtual void exitQualifiedIdent(GoParser::QualifiedIdentContext * /*ctx*/) override { }

  virtual void enterCompositeLit(GoParser::CompositeLitContext * /*ctx*/) override { }
  virtual void exitCompositeLit(GoParser::CompositeLitContext * /*ctx*/) override { }

  virtual void enterLiteralType(GoParser::LiteralTypeContext * /*ctx*/) override { }
  virtual void exitLiteralType(GoParser::LiteralTypeContext * /*ctx*/) override { }

  virtual void enterLiteralValue(GoParser::LiteralValueContext * /*ctx*/) override { }
  virtual void exitLiteralValue(GoParser::LiteralValueContext * /*ctx*/) override { }

  virtual void enterElementList(GoParser::ElementListContext * /*ctx*/) override { }
  virtual void exitElementList(GoParser::ElementListContext * /*ctx*/) override { }

  virtual void enterKeyedElement(GoParser::KeyedElementContext * /*ctx*/) override { }
  virtual void exitKeyedElement(GoParser::KeyedElementContext * /*ctx*/) override { }

  virtual void enterKey(GoParser::KeyContext * /*ctx*/) override { }
  virtual void exitKey(GoParser::KeyContext * /*ctx*/) override { }

  virtual void enterElement(GoParser::ElementContext * /*ctx*/) override { }
  virtual void exitElement(GoParser::ElementContext * /*ctx*/) override { }

  virtual void enterStructType(GoParser::StructTypeContext * /*ctx*/) override { }
  virtual void exitStructType(GoParser::StructTypeContext * /*ctx*/) override { }

  virtual void enterFieldDecl(GoParser::FieldDeclContext * /*ctx*/) override { }
  virtual void exitFieldDecl(GoParser::FieldDeclContext * /*ctx*/) override { }

  virtual void enterString_(GoParser::String_Context * /*ctx*/) override { }
  virtual void exitString_(GoParser::String_Context * /*ctx*/) override { }

  virtual void enterEmbeddedField(GoParser::EmbeddedFieldContext * /*ctx*/) override { }
  virtual void exitEmbeddedField(GoParser::EmbeddedFieldContext * /*ctx*/) override { }

  virtual void enterFunctionLit(GoParser::FunctionLitContext * /*ctx*/) override { }
  virtual void exitFunctionLit(GoParser::FunctionLitContext * /*ctx*/) override { }

  virtual void enterIndex(GoParser::IndexContext * /*ctx*/) override { }
  virtual void exitIndex(GoParser::IndexContext * /*ctx*/) override { }

  virtual void enterSlice_(GoParser::Slice_Context * /*ctx*/) override { }
  virtual void exitSlice_(GoParser::Slice_Context * /*ctx*/) override { }

  virtual void enterTypeAssertion(GoParser::TypeAssertionContext * /*ctx*/) override { }
  virtual void exitTypeAssertion(GoParser::TypeAssertionContext * /*ctx*/) override { }

  virtual void enterArguments(GoParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(GoParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterMethodExpr(GoParser::MethodExprContext * /*ctx*/) override { }
  virtual void exitMethodExpr(GoParser::MethodExprContext * /*ctx*/) override { }

  virtual void enterReceiverType(GoParser::ReceiverTypeContext * /*ctx*/) override { }
  virtual void exitReceiverType(GoParser::ReceiverTypeContext * /*ctx*/) override { }

  virtual void enterEoss(GoParser::EossContext * /*ctx*/) override { }
  virtual void exitEoss(GoParser::EossContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


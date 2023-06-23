
// Generated from /home/aurora1/homework3/h3/grammar/GoLexer.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  GoLexer : public antlr4::Lexer {
public:
  enum {
    BREAK = 1, DEFAULT = 2, FUNC = 3, INTERFACE = 4, SELECT = 5, CASE = 6, 
    DEFER = 7, GO = 8, MAP = 9, STRUCT = 10, CHAN = 11, ELSE = 12, GOTO = 13, 
    PACKAGE = 14, SWITCH = 15, CONST = 16, FALLTHROUGH = 17, IF = 18, RANGE = 19, 
    TYPE = 20, CONTINUE = 21, FOR = 22, IMPORT = 23, RETURN = 24, VAR = 25, 
    NIL_LIT = 26, IDENTIFIER = 27, L_PAREN = 28, R_PAREN = 29, L_CURLY = 30, 
    R_CURLY = 31, L_BRACKET = 32, R_BRACKET = 33, ASSIGN = 34, COMMA = 35, 
    SEMI = 36, HUANHANG = 37, HUANHANGG = 38, COLON = 39, DOT = 40, PLUS_PLUS = 41, 
    MINUS_MINUS = 42, DECLARE_ASSIGN = 43, ELLIPSIS = 44, EOSSS = 45, LOGICAL_OR = 46, 
    LOGICAL_AND = 47, EQUALS = 48, NOT_EQUALS = 49, LESS = 50, LESS_OR_EQUALS = 51, 
    GREATER = 52, GREATER_OR_EQUALS = 53, OR = 54, DIV = 55, MOD = 56, LSHIFT = 57, 
    RSHIFT = 58, BIT_CLEAR = 59, EXCLAMATION = 60, PLUS = 61, MINUS = 62, 
    CARET = 63, STAR = 64, AMPERSAND = 65, RECEIVE = 66, DECIMAL_LIT = 67, 
    BINARY_LIT = 68, OCTAL_LIT = 69, HEX_LIT = 70, FLOAT_LIT = 71, DECIMAL_FLOAT_LIT = 72, 
    HEX_FLOAT_LIT = 73, IMAGINARY_LIT = 74, RUNE_LIT = 75, BYTE_VALUE = 76, 
    OCTAL_BYTE_VALUE = 77, HEX_BYTE_VALUE = 78, LITTLE_U_VALUE = 79, BIG_U_VALUE = 80, 
    RAW_STRING_LIT = 81, INTERPRETED_STRING_LIT = 82, WS = 83, COMMENT = 84, 
    TERMINATOR = 85, LINE_COMMENT = 86, WS_NLSEMI = 87, COMMENT_NLSEMI = 88, 
    LINE_COMMENT_NLSEMI = 89
  };

  enum {
    NLSEMI = 1
  };

  explicit GoLexer(antlr4::CharStream *input);
  ~GoLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};


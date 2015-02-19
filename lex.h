#pragma once

#include "Symbol.h"
#include "SymbolTable.h"
#include "AstNode.h"
#include "PrintNode.h"
#include "StmtsNode.h"
#include "BlockNode.h"
#include "FloatNode.h"
#include "IntNode.h"
#include "ExprNode.h"
#include "VarRef.h"
#include "BinaryExprNode.h"
#include "DeclsNode.h"
#include "VarDecl.h"
#include "ParamsNode.h"
#include "FuncCall.h"
#include "ReturnNode.h"
#include "IfStmt.h"
#include "ScanStmt.h"
#include "IfElseStmt.h"
#include "WhileStmt.h"
#include "AssignStmt.h"
#include "StructDecl.h"
#include "FuncDecl.h"
#include "FuncDef.h"
#include "FuncHeader.h"
#include "FuncPrefix.h"
#include "Paramsspec.h"
#include "Paramspec.h"
#include "ArraySpec.h"
#include "ArrayVal.h"
#include "VarPart.h"
#include "VarRef.h"
#include "ArrayDecl.h"
#include "BaseDecl.h"

#include "langparse.h"

int yyparse();
int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern SymbolTable *symbolTableRoot;

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
#include "BinaryExprNode.h"
#include "DeclsNode.h"
#include "VarDecl.h"

#include "langparse.h"

int yyparse();
int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern SymbolTable *symbolTableRoot;

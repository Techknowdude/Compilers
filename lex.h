#pragma once

#include "Symbol.h"
#include "SymbolTable.h"
#include "AstNode.h"
#include "BlockNode.h"
#include "PrintNode.h"

#include "langparse.h"

int yyparse();
int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern SymbolTable *symbolTableRoot;

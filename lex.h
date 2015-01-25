#pragma once
int yyparse();
int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern SymbolTable *symbolTableRoot;

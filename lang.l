%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu
#include "lex.h"
#include "langparse.h"
#include "SymbolTable.h"
#include "Symbol.h"
#include <iostream>
using std::cout;
using std::endl;

#define RETURN(a) return Return(a);
static int Return(int val);
%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */
punct		[(){}[\];,.]
operator        [\+\-\*/%=<!]
integer		\-?[0-9]+
float		\-?[0-9]+\.[0-9]+
identifier	[a-zA-Z_][a-zA-Z0-9_]*
junk		.
whitespace      [ \n\t]
commentline     \/\/.*
%%
{commentline}   {}
{punct}         return yytext[0];
{operator}      return yytext[0];
{float}         RETURN(FLOAT_VAL);
{integer}       RETURN(INT_VAL);
{whitespace}    {}
"if"            RETURN(IF);
"scan"          RETURN(SCAN);
"while"         RETURN(WHILE);
"else"          RETURN(ELSE);
"print"         RETURN(PRINT);
"struct"        RETURN(STRUCT);
"return"        RETURN(RETURN);
{identifier}    {
                    string ident(yytext);
                    if(symbolTableRoot->TypeExists(ident))
                    {
                        yylval.symbol = symbolTableRoot->GetSymbol(ident);
                        RETURN(TYPE_ID);
                    }
                    else
                    {
                        yylval.symbol = symbolTableRoot->InsertSymbol(ident);
                        RETURN(IDENTIFIER);
                    }
                }
{junk}          RETURN(JUNK_TOK);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
 //   printf("Scanned '%s': %d\n", yytext, val);
    return val;
}


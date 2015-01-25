%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu

#include "tokens.h"
#include "SymbolTable.h"


#define RETURN(a) return Return(a);
static int Return(int val);
extern SymbolTable * symbolTableRoot;
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
"for"           RETURN(FOR);
"then"          RETURN(THEN);
"else"          RETURN(ELSE);
"while"         RETURN(WHILE);
"print"         RETURN(PRINT);
"scan"          RETURN(SCAN);
"int"           RETURN(INT);
"float"         RETURN(FLOAT);
"char"          RETURN(CHAR);
"struct"        RETURN(STRUCT);
"return"        RETURN(RETURN_TOK);
{identifier}                {
                                return IDENTIFIER;
                            }
{junk}          RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}


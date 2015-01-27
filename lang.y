/* lang.y */

%{
#include <iostream>
#include "Symbol.h"
#include "SymbolTable.h"
#include "lex.h"

%}

%locations

// define semantic value type
%union{
    int             int_val;
    double          float_val;
    Symbol*         symbol;
    SymbolTable*    sym_table;
    void*           ast_node;
    }

%{
    int yyerror(const char *msg);

    SymbolTable * symbolTableRoot;
    
    void *yyast_root;
%}

// Define start symbol
%start  program

// define token types that have an associated semantic value
%token <symbol>     IDENTIFIER
%token <symbol>     TYPE_ID
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

// define token types that don't have a semantic value
%token  SCAN PRINT
%token  WHILE IF ELSE JUNK_TOK
%token  STRUCT
%token  RETURN_TOK
%token  JUNK_TOKEN


%type <ast_node> program
%type <ast_node> block
%type <sym_table> open
%type <sym_table> close
%type <ast_node> decls
%type <ast_node> decl
%type <ast_node> var_decl
%type <ast_node> struct_decl
%type <ast_node> func_decl
%type <ast_node>  func_header
%type <symbol>  func_prefix
%type <ast_node> func_call
%type <ast_node> paramsspec
%type <ast_node> paramspec
%type <ast_node> arrayspec
%type <ast_node> stmts
%type <ast_node> stmt
%type <ast_node> lval
%type <ast_node> arrayval
%type <ast_node> params
%type <ast_node> param
%type <ast_node> expr
%type <ast_node> term
%type <ast_node> fact
%type <ast_node> varref
%type <ast_node> varpart

%%

program: block                  { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
        | /* empty */           { YYACCEPT; }
block:  open decls stmts close  {}
    |   open stmts close        {}
open:   '{'                     { 
                                   symbolTableRoot->IncreaseScope();
                                   $$ = NULL;
                                 }
close:  '}'                     { 
                                  symbolTableRoot->DecreaseScope();
                                  $$ = NULL; // might want to change this
                                }
decls:      decls decl          {}
        |   decl                {}
decl:       var_decl ';'        {}
        |   struct_decl ';'     {}
        |   func_decl           {}
        |   error ';'           {}
var_decl:   TYPE_ID IDENTIFIER arrayspec    
                                {}/* create symbol here  */
        |   struct_decl IDENTIFIER arrayspec
                                {}
struct_decl:  STRUCT open decls close IDENTIFIER    
                                {}
func_decl:  func_header ';'
                                {}
        |   func_header  '{' decls stmts '}'
                                {}
        |   func_header  '{' stmts '}'
                                {}
func_header: func_prefix paramsspec ')'
                                {}
        |    func_prefix ')'    {}
func_prefix: TYPE_ID IDENTIFIER '('
                                {}
paramsspec:     
            paramsspec',' paramspec 
                                {}
        |   paramspec           {}

paramspec:  var_decl            {}

arrayspec:  arrayspec '[' INT_VAL ']'
                                {}
        |   /* empty */         {}

stmts:      stmts stmt          {}
        |   stmt                {}

stmt:       IF '(' expr ')' stmt 
                                {}
        |   IF '(' expr ')' stmt ELSE stmt
                                {}
        |   WHILE '(' expr ')' stmt
                                {}
        |   PRINT '(' expr ')' ';'
                                {}
        |   SCAN '(' lval ')' ';'
                                {}
        |   lval '=' expr ';'   {}
        |   func_call ';'       {}
        |   block               {}
        |   RETURN expr ';'     {}
        |   error ';'           {}

func_call:  IDENTIFIER '(' params ')' 
                                {}
varref:   varref '.' varpart    {}
        | varpart               {}

varpart:  IDENTIFIER arrayval   {}

lval:     varref                {}
arrayval: arrayval '[' expr ']' {}
        |   /* empty */         {}

params:     params',' param     {}
        |   param               {}

param:      expr                {}
        |   /* empty */         {}

expr:       expr '+' term       {}
        |   expr '-' term       {}
        |   term                {}

term:       term '*' fact       {}
        |   term '/' fact       {}
        |   term '%' fact       {}
        |   fact                {}

fact:        '(' expr ')'       {}
        |   INT_VAL             {}
        |   FLOAT_VAL           {}
        |   varref              {}
        |   func_call           {}

%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

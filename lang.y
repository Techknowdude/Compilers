/* lang.y */

%{
#include <iostream>
#include "lex.h"
using std::cout;
using std::endl;
%}

%locations

// define semantic value type
%union{
    int             int_val;
    double          float_val;
    AstNode*        ast_node;
    Symbol*         symbol;
    SymbolTable*    sym_table;
    PrintNode*      print_node;
    BlockNode*      block_node;
    StmtsNode*      stmts_node;
    ExprNode*       expr_node;
    BinaryExprNode* bin_expr_node;
    DeclsNode*      decls_node;
    VarDecl*        var_decl;
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
%token  RETURN
%token  JUNK_TOKEN


%type <block_node> program
%type <block_node> block
%type <sym_table> open
%type <sym_table> close
%type <decls_node> decls
%type <var_decl> decl
%type <var_decl> var_decl
%type <ast_node> struct_decl
%type <ast_node> func_decl
%type <ast_node>  func_header
%type <symbol>  func_prefix
%type <ast_node> func_call
%type <ast_node> paramsspec
%type <ast_node> paramspec
%type <ast_node> arrayspec
%type <stmts_node> stmts
%type <print_node> stmt
%type <ast_node> lval
%type <ast_node> arrayval
%type <ast_node> params
%type <ast_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact
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
block:  open decls stmts close  {
                                    $$ = new BlockNode($3,$2);
                                }
    |   open stmts close        {
                                    $$ = new BlockNode($2,nullptr);
                                }
open:   '{'                     { 
                                    symbolTableRoot->IncreaseScope();
                                    //$$ = NULL; //return current table
                                 }
close:  '}'                     { 
                                    symbolTableRoot->DecreaseScope();
                                    //$$ = NULL; //return current table
                                }
decls:      decls decl          {
                                    $$ = $1;
                                    $$->AddNode($2);
                                }
        |   decl                {
                                    $$ = new DeclsNode($1);
                                }
decl:       var_decl ';'        {
                                    $$ = $1;
                                }
        |   struct_decl ';'     {}
        |   func_decl           {}
        |   error ';'           { // do whatever to not segfault 
                                }
var_decl:   TYPE_ID IDENTIFIER arrayspec    
                                {
                                    symbolTableRoot->InsertSymbol($2);
                                    $$ = new VarDecl($1,$2,$3);    
                                }/* create symbol here  */
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

stmts:      stmts stmt          {
                                    $$ = $1;
                                    $$->AddNode($2);
                                }
        |   stmt                {
                                    $$ = new StmtsNode($1);
                                }

stmt:       IF '(' expr ')' stmt 
                                {
                                }
        |   IF '(' expr ')' stmt ELSE stmt
                                {}
        |   WHILE '(' expr ')' stmt
                                {}
        |   PRINT '(' expr ')' ';'
                                {
                                    $$ = new PrintNode($3);
                                }
        |   SCAN '(' lval ')' ';'
                                {}
        |   lval '=' expr ';'   {}
        |   func_call ';'       {}
        |   block               {}
        |   RETURN expr ';'     {}
        |   error ';'           { // anything to prevent a segfault
                                }

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

expr:       expr '+' term       { 
                                    $$ = new BinaryExprNode($1,"+",$3);
                                }
        |   expr '-' term       {
                                    $$ = new BinaryExprNode($1,"-",$3);
                                }
        |   term                {
                                    $$ = $1;
                                }

term:       term '*' fact       {
                                    $$ = new BinaryExprNode($1,"*",$3);
                                }
        |   term '/' fact       {
                                    $$ = new BinaryExprNode($1,"/",$3);
                                }
        |   term '%' fact       {
                                    $$ = new BinaryExprNode($1,"%",$3);
                                }
        |   fact                {
                                    $$ = $1;
                                }

fact:        '(' expr ')'       {}
        |   INT_VAL             {
                                    $$ =  new IntNode(std::stoi(yytext));
                                }
        |   FLOAT_VAL           {
                                    $$ = new FloatNode(std::stof(yytext));
                                }
        |   varref              {}
        |   func_call           {}

%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

/* lang.y */

%{
#include <iostream>
#include "lex.h"
using std::cout;
using std::endl;

//#define DebugMode
%}

%locations

// define semantic value type
%union{
    string*          string_val;
    int             int_val;
    double          float_val;
    AstNode*        ast_node;
    Symbol*         symbol;
    SymbolTable*    sym_table;
    PrintNode*      print_node;
    BlockNode*      block_node;
    StmtsNode*      stmts_node;
    StmtNode*       stmt_node;
    ExprNode*       expr_node;
    BinaryExprNode* bin_expr_node;
    DeclsNode*      decls_node;
    VarDecl*        var_decl;
    FuncCall*       func_call;
    ParamsNode*     params_node;
    ReturnNode*     ret_node;
    VarRef*         var_ref;
    }

%{
    int yyerror(const char *msg);

    SymbolTable * symbolTableRoot;
    
    void *yyast_root;
%}

// Define start symbol
%start  program

// define token types that have an associated semantic value
%token <string_val>     IDENTIFIER
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
%type <var_decl> struct_decl
%type <var_decl> func_decl
%type <var_decl>  func_header
%type <symbol>  func_prefix
%type <func_call> func_call
%type <params_node> paramsspec
%type <params_node> paramspec
%type <ast_node> arrayspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <var_ref> lval
%type <ast_node> arrayval
%type <params_node> params
%type <expr_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact
%type <var_ref> varref
%type <var_ref> varpart

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
                                    #ifdef DebugMode
                                    #endif
                                    $$ = new BlockNode($3,$2);
                                }
    |   open stmts close        {
                                    #ifdef DebugMode
                                    #endif
                                    $$ = new BlockNode($2,nullptr);
                                }
open:   '{'                     { 
                                    #ifdef DebugMode
                                        cout << "open: {" << endl;
                                    #endif
                                    symbolTableRoot->IncreaseScope();
                                    //$$ = NULL; //return current table
                                 }
close:  '}'                     { 
                                    #ifdef DebugMode
                                        cout << "close: }" << endl;
                                    #endif
                                    symbolTableRoot->DecreaseScope();
                                    //$$ = NULL; //return current table
                                }
decls:      decls decl          {
                                    #ifdef DebugMode
                                        cout << "decls: decls decl" << endl;
                                    #endif
                                    $$ = $1;
                                    $$->AddNode($2);
                                }
        |   decl                {
                                    #ifdef DebugMode
                                        cout << "decls: decl" << endl;
                                    #endif
                                    $$ = new DeclsNode($1);
                                }
decl:       var_decl ';'        {
                                    #ifdef DebugMode
                                        cout << "decl: var_decl" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   struct_decl ';'     {
                                    #ifdef DebugMode
                                        cout << "decl: var_decl" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   func_decl           {
                                    #ifdef DebugMode
                                        cout << "decl: func_decl" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   error ';'           { // do whatever to not segfault 
                                    #ifdef DebugMode
                                        cout << "decl: error" << endl;
                                    #endif
                                }
var_decl:   TYPE_ID IDENTIFIER arrayspec    
                                {
                                    #ifdef DebugMode
                                        cout << "var_decl: TYPE_ID IDENTIFIER arrayspec" << endl;
                                    #endif
                                    Symbol* newSymbol = symbolTableRoot->InsertSymbol(*$2);
                                    $$ = new VarDecl($1,newSymbol,nullptr);    
                                }/* create symbol here  */
        |   struct_decl IDENTIFIER arrayspec
                                {
                                    #ifdef DebugMode
                                        cout << "var_decl: struct_decl IDENTIFIER arrayspec" << endl;
                                    #endif
                                    symbolTableRoot->InsertSymbol(*$2);
                                    $$ = $1;
                                }
struct_decl:  STRUCT open decls close IDENTIFIER    
                                {
                                    #ifdef DebugMode
                                        cout << "struct_decl: STRUCT open decls close IDENTIFIER" << endl;
                                    #endif
                                    Symbol* ident = symbolTableRoot->InsertType(*$5);
                                    $$ = new StructDecl(ident,$3);
                                }
func_decl:  func_header ';'
                                {
                                    #ifdef DebugMode
                                        cout << "func_decl: func_header" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   func_header  '{' decls stmts '}'
                                {
                                    #ifdef DebugMode
                                        cout << "func_decl: { decls stmts }" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   func_header  '{' stmts '}'
                                {
                                    #ifdef DebugMode
                                        cout << "func_header { stmts }" << endl;
                                    #endif
                                    $$ = $1;
                                }
func_header: func_prefix paramsspec ')'
                                {
                                    #ifdef DebugMode
                                        cout << "func_header: func_prefix paramsspec" << endl;
                                    #endif
                                }
        |    func_prefix ')'    {
                                    #ifdef DebugMode
                                        cout << "func_header: func_prefix )" << endl;
                                    #endif
                                }
func_prefix: TYPE_ID IDENTIFIER '('
                                {
                                    #ifdef DebugMode
                                        cout << "func_prefix: TYPE_ID IDENTIFIER" << endl;
                                    #endif
                                }
paramsspec:     
            paramsspec',' paramspec 
                                {
                                    #ifdef DebugMode
                                        cout << "paramsspec: paramsspec, paramspec" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   paramspec           {
                                    #ifdef DebugMode
                                        cout << "paramsspec: paramspec" << endl;
                                    #endif
                                    $$ = $1;
                                }

paramspec:  var_decl            {
                                    #ifdef DebugMode
                                        cout << "paramspec: var_decl" << endl;
                                    #endif
                                    $$ = $1;
                                }

arrayspec:  arrayspec '[' INT_VAL ']'
                                {
                                    #ifdef DebugMode
                                        cout << "arrayspec: arrayspec [ INT_VAL ]" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   /* empty */         {
                                    #ifdef DebugMode
                                        cout << "arrayspec: epsilon" << endl;
                                    #endif
                                }

stmts:      stmts stmt          {
                                    #ifdef DebugMode
                                        cout << "stmts: stmts stmt" << endl;
                                    #endif
                                    $$ = $1;
                                    $$->AddNode($2);
                                }
        |   stmt                {
                                    #ifdef DebugMode
                                        cout << "stmts: stmt" << endl;
                                    #endif
                                    $$ = new StmtsNode($1);
                                }

stmt:       IF '(' expr ')' stmt 
                                {
                                    #ifdef DebugMode
                                        cout << "stmt: IF ( expr ) stmt" << endl;
                                    #endif
                                    $$ = new IfStmt($3,$5);
                                }
        |   IF '(' expr ')' stmt ELSE stmt
                                {
                                    #ifdef DebugMode
                                        cout << "stmt: IF ( expr ) stmt ELSE stmt" << endl;
                                    #endif
                                    $$ = new IfElseStmt($3,$5,$7);
                                }
        |   WHILE '(' expr ')' stmt
                                {
                                    #ifdef DebugMode
                                        cout << "stmt: WHILE ( expr ) stmt" << endl;
                                    #endif
                                    $$ = new WhileStmt($3,$5);
                                }
        |   PRINT '(' expr ')' ';'
                                {
                                    #ifdef DebugMode
                                        cout << "stmt: PRINT ( expr ) ;" << endl;
                                    #endif
                                    $$ = new PrintNode($3);
                                }
        |   SCAN '(' lval ')' ';'
                                {
                                    #ifdef DebugMode
                                        cout << "stmt: SCAN ( lval ) ;" << endl;
                                    #endif
                                    $$ = new ScanStmt($3);
                                }
        |   lval '=' expr ';'   {
                                    #ifdef DebugMode
                                        cout << "stmt: lval = expr ;" << endl;
                                    #endif
                                    $$ = new AssignStmt($1,$3);
                                }
        |   func_call ';'       {
                                    #ifdef DebugMode
                                        cout << "stmt: func_call" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   block               {
                                    #ifdef DebugMode
                                        cout << "stmt: block" << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   RETURN expr ';'     {
                                    #ifdef DebugMode
                                        cout << "stmt: RETURN expr" << endl;
                                    #endif
                                    $$ = new ReturnNode($2);
                                }
        |   error ';'           { // anything to prevent a segfault
                                    #ifdef DebugMode
                                        cout << "stmt: error" << endl;
                                    #endif
                                }

func_call:  IDENTIFIER '(' params ')' 
                                {
                                    #ifdef DebugMode
                                        cout << "func_call: IDENTIFIER ( params )" << endl;
                                    #endif
                                    Symbol* symbol = symbolTableRoot->GetSymbol(*$1);
                                    $$ = new FuncCall(symbol,$3);
                                }
varref:   varref '.' varpart    {
                                    #ifdef DebugMode
                                        cout << "varref: varref . varpart" << endl;
                                    #endif
                                    $$ = $1;
                                    $$->AddPart($3);
                                }
        | varpart               {
                                    #ifdef DebugMode
                                        cout << "varref: varpart" << endl;
                                    #endif
                                    $$ = $1;
                                }

varpart:  IDENTIFIER arrayval   {
                                    #ifdef DebugMode
                                        cout << "varpart: IDENTIFIER arrayval" << endl;
                                    #endif
                                    $$ = new VarRef(symbolTableRoot->GetSymbol(*$1));
                                }

lval:     varref                {
                                    #ifdef DebugMode
                                        cout << "lval: varref" << endl;
                                    #endif
                                    $$ = new VarRef($1);
                                }
arrayval: arrayval '[' expr ']' {
                                    #ifdef DebugMode
                                        cout << "arrayval: arrayval [ expr ]" << endl;
                                    #endif
                                }
        |   /* empty */         {
                                    #ifdef DebugMode
                                        cout << "arrayval: epsilon" << endl;
                                    #endif
                                }

params:     params',' param     {
                                    #ifdef DebugMode
                                        cout << "params: params, param. ";
                                        cout << $3->toString() << endl;
                                    #endif
                                    $$ = $1;
                                    $$->AddNode($3);
                                }
        |   param               {
                                    #ifdef DebugMode
                                        cout << "params: param. ";
                                        cout << $1->toString() << endl;
                                    #endif
                                    $$ = new ParamsNode($1);
                                }

param:      expr                {
                                    #ifdef DebugMode
                                        cout << "param: expr";
                                        cout << $1->toString() << endl;
                                    #endif
                                    $$ = $1;
                                }
        |   /* empty */         {
                                    #ifdef DebugMode
                                        cout << "param: epsilon" << endl;
                                    #endif
                                    $$ = nullptr;
                                }

expr:       expr '+' term       { 
                                    #ifdef DebugMode
                                        cout << "expr: expr + term" << endl;
                                    #endif
                                    $$ = new BinaryExprNode($1,"+",$3);
                                }
        |   expr '-' term       {
                                    #ifdef DebugMode
                                        cout << "expr: expr - term" << endl;
                                    #endif
                                    $$ = new BinaryExprNode($1,"-",$3);
                                }
        |   term                {
                                    #ifdef DebugMode
                                        cout << "expr: term. ";
                                        cout << $1->toString() << endl;
                                    #endif
                                    $$ = $1;
                                }

term:       term '*' fact       {
                                    #ifdef DebugMode
                                        cout << "term: term * fact" << endl;
                                    #endif
                                    $$ = new BinaryExprNode($1,"*",$3);
                                }
        |   term '/' fact       {
                                    #ifdef DebugMode
                                    $$ = new BinaryExprNode($1,"/",$3);
                                    #endif
                                }
        |   term '%' fact       {
                                    #ifdef DebugMode
                                        cout << "expr: term \% fact" << endl;
                                    #endif
                                    $$ = new BinaryExprNode($1,"%",$3);
                                }
        |   fact                {
                                    #ifdef DebugMode
                                        cout << "expr: fact => ";
                                        cout << $1->toString() << endl;
                                    #endif
                                    $$ = $1;
                                }

fact:        '(' expr ')'       {
                                    #ifdef DebugMode
                                        cout << "fact: ( expr ) => ";
                                        cout << $2->toString() << endl;
                                    #endif
                                    $$ = $2;
                                }
        |   INT_VAL             {
                                    #ifdef DebugMode
                                        cout << "fact: INT_VAL" << endl;
                                    #endif
                                    $$ =  new IntNode(std::stoi(yytext));
                                }
        |   FLOAT_VAL           {
                                    
                                    #ifdef DebugMode
                                        cout << "fact: FLOAT_VAL" << endl;
                                    #endif
                                    $$ = new FloatNode(std::stof(yytext));
                                }
        |   varref              { 
                                    #ifdef DebugMode
                                        cout << "fact: varref => ";
                                        cout << $1->toString() << endl;
                                    #endif
                                    $$ = new VarRef($1);
                                }
        |   func_call           {
                                    #ifdef DebugMode
                                        cout << "fact: func_call => ";
                                        cout << $1->toString() << endl;
                                    #endif
                                    $$ = $1;
                                }

%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

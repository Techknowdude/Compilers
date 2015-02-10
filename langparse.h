/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_LANGPARSE_H_INCLUDED
# define YY_YY_LANGPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     TYPE_ID = 259,
     INT_VAL = 260,
     FLOAT_VAL = 261,
     SCAN = 262,
     PRINT = 263,
     WHILE = 264,
     IF = 265,
     ELSE = 266,
     JUNK_TOK = 267,
     STRUCT = 268,
     RETURN = 269,
     JUNK_TOKEN = 270
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 15 "lang.y"

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
    FuncDecl*       func_decl;
    FuncHeader*     func_head;
    FuncPrefix*     func_pre;
    Paramsspec*     paramsspec_node;
    ArraySpec*      arr_spec;
    Paramspec*      paramspec_node;
    ArrayVal*       arr_val;
    VarPart*        var_part;
    

/* Line 2058 of yacc.c  */
#line 102 "langparse.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_LANGPARSE_H_INCLUDED  */

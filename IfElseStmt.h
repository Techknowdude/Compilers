/*
 * =====================================================================================
 *
 *    Description:	If Else Statement node for AST
 *
 *        Version:  1.0
 *        Created:  02/21/2015 04:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Brandon Westmoreland (OIT), brandon.westmoreland@oit.edu
 *   Organization:  Oregon Tech
 *
 * =====================================================================================
 */
#ifndef H_IFELSEEXPR
#define H_IFELSEEXPR

#include "ExprNode.h"
#include "StmtNode.h"

class IfElseStmt : public StmtNode
{
    public:
        IfElseStmt(ExprNode* expr, StmtNode* ifStmt, StmtNode* elStmt);

        string toString();

    protected:
        ExprNode* _expr;
        StmtNode* _ifStmt;
        StmtNode* _elStmt;
};

#endif

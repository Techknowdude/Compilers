/*
 * =====================================================================================
 *
 *    Description:	If Statement node for AST
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
#ifndef H_IFSTMT
#define H_IFSTMT

#include "ExprNode.h"
#include "StmtNode.h"

class IfStmt : public StmtNode
{
    public:
        IfStmt(ExprNode* expr, StmtNode* stmt);

        string toString();

    protected:
        ExprNode* _expr;
        StmtNode* _stmt;
};

#endif

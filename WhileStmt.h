/*
 * =====================================================================================
 *
 *    Description:	While Statement node for AST
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
#ifndef H_WHILESTMT
#define H_WHILESTMT

#include "StmtNode.h"
#include "ExprNode.h"

class WhileStmt : public StmtNode
{
    public:
        WhileStmt(ExprNode* expr, StmtNode* stmt);

        string toString();
            
    protected:
        ExprNode* _expr;
        StmtNode* _stmt;
};

#endif

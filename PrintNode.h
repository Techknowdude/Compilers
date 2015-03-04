/*
 * =====================================================================================
 *
 *    Description:	Print Statement node for AST
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
#ifndef H_PRINTNODE
#define H_PRINTNODE

#include "StmtNode.h"
#include "ExprNode.h"

class PrintNode : public StmtNode
{
    public:
    PrintNode(ExprNode* expr);
    string toString();
    virtual int ComputeOffsets(int base)
    {
        return _expr->ComputeOffsets(base);
    }
    
    virtual void GenerateCode()
    {
        EmitString("Temp = ");
        _expr->GenerateCode();
        EmitString(";\n");
        EmitPrintTemp();
    }

    protected:
    ExprNode* _expr;
};

#endif

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

        virtual int ComputeOffsets(int base)
        {
            int offset = base;
            if(_expr != nullptr)
                offset = _expr->ComputeOffsets(offset);
            if(_ifStmt != nullptr)
                offset = _ifStmt->ComputeOffsets(offset);
            if(_elStmt != nullptr)
                offset = _elStmt->ComputeOffsets(offset);
            return base;
        }

        void GenerateCode()
        {
            string endLabel = GenerateLabel();
            string elseLabel = GenerateLabel();

            EmitString("if (!(");
            _expr->GenerateCode();
            EmitString(")) goto " + elseLabel + ";\n");
            _ifStmt->GenerateCode();
            EmitString("goto " + endLabel + ";\n");
            EmitString(elseLabel + ":\n");
            _elStmt->GenerateCode();
            EmitString(endLabel + ":\n");
        }
    protected:
        ExprNode* _expr;
        StmtNode* _ifStmt;
        StmtNode* _elStmt;
};

#endif

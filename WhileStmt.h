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
            
        virtual int ComputeOffsets(int base)
        {
            int offset = base;
            if(_expr != nullptr)
                offset = _expr->ComputeOffsets(offset);
            if(_stmt != nullptr)
                offset = _stmt->ComputeOffsets(offset);
            return base;
        }
        void GenerateCode()
        {
            string startLabel = GenerateLabel();
            string endLabel = GenerateLabel();
    
            EmitString("/*While(" + _expr->toString() + ")*/\n");
            EmitString(startLabel + ":\n");
            EmitString("if (!(");
            _expr->GenerateCode();
            EmitString(")) goto " + endLabel + ";\n");
            _stmt->GenerateCode();
            EmitString("goto " + startLabel + ";\n");
            EmitString(endLabel + ":\n");
        }
    protected:
        ExprNode* _expr;
        StmtNode* _stmt;
};

#endif

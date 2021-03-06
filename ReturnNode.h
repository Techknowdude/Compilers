/*
 * =====================================================================================
 *
 *    Description:	Return Statement node for AST
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
#ifndef H_RETURNNODE
#define H_RETURNNODE

#include "StmtNode.h"
#include "ExprNode.h"

class ReturnNode : public StmtNode
{
    public:
        ReturnNode(ExprNode* expr);
        string toString();

        virtual int ComputeOffsets(int base)
        {
            return _expr->ComputeOffsets(base);
        }
        void GenerateCode()
        {
            EmitString("/* Return Node */");
            if(_expr->GetType()->IsFloat())
            {
                EmitString("Temp_F = ");
                _expr->GenerateCode();
                EmitString(";\n");
            }
            EmitString("Temp = ");
            _expr->GenerateCode();
            EmitString(";\n");
        }
    protected:
        ExprNode* _expr;
};

#endif

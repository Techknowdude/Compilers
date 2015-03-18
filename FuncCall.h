/*
 * =====================================================================================
 *
 *    Description:	Function Call node for AST
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
#ifndef H_FUNCCALL
#define H_FUNCCALL

#include "StmtNode.h"
#include "ParamsNode.h"
#include "Symbol.h"
#include "ExprNode.h"

//class ParamsNode;

class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(Symbol* ident, ParamsNode* params);
        virtual string toString();
        Decl* GetType(); // return the ident->GetType()

        virtual int ComputeOffsets(int base)
        {
            return _params->ComputeOffsets(base);
        }

        void GenerateCode()
        {
            EmitString("/* Func call */\n");
            // push FP
            EmitString("/* Pushing FP */\n");
            EmitString("(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;\n");
            EmitString("Stack_Pointer += 4;\n");
            
            // push params
            EmitString("/* Pushing Parameters */\n");
            _params->GenerateCode();
            EmitString("Frame_Pointer = Stack_Pointer;\n");
            // make call
            EmitString("/* Making call */\n");
            EmitString( _ident->GetIdentifier() + "();\n");
            
            // pop params
            EmitString("/* Deallocating Param space */\n");
            EmitString("Stack_Pointer -= " + std::to_string(_params->GetSize()) + ";\n");
            // pop FP
            EmitString("/* Popping FP */\n");
            EmitString("Stack_Pointer -= 4;\n");
            EmitString("Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));\n");
        }
    protected:
        Symbol* _ident;
        ParamsNode* _params;
};

#endif

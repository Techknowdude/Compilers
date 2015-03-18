/*
 * =====================================================================================
 *
 *    Description:	Assignment Statement Node for AST
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
#ifndef H_ASSIGNSTMT
#define H_ASSIGNSTMT

#include "StmtNode.h"
#include "ExprNode.h"
#include "VarRef.h"
#include "FuncCall.h"

class AssignStmt : public StmtNode
{
    public:
        AssignStmt(VarRef* varRef, ExprNode* expr);
        AssignStmt(VarRef* varRef, FuncCall* func);

        string toString();
        void CheckForError();
        bool HasSemanticError() { return _hasErr; }
        string GetError() { return _err; }
        virtual int ComputeOffsets(int base)
        {
            if(_varRef != nullptr)
                _varRef->ComputeOffsets(base);
            if(_expr != nullptr)
                _expr->ComputeOffsets(base);
            return base;
        }

        void GenerateCode()
        {
            // Check for function!!!
            Decl* exprDecl = _expr->GetType();
            if(_hasFunc)
            {
                // make call and get return in temp
                _expr->GenerateCode();
                // generate code for lhs
                _varRef->GenerateCode();
               if(exprDecl->IsFloat())
               {
                EmitString(" = Temp_F;\n");
               } 
               else if (exprDecl->IsInt())
               {
                EmitString(" = Temp;\n");
               }
            }
            else
            {
                _varRef->GenerateCode();
                EmitString(" = ");
                _expr->GenerateCode();
                EmitString(";\n");
            }
        }
    protected:
        VarRef* _varRef;
        ExprNode* _expr;

        string _err;
        bool _hasErr;
        bool _hasFunc;
};

#endif

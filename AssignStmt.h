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

class AssignStmt : public StmtNode
{
    public:
        AssignStmt(VarRef* varRef, ExprNode* expr);

        string toString();
        void CheckForError();
        bool HasSemanticError() { return _hasErr; }
        string GetError() { return _err; }
    protected:
        VarRef* _varRef;
        ExprNode* _expr;

        string _err;
        bool _hasErr;
};

#endif

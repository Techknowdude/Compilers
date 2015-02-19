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

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

    protected:
        VarRef* _varRef;
        ExprNode* _expr;
};

#endif

#ifndef H_IFELSEEXPR
#define H_IFELSEEXPR

#include "ExprNode.h"
#include "StmtNode.h"

class IfElseStmt : public StmtNode
{
    public:
        IfElseStmt(ExprNode* expr, StmtNode* ifStmt, StmtNode* elStmt);

        string toString();
        Decl* GetType() { return _expr->GetType(); }

    protected:
        ExprNode* _expr;
        StmtNode* _ifStmt;
        StmtNode* _elStmt;
};

#endif

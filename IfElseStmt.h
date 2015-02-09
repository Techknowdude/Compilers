#ifndef H_IFELSEEXPR
#define H_IFELSEEXPR

#include "ExprNode.h"
#include "StmtNode.h"

class IfElseStmt : public ExprNode, public StmtNode
{
    public:
        IfElseStmt(ExprNode* expr, StmtNode* ifStmt, StmtNode* elStmt);

        string toString();

    protected:
        ExprNode* _expr;
        StmtNode* _ifStmt;
        StmtNode* _elStmt;
};

#endif

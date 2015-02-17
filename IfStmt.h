#ifndef H_IFSTMT
#define H_IFSTMT

#include "ExprNode.h"
#include "StmtNode.h"

class IfStmt : public StmtNode
{
    public:
        IfStmt(ExprNode* expr, StmtNode* stmt);

        string toString();

    protected:
        ExprNode* _expr;
        StmtNode* _stmt;
};

#endif

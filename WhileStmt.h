#ifndef H_WHILESTMT
#define H_WHILESTMT

#include "StmtNode.h"
#include "ExprNode.h"

class WhileStmt : public StmtNode
{
    public:
        WhileStmt(ExprNode* expr, StmtNode* stmt);

        string toString();
            
    protected:
        ExprNode* _expr;
        StmtNode* _stmt;
};

#endif

#ifndef H_RETURNNODE
#define H_RETURNNODE

#include "StmtNode.h"
#include "ExprNode.h"

class ReturnNode : public StmtNode
{
    public:
        ReturnNode(ExprNode* expr);
        string toString();

    protected:
        ExprNode* _expr;
};

#endif

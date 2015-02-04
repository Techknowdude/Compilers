#ifndef H_PRINTNODE
#define H_PRINTNODE

#include "StmtNode.h"
#include "ExprNode.h"

class PrintNode : public StmtNode
{
    public:
    PrintNode(ExprNode* expr);
    string toString();
    protected:
    ExprNode* _expr;
};

#endif

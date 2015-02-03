#ifndef H_PRINTNODE
#define H_PRINTNODE

#include "AstNode.h"
#include "ExprNode.h"

class PrintNode : public AstNode
{
    public:
    PrintNode(ExprNode* expr);
    string toString();
    protected:
    ExprNode* _expr;
};

#endif

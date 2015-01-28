#ifndef H_PRINTNODE
#define H_PRINTNODE

#include "AstNode.h"

class PrintNode : public AstNode
{
    public:
    PrintNode(int expr);
    string toString();
    protected:
    int _expr;
};

#endif

#ifndef H_EXPRNODE
#define H_EXPRNODE

#include <string>
using std::string;

#include "AstNode.h"

class ExprNode : public AstNode
{
    public:
        ExprNode();
        virtual string toString() = 0;

    protected:
};

#endif

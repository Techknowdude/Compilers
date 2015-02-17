#ifndef H_EXPRNODE
#define H_EXPRNODE

#include <string>
using std::string;

#include "AstNode.h"
#include "Symbol.h"

class ExprNode : public AstNode
{
    public:
        ExprNode();
        virtual string toString() = 0;
        //virtual Symbol* GetType() = 0;
    protected:
};

#endif

#ifndef H_EXPRNODE
#define H_EXPRNODE

#include <string>
using std::string;

#include "Symbol.h"
#include "ParamNode.h"

class ExprNode : virtual public ParamNode
{
    public:
        ExprNode();
        virtual string toString() = 0;
        virtual Decl* GetType() = 0;
    protected:
};

#endif

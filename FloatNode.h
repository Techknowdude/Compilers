#ifndef H_FLOATNODE
#define H_FLOATNODE

#include <string>
using std::string;

#include "ExprNode.h"

class FloatNode : public ExprNode
{
    public:
        FloatNode(float floatVal);
        string toString();

        float GetVal();

    protected:
        float _floatVal;
};
#endif

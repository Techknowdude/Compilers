#ifndef H_FLOATNODE
#define H_FLOATNODE

#include <string>
using std::string;

#include "ExprNode.h"
#include "SymbolTable.h"
#include "Symbol.h"

class FloatNode : public ExprNode
{
    public:
        FloatNode(float floatVal);
        string toString();
        Decl* GetType();
        float GetVal();

    protected:
        float _floatVal;
};
#endif

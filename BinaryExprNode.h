#ifndef H_BINEXPRNODE
#define H_BINEXPRNODE

#include <string>
using std::string;

#include "ExprNode.h"

class BinaryExprNode : public ExprNode
{
    public:
        BinaryExprNode(ExprNode* lChild = nullptr, string op = "", ExprNode* rChild = nullptr);
        virtual string toString();

    protected:
        ExprNode* _lChild;
        string _op;
        ExprNode* _rChild;
};

#endif

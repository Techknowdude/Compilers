#ifndef H_BINEXPRNODE
#define H_BINEXPRNODE

#include <string>
using std::string;

#include "ExprNode.h"
#include "Decl.h"
#include "BaseDecl.h"

class BinaryExprNode : public ExprNode
{
    public:
        BinaryExprNode(ExprNode* lChild = nullptr, string op = "", ExprNode* rChild = nullptr);
        virtual string toString();
        Decl* GetType();

    protected:
        ExprNode* _lChild;
        string _op;
        ExprNode* _rChild;
};

#endif

#ifndef H_PARAMSNODE
#define H_PARAMSNODE

#include <list>
using std::list;

#include "ExprNode.h"
#include "Decl.h"

class ParamsNode : public Decl
{
    public:
        ParamsNode(ExprNode* param = nullptr);
        void AddNode(ExprNode* newNode);

        virtual string toString();

    protected:
        list<ExprNode*> _exprList;
};

#endif

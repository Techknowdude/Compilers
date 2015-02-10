#ifndef H_ARRAYVAL
#define H_ARRAYVAL

#include <list>
using std::list;
#include <string>
using std::string;

#include "AstNode.h"
#include "ExprNode.h"

class ArrayVal : public AstNode
{
    public:
        ArrayVal();
        void AddVal(ExprNode* val);

        string toString();

        bool HasVals();
    protected:
        list<ExprNode*> _vals;
};

#endif

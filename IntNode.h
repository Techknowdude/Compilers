#ifndef H_INTTNODE
#define H_INTNODE

#include <string>
using std::string;

#include "ExprNode.h"

class IntNode : public ExprNode
{
    public:
        IntNode(int intVal);
        string toString();

        int GetVal();

    protected:
        int _intVal;
};
#endif

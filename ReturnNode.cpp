#include <iostream>
using std::cout;
using std::endl;

#include "ReturnNode.h"

ReturnNode::ReturnNode(ExprNode* expr) : _expr(expr)
{
}

string ReturnNode::toString()
{
    return "RETURN: " + _expr->toString();
}

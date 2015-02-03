#include "PrintNode.h"

PrintNode::PrintNode(ExprNode* expr) : _expr(expr)
{

}

string PrintNode::toString()
{
    return "PRINT: " + _expr->toString();  
}



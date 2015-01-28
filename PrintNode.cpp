#include "PrintNode.h"

PrintNode::PrintNode(int expr) : _expr(expr)
{

}

string PrintNode::toString()
{
    return "PRINT: (EXPR: " + std::to_string(_expr) + ")";  
}



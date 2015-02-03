#include "ExprNode.h"

ExprNode::ExprNode(ExprNode* child) : _child(child)
{

}
        
string ExprNode::toString()
{
    string stringVal = "(EXPR: ";

    if(_child != nullptr)
        stringVal += _child->toString();
    stringVal += ")";

    return stringVal;
}

#include "BinaryExprNode.h"

        
BinaryExprNode::BinaryExprNode(ExprNode* lChild, string op, ExprNode* rChild) 
    : _lChild(lChild), _op(op), _rChild(rChild)
{

}

string BinaryExprNode::toString()
{
    return "(EXPR: " + _lChild->toString() + " " +_op + " " + _rChild->toString() + ")";
}

// Get the type from left most child. 
//Symbol* BinaryExprNode::GetType()
//{
//    return _lChild->GetType();
//}

#include <iostream>
#include "IntNode.h"

IntNode::IntNode(int intVal) : _intVal(intVal), _type()
{
    // Check if char value
    if(_intVal < 128 && _intVal > -129)
        _type = symbolTableRoot->GetCharDecl();
    else
        _type = symbolTableRoot->GetIntDecl();
}
 
string IntNode::toString()
{
    return "(EXPR: " + std::to_string(_intVal) + ")";
}
 
int IntNode::GetVal()
{
    return _intVal;
}


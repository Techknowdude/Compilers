#include <iostream>
#include "IntNode.h"

IntNode::IntNode(int intVal) : _intVal(intVal)
{

}
 
string IntNode::toString()
{
    return "(EXPR: " + std::to_string(_intVal) + ")";
}
 
int IntNode::GetVal()
{
    return _intVal;
}


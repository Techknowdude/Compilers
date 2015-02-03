#include <iostream>
#include "FloatNode.h"

FloatNode::FloatNode(float floatVal) : _floatVal(floatVal)
{

}

string FloatNode::toString()
{
    return "(EXPR: " + std::to_string(_floatVal) + ")";
}

 
float FloatNode::GetVal()
{
    return _floatVal;
}

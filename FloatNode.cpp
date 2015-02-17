#include <iostream>
#include "FloatNode.h"

extern SymbolTable* symbolTableRoot;

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

Symbol* FloatNode::GetType()
{
    return symbolTableRoot->GetSymbol("float");
}

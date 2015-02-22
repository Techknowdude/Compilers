/*
 * =====================================================================================
 *
 *    Description:	Float Node definitions
 *
 *        Version:  1.0
 *        Created:  02/21/2015 04:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Brandon Westmoreland (OIT), brandon.westmoreland@oit.edu
 *   Organization:  Oregon Tech
 *
 * =====================================================================================
 */
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

Decl* FloatNode::GetType()
{
    return symbolTableRoot->GetSymbol("float")->GetDecl();
}

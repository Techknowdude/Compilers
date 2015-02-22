/*
 * =====================================================================================
 *
 *    Description:	Array Declaration node definitions
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
 */#include "ArrayDecl.h"

ArrayDecl::ArrayDecl(Symbol* type, Symbol* name, ArraySpec* arrSpec)
    : _type(type), _name(name), _arrSpec(arrSpec)
{
}

string ArrayDecl::toString()
{
    string stringVal = "ARRAY: ";
    if(_type != nullptr)
        stringVal += _type->toString() + " ";
    if(_name != nullptr)
        stringVal += _name->toString() + " ";
    if(_arrSpec != nullptr)
        stringVal += _arrSpec->toString();
    
    return stringVal;
}

Decl* ArrayDecl::GetType()
{
    return _type->GetDecl();
}

bool ArrayDecl::IsType()
{
    return true;
}

bool ArrayDecl::IsArray()
{
    return true;
}

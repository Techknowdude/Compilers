/*********************************
*
*   Brandon Westmoreland
*
**********************************/
#include "ArrayDecl.h"

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

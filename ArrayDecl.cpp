/*********************************
*
*   Brandon Westmoreland
*
**********************************/
#include "ArrayDecl.h"

ArrayDecl::ArrayDecl(Symbol* type, Symbol* name, ArraySpec* arrSpec)
    : _type(type), _name(name), _arrSpec(arrSpec)
{
    _name->SetType(true);
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

Symbol* ArrayDecl::GetType()
{
    return _type;
}

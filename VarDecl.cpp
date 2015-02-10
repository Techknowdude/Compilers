#include "VarDecl.h"

VarDecl::VarDecl()
    : _type(), _ident(), _arrSpec()
{

}

VarDecl::VarDecl(Symbol* type, Symbol* ident, ArraySpec* arrSpec)
    : _type(type), _ident(ident), _arrSpec(arrSpec)
{

}

string VarDecl::toString()
{
    string stringVar = "VAR: " + _type->toString() + " " + _ident->toString();
    if(_arrSpec != nullptr && _arrSpec->NumSpecs() > 0)
        stringVar += " " + _arrSpec->toString();

    return stringVar;
}

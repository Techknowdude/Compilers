#include "VarDecl.h"

VarDecl::VarDecl(Symbol* type, Symbol* ident, AstNode* arrSpec)
    : _type(type), _ident(ident), _arrSpec(arrSpec)
{

}

string VarDecl::toString()
{
    string stringVar = "VAR: " + _type->toString() + " " + _ident->toString();
    if(_arrSpec != nullptr)
        stringVar += " " + _arrSpec->toString();

    return stringVar;
}

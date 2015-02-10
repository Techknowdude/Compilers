#include "VarRef.h"

#include <iostream>
using std::cout;
using std::endl;

VarRef::VarRef(Symbol* symbol, VarRef* varRef) : _sym(symbol), _varPart(varRef), _arrVal()
{
}

void VarRef::AddPart(VarRef* varRef)
{
    _varPart = varRef;
}
        
string VarRef::toString()
{
    string stringVal;

        stringVal = "(VarRef: " + _sym->toString();

        if(_varPart != nullptr)
            stringVal += "\n" + _varPart->toString();   

        stringVal += ")";

    return stringVal;
}

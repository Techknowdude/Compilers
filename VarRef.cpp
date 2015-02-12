#include "VarRef.h"

#include <iostream>
using std::cout;
using std::endl;

VarRef::VarRef() : _varRef(), _ident(), _arrVal()
{
}

        
VarRef::VarRef(Symbol* ident, ArrayVal* arrVal) : _varRef(nullptr), _ident(ident), _arrVal(arrVal)
{

}

string VarRef::toString()
{
    string stringVal;

    stringVal += "(VarRef: ";
    if(_ident != nullptr)
       stringVal += _ident->toString();
    if(_arrVal != nullptr && _arrVal->HasVals())
       stringVal += "[" + _arrVal->toString() + "]";
    if(_varRef != nullptr)
       stringVal += "\n" + _varRef->toString();
   
    stringVal += ")";
    return stringVal;
}

void VarRef::SetRef(VarRef* varRef)
{
    _varRef = varRef;
}

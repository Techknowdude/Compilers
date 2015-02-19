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
    // if struct, verify child is in struct
    Decl* decl = _ident->GetDecl();

    if(decl->IsStruct())
    {
        StructDecl* str = dynamic_cast<StructDecl*>(decl);
        if(!str->IsMember(varRef->GetIdent()))
        {
            _hasErr = true;
            _err = varRef->GetIdent()->GetIdentifier() + " is not a field of " + _ident->GetIdentifier();
        }
    }
    else
    {
        _hasErr = true;
        _err = _ident->GetIdentifier() + " is not a struct";
    }
    
    _varRef = varRef;
}

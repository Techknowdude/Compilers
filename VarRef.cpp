#include "VarRef.h"

#include <iostream>
using std::cout;
using std::endl;

VarRef::VarRef() : _varRef(), _ident(), _arrVal()
{
}

VarRef::VarRef(string* ident, ArrayVal* arrVal) : _varRef(nullptr), _ident(), _arrVal(arrVal)
{
    _name = *ident;
    _err = "Symbol " + _name + " not defined";
    _hasErr = true;
}

VarRef::VarRef(Symbol* ident, ArrayVal* arrVal) : _varRef(nullptr), _ident(ident), _arrVal(arrVal)
{
    _name = ident->GetIdentifier();
    _hasErr = false;
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
       stringVal += " " + _varRef->toString();
   
    stringVal += ")";
    return stringVal;
}

void VarRef::SetRef(VarRef* varRef)
{
    if(_hasErr) return;
    if(_varRef != nullptr)
    {
        _varRef->SetRef(varRef);
    }
    else
    {

        // if struct, verify child is in struct
        Decl* decl = _ident->GetDecl();

        if(decl->IsStruct())
        {
            StructDecl* str = dynamic_cast<StructDecl*>(decl->GetBaseType());
            varRef->_ident = str->GetMember(varRef->_name);
            if(varRef->_ident == nullptr)
            {
                _hasErr = true;
                _err = varRef->_name + " is not a field of " + _ident->GetIdentifier();
            }
        }
        else
        {
            _hasErr = true;
            _err = _ident->GetIdentifier() + " is not a struct";
        }
    
        _varRef = varRef;
        _varRef->_hasErr = false;
    }
}

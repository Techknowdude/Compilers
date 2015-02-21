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
    
    // if struct, verify child is in struct
    Decl* decl = _ident->GetDecl();
    
    // only structs have a "child"
    if(!decl->IsStruct())
    {
        _hasErr = true;
        _err = _name + " is not a struct";
    }
    else
    {
        // if this is not the lowest on the tree, add to the child instead
        if(_varRef != nullptr)
        {
            _varRef->SetRef(varRef);

            // check if child had error
            _hasErr = _varRef->_hasErr;
            _err = _varRef->_err;
        }
        else // if this is the lowest, add the new ref
        {
            // get the decl of the ref (safe because we know this is a struct)
            StructDecl* str = dynamic_cast<StructDecl*>(decl->GetBaseType());

            // set the type of the child to the symbol in the struct
            varRef->_ident = str->GetMember(varRef->_name);

            // if the symbol was not found, error
            if(varRef->_ident == nullptr)
            {
                _hasErr = true;
                _err =  varRef->_name + " is not a field of " + _name;
            }
            else
            {   
                _varRef = varRef;
                _varRef->_name = _name + "." + _varRef->_name;
                _varRef->_hasErr = false;
            }
        }
    }
}


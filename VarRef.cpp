#include "VarRef.h"

#include <iostream>
using std::cout;
using std::endl;

VarRef::VarRef() : _varRefs()
{
}

VarRef::VarRef(VarRef* varRef) : _varRefs()
{
    AddRef(varRef);
}

void VarRef::AddRef(VarRef* varRef)
{
    _varRefs.push_back(varRef);
}
        
string VarRef::toString()
{
    string stringVal;

    list<VarRef*>::iterator iter = _varRefs.begin();
    
    if(iter != _varRefs.end())
    {
        stringVal += "(VarRef: " + (*iter)->GetID() + (*iter)->GetArrVal();
        iter++;
    }
    for(; iter != _varRefs.end(); ++iter)
    {
        stringVal += "\n(VarRef: " + (*iter)->GetID() + (*iter)->GetArrVal() + ")";
    }
    stringVal += ")";

    return stringVal;
}

string VarRef::GetID()
{
    return string("");
}

string VarRef::GetArrVal()
{
    return string("");
}

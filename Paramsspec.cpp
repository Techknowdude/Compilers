#include "Paramsspec.h"

Paramsspec::Paramsspec(Paramspec* varDecl) : _decls()
{
    AddNode(varDecl);
}

void Paramsspec::AddNode(Paramspec* varDecl)
{
    if(varDecl != nullptr)
        _decls.push_back(varDecl);
}

string Paramsspec::toString()
{
    string stringVal = "(PARAMS:";

    list<Paramspec*>::iterator iter;

    for(iter = _decls.begin(); iter != _decls.end(); ++iter)
    {
        stringVal += (*iter)->toString();
    }

    stringVal += ")\n";

    return stringVal;

}

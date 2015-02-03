#include "DeclsNode.h"

DeclsNode::DeclsNode(Decl* newNode) : _decls()
{
    AddNode(newNode);
}

void DeclsNode::AddNode(Decl* newNode)
{
    _decls.push_back(newNode);
}

string DeclsNode::toString()
{
    string stringVal = "DECLS:\n{\n";

    list<Decl*>::iterator iter;

    for(iter = _decls.begin(); iter != _decls.end(); ++iter)
    {
        stringVal += (*iter)->toString() + "\n";
    }

    stringVal += "}\n";

    return stringVal;
}

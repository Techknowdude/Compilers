#include "StmtsNode.h"

StmtsNode::StmtsNode(PrintNode* newNode) : _stmts()
{
    AddNode(newNode);
}

void StmtsNode::AddNode(PrintNode* newNode)
{
    _stmts.push_back(newNode);
}

string StmtsNode::toString()
{
    string stringVal = "STMTS:\n{\n";

    list<AstNode*>::iterator iter;

    for(iter = _stmts.begin(); iter != _stmts.end(); ++iter)
    {
        stringVal += (*iter)->toString() + "\n";
    }

    stringVal += "}\n";

    return stringVal;
}

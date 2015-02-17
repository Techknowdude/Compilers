#include <iostream>
using std::cout;
using std::endl;

#include "StmtsNode.h"

StmtsNode::StmtsNode(StmtNode* newNode) : _stmts()
{
    AddNode(newNode);
}

void StmtsNode::AddNode(StmtNode* newNode)
{
    if(newNode != nullptr)
        _stmts.push_back(newNode);
}

string StmtsNode::toString()
{
    string stringVal = "STMTS:\n{\n";

    list<StmtNode*>::iterator iter;

    for(iter = _stmts.begin(); iter != _stmts.end(); ++iter)
    {
        if((*iter) != nullptr)
            stringVal += (*iter)->toString() + "\n";
        else
            cout << "Found empty stmt" << endl;
    }

    stringVal += "}\n";

    return stringVal;
}

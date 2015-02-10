#include <iostream>
using std::cout;
using std::endl;
#include "ParamsNode.h"

ParamsNode::ParamsNode(ExprNode* param) : _exprList()
{
   // cout << "ParamsNode created" << endl;
    if(param != nullptr)
        _exprList.push_front(param);
}
        
void ParamsNode::AddNode(ExprNode* newNode)
{
    if(newNode != nullptr)
    {
     //   cout << "Node being added: " + newNode->toString() << endl; 
        _exprList.push_back(newNode);
    }
    else
    {
       // cout << "Null added. Should be last thing" << endl;
    }
}

string ParamsNode::toString()
{
    string stringVal = "(PARAM:";

    
    list<ExprNode*>::iterator iter;

    for(iter = _exprList.begin(); iter != _exprList.end(); ++iter)
    {
        stringVal += (*iter)->toString() + " ";
    }
    
    stringVal += ")\n";    

    return stringVal;
}


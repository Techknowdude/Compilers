/*
 * =====================================================================================
 *
 *    Description:	Statements node definitions
 *
 *        Version:  1.0
 *        Created:  02/21/2015 04:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Brandon Westmoreland (OIT), brandon.westmoreland@oit.edu
 *   Organization:  Oregon Tech
 *
 * =====================================================================================
 */
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

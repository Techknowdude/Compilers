/*
 * =====================================================================================
 *
 *    Description:	Declarations Node definitions
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
        if((*iter) != nullptr)
            stringVal += (*iter)->toString() + "\n";
    }

    stringVal += "}\n";

    return stringVal;
}

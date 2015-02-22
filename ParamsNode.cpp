/*
 * =====================================================================================
 *
 *    Description:	Parameter Node definitions
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
#include "ParamsNode.h"

ParamsNode::ParamsNode(ParamNode* param) : _paramList()
{
   // cout << "ParamsNode created" << endl;
    if(param != nullptr)
        _paramList.push_front(param);
}
        
void ParamsNode::AddNode(ParamNode* newNode)
{
    if(newNode != nullptr)
    {
     //   cout << "Node being added: " + newNode->toString() << endl; 
        _paramList.push_back(newNode);
    }
    else
    {
       // cout << "Null added. Should be last thing" << endl;
    }
}

string ParamsNode::toString()
{
    string stringVal = "(PARAM:";

    
    list<ParamNode*>::iterator iter;

    for(iter = _paramList.begin(); iter != _paramList.end(); ++iter)
    {
        stringVal += (*iter)->toString() + " ";
    }
    
    stringVal += ")\n";    

    return stringVal;
}


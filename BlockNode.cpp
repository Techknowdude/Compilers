/*
 * =====================================================================================
 *
 *    Description:	Block Node definitions
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
#include "BlockNode.h"

BlockNode::BlockNode(AstNode* stmts, AstNode* decls) : _decls(decls), _stmts(stmts)
{

}

string BlockNode::toString()
{
    string stringVal = "BLOCK: \n{\n"; 
    if(_decls != nullptr)
    {
        stringVal +=  _decls->toString();
    }
    if(_stmts != nullptr)
    {
        stringVal += _stmts->toString();
    }
   
    stringVal += "}\n";
    
    return stringVal;
}

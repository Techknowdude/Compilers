/*
 * =====================================================================================
 *
 *    Description:	Return Statement definitions
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

#include "ReturnNode.h"

ReturnNode::ReturnNode(ExprNode* expr) : _expr(expr)
{
}

string ReturnNode::toString()
{
    return "RETURN: " + _expr->toString();
}

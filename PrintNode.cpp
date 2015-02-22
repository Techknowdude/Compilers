/*
 * =====================================================================================
 *
 *    Description:	Print Stmt definitions
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
#include "PrintNode.h"

PrintNode::PrintNode(ExprNode* expr) : _expr(expr)
{

}

string PrintNode::toString()
{
    return "PRINT: " + _expr->toString();  
}



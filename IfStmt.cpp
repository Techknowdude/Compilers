/*
 * =====================================================================================
 *
 *    Description:	If Statement node definitions
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
#include "IfStmt.h"
        
IfStmt::IfStmt(ExprNode* expr, StmtNode* stmt) : _expr(expr), _stmt(stmt)
{

}

string IfStmt::toString()
{
    string stringVal = "(IF: ";
    if(_expr != nullptr)
        stringVal += _expr->toString() + "\n";
    if(_stmt != nullptr)
        stringVal += _stmt->toString() + "\n";
    stringVal += ")";
    return stringVal;
}

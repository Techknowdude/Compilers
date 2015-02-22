/*
 * =====================================================================================
 *
 *    Description:	If Else Statement definitions
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
#include "IfElseStmt.h"
        
IfElseStmt::IfElseStmt(ExprNode* expr, StmtNode* ifStmt, StmtNode* elStmt) : 
    _expr(expr), _ifStmt(ifStmt), _elStmt(elStmt)
{

}

string IfElseStmt::toString()
{
    string stringVal = "(IF: ";
    if(_expr != nullptr)
        stringVal += _expr->toString() + "\n";
    if(_ifStmt != nullptr)
        stringVal += _ifStmt->toString() + "\n";
    if(_elStmt != nullptr)
        stringVal += "ELSE:\n" + _elStmt->toString() + "\n";
    stringVal += ")";
    return stringVal;
}

/*
 * =====================================================================================
 *
 *    Description:	While Statement node definitions
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
#include "WhileStmt.h"

WhileStmt::WhileStmt(ExprNode* expr, StmtNode* stmt) : _expr(expr), _stmt(stmt)
{

}

string WhileStmt::toString()
{
    return "(WHILE: " + _expr->toString() + "\n" + _stmt->toString() + "\n)";
}

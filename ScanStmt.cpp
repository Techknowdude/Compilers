/*
 * =====================================================================================
 *
 *    Description:	Scan Statement node definitions
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
#include "ScanStmt.h"

ScanStmt::ScanStmt(VarRef* varRef) : _varRef(varRef)
{
}

string ScanStmt::toString()
{
    return "SCAN: " + _varRef->toString();
}

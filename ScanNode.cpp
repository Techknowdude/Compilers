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
#include "ScanNode.h"

ScanNode::ScanNode(VarRef* ref) : _ref(ref)
{

}

string ScanNode::toString()
{
    return "SCAN: " + _ref->toString();  
}



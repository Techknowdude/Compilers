/*
 * =====================================================================================
 *
 *    Description:	Function Prefix definitions
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
#include "FuncPrefix.h"

FuncPrefix::FuncPrefix(Symbol* type, Symbol* id)
    : _type(type), _id(id)
{
    _id->SetDecl(this);
}

        
string FuncPrefix::toString()
{
    return _id->toString();
}


/*
 * =====================================================================================
 *
 *    Description:	Variable Declaration definitions
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
#include "VarDecl.h"

VarDecl::VarDecl()
    : _type(), _ident(), _arrSpec()
{

}

VarDecl::VarDecl(Symbol* type, Symbol* ident, ArraySpec* arrSpec)
    : _type(type), _ident(ident), _arrSpec(arrSpec)
{

}

string VarDecl::toString()
{
    string stringVar = "VAR: " + _type->toString() + " " + _ident->toString();
    if(_arrSpec != nullptr && _arrSpec->NumSpecs() > 0)
        stringVar += " " + _arrSpec->toString();

    return stringVar;
}

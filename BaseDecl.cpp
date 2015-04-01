/*
 * =====================================================================================
 *
 *    Description:	Base Declaration definitions
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
#include "BaseDecl.h"

BaseDecl::BaseDecl(Symbol* ident, int size, bool isFloat) 
    : _ident(ident), _isFloat(isFloat)
{
    _size = size;
}

string BaseDecl::GetName()
{
    return _ident->GetIdentifier();
}

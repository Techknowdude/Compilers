/*
 * =====================================================================================
 *
 *    Description:	Function Header definitions
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
#include "FuncHeader.h"

FuncHeader::FuncHeader(FuncPrefix* prefix, Paramsspec* params)
    : _prefix(prefix), _params(params)
{

}

string FuncHeader::toString()
{
    string stringVal;

    if(_prefix != nullptr)
        stringVal += _prefix->toString();
    if(_params != nullptr)
        stringVal += _params->toString();
    else
        stringVal += "()";

    return stringVal;
}

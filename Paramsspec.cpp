/*
 * =====================================================================================
 *
 *    Description:	Parameter Spec definitions
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
#include "Paramsspec.h"

Paramsspec::Paramsspec(Paramspec* varDecl) : _decls()
{
    AddNode(varDecl);
}

void Paramsspec::AddNode(Paramspec* varDecl)
{
    if(varDecl != nullptr)
        _decls.push_back(varDecl);
}

string Paramsspec::toString()
{
    string stringVal = "(PARAMS:";

    list<Paramspec*>::iterator iter;

    for(iter = _decls.begin(); iter != _decls.end(); ++iter)
    {
        stringVal += (*iter)->toString();
    }

    stringVal += ")\n";

    return stringVal;

}

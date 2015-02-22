/*
 * =====================================================================================
 *
 *    Description:	Function Call Node for AST
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
#include "FuncCall.h"

#include <iostream>
using std::cout;
using std::endl;
        
FuncCall::FuncCall(Symbol* ident, ParamsNode* params) : _ident(ident), _params(params)
{
 //   cout << "Func call created" << endl;
}

         
string FuncCall::toString()
{
    string stringVal = "(FUNC CALL: ";

    stringVal += _ident->toString(); 

    stringVal += _params->toString();

    stringVal += ")";

    return stringVal;
}

Decl* FuncCall::GetType()
{
    return _ident->GetDecl()->GetBaseType();
}


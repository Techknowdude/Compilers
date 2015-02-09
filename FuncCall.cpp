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

    stringVal += _params->toString();

    stringVal += ")";

    return stringVal;
}
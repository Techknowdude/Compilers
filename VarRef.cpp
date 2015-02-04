#include "VarRef.h"

#include <iostream>
using std::cout;
using std::endl;

VarRef::VarRef(Symbol* symbol) : _sym(symbol)
{
}
        
string VarRef::toString()
{
    string stringVal = "(VarRef: " + _sym->toString();

    // Checking for other members here
    //
    stringVal += ")";

    return stringVal;
}

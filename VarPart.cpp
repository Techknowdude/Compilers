#include "VarPart.h"

VarPart::VarPart(Symbol* ident, ArrayVal* arrVal)
    : _symbol(ident), _arrVal(arrVal)
{

}

string VarPart::toString()
{
    string stringVal = "VARPART. Ident, ArrVal";

    return stringVal;
}

string VarPart::GetID()
{
    if(_symbol != nullptr)
        return _symbol->toString();
    else
        return string("");
}

string VarPart::GetArrVal()
{
    if(_arrVal != nullptr && _arrVal->HasVals())
        return "[" + _arrVal->toString() + "]";
    else
        return string("");
}


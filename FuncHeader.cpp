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

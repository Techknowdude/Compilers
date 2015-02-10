#include "ArraySpec.h"

ArraySpec::ArraySpec(int val) : _arraySpecs()
{
    AddSpec(val);
}

void ArraySpec::AddSpec(int val)
{
    _arraySpecs.push_back(val);
}

string ArraySpec::toString()
{
    string stringVal = "(ARRAYSPEC:";

    list<int>::iterator iter;

    for(iter = _arraySpecs.begin(); iter != _arraySpecs.end(); ++iter)
        stringVal += " " + std::to_string(*iter);
    stringVal += ")\n";

    return stringVal;
}

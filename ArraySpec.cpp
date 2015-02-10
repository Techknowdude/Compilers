#include <iostream>
#include "ArraySpec.h"

ArraySpec::ArraySpec() : _arraySpecs()
{
}

void ArraySpec::AddSpec(int val)
{
    _arraySpecs.push_back(val);
}

int ArraySpec::NumSpecs()
{
    return _arraySpecs.size();
}

string ArraySpec::toString()
{
    string stringVal = "(ARRAYSPEC:";

    list<int>::iterator iter;

    for(iter = _arraySpecs.begin(); iter != _arraySpecs.end(); ++iter)
    {
        int val = *iter;
        stringVal += " " + std::to_string(val);
    }
    
    stringVal += ")\n";

    return stringVal;
}

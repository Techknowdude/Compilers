#include "ArrayVal.h"        

ArrayVal::ArrayVal() : _vals()
{

}
 
void ArrayVal::AddVal(ExprNode* val)
{
    _vals.push_back(val);
}


string ArrayVal::toString()
{
    if(_vals.size() == 0) return string("");
    string stringVal = "(ARRAYVAL:";

    list<ExprNode*>::iterator iter;

    for(iter = _vals.begin(); iter != _vals.end(); ++iter)
    {
        stringVal += (*iter)->toString() + " ";
    }

    stringVal += ")\n";

    return stringVal;

}

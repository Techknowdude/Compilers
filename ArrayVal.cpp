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

    list<ExprNode*>::iterator iter = _vals.begin();
    if(iter != _vals.end())
        stringVal += (*iter++)->toString() ;

    for(; iter != _vals.end(); ++iter)
    {
        stringVal += " " + (*iter)->toString() + ")";
    }
    if(_vals.size() == 1)
        stringVal += ")";

 //   stringVal += ")";

    return stringVal;

}

bool ArrayVal::HasVals()
{
    return _vals.size() > 0;
}

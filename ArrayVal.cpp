/*
 * =====================================================================================
 *
 *    Description:	Array value node definitions
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

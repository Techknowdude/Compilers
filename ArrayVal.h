/*
 * =====================================================================================
 *
 *    Description:	Array value node for AST
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

#ifndef H_ARRAYVAL
#define H_ARRAYVAL

#include <list>
using std::list;
#include <string>
using std::string;

#include "AstNode.h"
#include "ExprNode.h"

class ArrayVal : public AstNode
{
    public:
        ArrayVal();
        void AddVal(ExprNode* val);

        string toString();

        bool HasVals();
    protected:
        list<ExprNode*> _vals;
};

#endif

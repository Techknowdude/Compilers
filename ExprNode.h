/*
 * =====================================================================================
 *
 *    Description:	Expression Node for AST
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
#ifndef H_EXPRNODE
#define H_EXPRNODE

#include <string>
using std::string;

#include "Symbol.h"
#include "ParamNode.h"

class ExprNode : virtual public ParamNode
{
    public:
        ExprNode();
        virtual string toString() = 0;
        virtual Decl* GetType() = 0;
    protected:
};

#endif

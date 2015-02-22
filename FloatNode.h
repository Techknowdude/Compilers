/*
 * =====================================================================================
 *
 *    Description:	Float Node for AST
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
#ifndef H_FLOATNODE
#define H_FLOATNODE

#include <string>
using std::string;

#include "ExprNode.h"
#include "SymbolTable.h"
#include "Symbol.h"

class FloatNode : public ExprNode
{
    public:
        FloatNode(float floatVal);
        string toString();
        Decl* GetType();
        float GetVal();

    protected:
        float _floatVal;
};
#endif

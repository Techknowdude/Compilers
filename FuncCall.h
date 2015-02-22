/*
 * =====================================================================================
 *
 *    Description:	Function Call node for AST
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
#ifndef H_FUNCCALL
#define H_FUNCCALL

#include "StmtNode.h"
#include "ParamsNode.h"
#include "Symbol.h"
#include "ExprNode.h"

//class ParamsNode;

class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(Symbol* ident, ParamsNode* params);
        virtual string toString();
        Decl* GetType(); // return the ident->GetType()

    protected:
        Symbol* _ident;
        ParamsNode* _params;
};

#endif

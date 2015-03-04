/*
 * =====================================================================================
 *
 *    Description:	Binary Expression Node for AST
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
#ifndef H_BINEXPRNODE
#define H_BINEXPRNODE

#include <string>
using std::string;

#include "ExprNode.h"
#include "Decl.h"
#include "BaseDecl.h"

class BinaryExprNode : public ExprNode
{
    public:
        BinaryExprNode(ExprNode* lChild = nullptr, string op = "", ExprNode* rChild = nullptr);
        virtual string toString();
        Decl* GetType();
        virtual int ComputeOffsets(int base)
        {
            _lChild->ComputeOffsets(base);
            _rChild->ComputeOffsets(base);
            return base;
        }

        virtual void GenerateCode()
        {
            _lChild->GenerateCode();
            EmitString(" " + _op + " ");
            _rChild->GenerateCode();
        }

    protected:
        ExprNode* _lChild;
        string _op;
        ExprNode* _rChild;
};

#endif

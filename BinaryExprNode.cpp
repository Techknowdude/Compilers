/*
 * =====================================================================================
 *
 *    Description:	Binary Expression Node definitions
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
#include "BinaryExprNode.h"

        
BinaryExprNode::BinaryExprNode(ExprNode* lChild, string op, ExprNode* rChild) 
    : _lChild(lChild), _op(op), _rChild(rChild)
{

}

string BinaryExprNode::toString()
{
    return "(EXPR: " + _lChild->toString() + " " +_op + " " + _rChild->toString() + ")";
}

// Get the type from left most child. 
Decl* BinaryExprNode::GetType()
{
    Decl* type = nullptr;
    // if either are non-numeric, semantic error
    Decl* lDecl = _lChild->GetType();
    Decl* rDecl = _rChild->GetType();

    if(lDecl->IsFunc() || lDecl->IsStruct() || lDecl->IsArray() || 
            rDecl->IsFunc() || rDecl->IsStruct() || rDecl->IsArray())
    {
        // SEMANTIC ERROR
 //       _err = "Operation: " + lDecl->GetName() + " " + _op + " " + rDecl-GetName() + " is not allowed";
   //     _hasErr = true;
    }
    //
    // if they are the same, return either
    else if(lDecl == rDecl)
    {
        type = lDecl;
    }
    //
    // if either is float, return float
    else if(lDecl->IsFloat())
    {
        type = lDecl;
    }
    else if(rDecl->IsFloat())
    {
        type = rDecl;
    }
    //
    // otherwise, return largest
    else
    {
        type = static_cast<BaseDecl*>(lDecl)->Size() > static_cast<BaseDecl*>(rDecl)->Size() ? lDecl : rDecl;
    }
    return type;
}

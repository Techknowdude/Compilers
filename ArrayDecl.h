/*
 * =====================================================================================
 *
 *    Description:	Array Declaration node for AST
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
#ifndef H_ARRAYDECL
#define H_ARRAYDECL

#include "VarDecl.h"
#include "Symbol.h"
#include "ArraySpec.h"
#include "ExprNode.h"

class ArrayDecl : public VarDecl, public ExprNode
{
    public:
        ArrayDecl(Symbol* type, Symbol* name, ArraySpec* arrSpec);
        string toString();
        Decl* GetType();
        bool IsType();
        bool IsArray();
        bool IsStruct() {return false;}
        bool IsChar() {return false;}
        bool IsInt() {return false;}
        bool IsFloat() {return false;}
        string GetName() { return _name->GetIdentifier(); }

    protected:
        Symbol* _type;
        Symbol* _name;
        ArraySpec* _arrSpec;
};
#endif

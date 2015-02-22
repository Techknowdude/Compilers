/*
 * =====================================================================================
 *
 *    Description:	Variable Declaration node for AST
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
#ifndef H_VARDECL
#define H_VARDECL

#include <string>
using std::string;

#include "Symbol.h"
#include "Decl.h"
#include "ParamsNode.h"
#include "Paramspec.h"
#include "ArraySpec.h"

class VarDecl : virtual public ParamsNode, virtual public Paramspec
{
    public:
        VarDecl();
        VarDecl(Symbol* type, Symbol* ident, ArraySpec* arrSpec = nullptr);
        virtual string toString();
        virtual bool IsFloat() { return _type->GetIdentifier() == "float"; }
        virtual bool IsChar() { return _type->GetIdentifier() == "char"; }
        virtual bool IsInt() { return _type->GetIdentifier() == "int"; }
        virtual string GetName() 
        { 
            return _type->GetName(); 
        }
        
        virtual bool IsStruct() { return _type->GetDecl()->IsStruct(); }
        virtual bool IsType() { return false; }
        virtual bool IsArray() { return _type->GetDecl()->IsArray(); }
        virtual bool IsFunc() { return GetBaseType()->IsFunc(); }

        virtual Decl* GetBaseType() 
        {
            return _type->GetDecl();
        }
    protected:
        Symbol* _type;
        Symbol* _ident;
        ArraySpec* _arrSpec;
};

#endif

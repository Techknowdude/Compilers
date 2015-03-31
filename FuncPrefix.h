/*
 * =====================================================================================
 *
 *    Description:	Function Prefix node for AST
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
#ifndef H_FUNCPREFIX
#define H_FUNCPREFIX

#include "FuncDef.h"
#include "Symbol.h"
#include "ParamsNode.h"

class FuncPrefix : public FuncDef
{
    public:
        FuncPrefix(Symbol* type, Symbol* id);

        string toString();

        virtual Decl* GetBaseType()
        {
            return _type->GetDecl();
        }

        virtual bool IsFloat() {return GetBaseType()->IsFloat();}
        virtual bool IsChar() {return GetBaseType()->IsChar();}
        virtual bool IsInt() {return GetBaseType()->IsInt();}
        virtual bool IsStruct() {return GetBaseType()->IsStruct();}
        virtual bool IsType() {return false;}
        virtual bool IsArray() {return GetBaseType()->IsArray();}
        virtual bool IsFunc() {return GetBaseType()->IsFunc();}
        virtual string GetName() {return _id->GetIdentifier();}
    
        Symbol* GetIdentifier() { return _id; }

        void SetParams(Paramsspec* params)
        {
            _params = params;
        }

        Paramsspec* GetParams() 
        {
            return _params;
        }

    protected:
        Symbol* _type;
        Symbol* _id;
        Paramsspec* _params;
};

#endif

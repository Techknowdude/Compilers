/*
 * =====================================================================================
 *
 *    Description:	Function Header Node for AST
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
#ifndef H_FUNCHEADER
#define H_FUNCHEADER

#include "FuncDef.h"
#include "FuncPrefix.h"
#include "Paramsspec.h"

class FuncHeader : public FuncDef
{
    public:
        FuncHeader(FuncPrefix* prefix, Paramsspec* params = nullptr);

        string toString();
        string GetName() { return _prefix->GetName(); }

        virtual Decl* GetBaseType()
        {
            return _prefix->GetBaseType();
        }

        Symbol* GetIdentifier() { return _prefix->GetIdentifier();}

        virtual int ComputeOffsets(int base)
        {
            int offset = base;
            if(_params != nullptr)
                offset = _params->ComputeOffsets(base);
            return offset;
        }

    protected:
        FuncPrefix* _prefix;
        Paramsspec* _params;
};

#endif

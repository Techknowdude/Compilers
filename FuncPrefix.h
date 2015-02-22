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

class FuncPrefix : public FuncDef
{
    public:
        FuncPrefix(Symbol* type, Symbol* id);

        string toString();

        virtual Decl* GetBaseType()
        {
            return _type->GetDecl();
        }

        virtual string GetName() {return _id->GetIdentifier();}
    
        Symbol* GetIdentifier() { return _id; }
    protected:
        Symbol* _type;
        Symbol* _id;
};

#endif

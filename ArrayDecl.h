/*********************************
*
*   Brandon Westmoreland
*
**********************************/
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
        Symbol* GetType();
    protected:
        Symbol* _type;
        Symbol* _name;
        ArraySpec* _arrSpec;
};
#endif

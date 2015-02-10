#ifndef H_VARPART
#define H_VARPART

#include "VarRef.h"
#include "Symbol.h"
#include "ArrayVal.h"

class VarPart : public VarRef
{
    public:
        VarPart(Symbol* ident, ArrayVal* arrVal);
        string toString();
        string GetID();
        string GetArrVal();
    protected:
        Symbol* _symbol;
        ArrayVal* _arrVal;
};

#endif

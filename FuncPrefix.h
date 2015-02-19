#ifndef H_FUNCPREFIX
#define H_FUNCPREFIX

#include "FuncDef.h"
#include "Symbol.h"

class FuncPrefix : public FuncDef
{
    public:
        FuncPrefix(Symbol* type, Symbol* id);

        string toString();

        virtual string GetName();

    protected:
        Symbol* _type;
        Symbol* _id;
};

#endif

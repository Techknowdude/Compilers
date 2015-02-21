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
    protected:
        FuncPrefix* _prefix;
        Paramsspec* _params;
};

#endif

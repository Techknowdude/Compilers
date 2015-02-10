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

    protected:
        FuncPrefix* _prefix;
        Paramsspec* _params;
};

#endif

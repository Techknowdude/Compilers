#ifndef H_VARREF
#define H_VARREF

#include <string>
#include <list>
using std::string;
using std::list;

#include "ExprNode.h"
#include "ArrayVal.h"
#include "Symbol.h"

class VarRef : public ExprNode
{
    public:
        VarRef();
        VarRef(Symbol* ident, ArrayVal* arrVal);
        virtual string toString();
        void SetRef(VarRef* varRef);
    protected:
        VarRef* _varRef;
        Symbol* _ident;
        ArrayVal* _arrVal;
};
#endif

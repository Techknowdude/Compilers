#ifndef H_VARREF
#define H_VARREF

#include <string>
#include "ExprNode.h"
using std::string;

#include "Symbol.h"

class VarRef : public ExprNode
{
    public:
        VarRef(Symbol* symbol);
        virtual string toString();

    protected:
        Symbol* _sym;
};
#endif

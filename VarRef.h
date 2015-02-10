#ifndef H_VARREF
#define H_VARREF

#include <string>
#include <list>
#include "ExprNode.h"
using std::string;
using std::list;

#include "Symbol.h"

class VarRef : public Symbol
{
    public:
        VarRef(Symbol* symbol, VarRef* varRef = nullptr);
        void AddPart(VarRef* varRef);
        virtual string toString();

    protected:
        Symbol* _sym;
        VarRef* _varPart;
        AstNode* _arrVal;
};
#endif

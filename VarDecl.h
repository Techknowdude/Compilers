#ifndef H_VARDECL
#define H_VARDECL

#include <string>
using std::string;

#include "Symbol.h"
#include "Decl.h"
#include "ParamsNode.h"
#include "Paramspec.h"
#include "ArraySpec.h"

class VarDecl : virtual public ParamsNode, virtual public Paramspec
{
    public:
        VarDecl();
        VarDecl(Symbol* type, Symbol* ident, ArraySpec* arrSpec = nullptr);
        virtual string toString();
        virtual bool IsFloat() { return _type->GetIdentifier() == "float"; }
        virtual bool IsChar() { return _type->GetIdentifier() == "char"; }
        virtual bool IsInt() { return _type->GetIdentifier() == "int"; }
        virtual string GetName() { return _type->GetIdentifier(); }
    protected:
        Symbol* _type;
        Symbol* _ident;
        ArraySpec* _arrSpec;
};

#endif

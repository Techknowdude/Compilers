#ifndef H_VARDECL
#define H_VARDECL

#include <string>
using std::string;

#include "Symbol.h"
#include "Decl.h"
#include "ParamsNode.h"
#include "Paramspec.h"

class VarDecl : public ParamsNode, public Paramspec
{
    public:
        VarDecl();
        VarDecl(Symbol* type, Symbol* ident, AstNode* arrSpec = nullptr);
        virtual string toString();
        
        
    protected:
        Symbol* _type;
        Symbol* _ident;
        AstNode* _arrSpec;
};

#endif

#ifndef H_VARDECL
#define H_VARDECL

#include <string>
using std::string;

#include "Symbol.h"
#include "Decl.h"

class VarDecl : public Decl
{
    public:
        VarDecl(Symbol* type, Symbol* ident, AstNode* arrSpec = nullptr);
        virtual string toString();
        
        
    protected:
        Symbol* _type;
        Symbol* _ident;
        AstNode* _arrSpec;
};

#endif

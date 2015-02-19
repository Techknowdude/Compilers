#ifndef H_VARREF
#define H_VARREF

#include <string>
#include <list>
using std::string;
using std::list;

#include "ExprNode.h"
#include "ArrayVal.h"
#include "Symbol.h"
#include "StructDecl.h"

class VarRef : public ExprNode
{
    public:
        VarRef();
        VarRef(Symbol* ident, ArrayVal* arrVal);
        virtual string toString();
        void SetRef(VarRef* varRef);
        Decl* GetType() 
            {
               if(_varRef != nullptr)
                  return _varRef->GetType();
               else
                   return _ident->GetDecl(); 
            }
        Symbol* GetIdent() { return _ident; }
        bool HasSemanticError() { return _hasErr; }
        string GetError() { return _err; }
    protected:
        VarRef* _varRef;
        Symbol* _ident;
        ArrayVal* _arrVal;
        string _err;
        bool _hasErr;
};
#endif

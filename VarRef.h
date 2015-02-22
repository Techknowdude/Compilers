#ifndef H_VARREF
#define H_VARREF

#include <string>
#include <list>
using std::string;
using std::list;
#include <iostream>
using std::cout;
using std::endl;

#include "ExprNode.h"
#include "ArrayVal.h"
#include "Symbol.h"
#include "StructDecl.h"
#include "ArrayDecl.h"

class VarRef : public ExprNode
{
    public:
        VarRef();
        VarRef(Symbol* ident, ArrayVal* arrVal);
        VarRef(string* ident, ArrayVal* arrVal);
        virtual string toString();
        void SetRef(VarRef* varRef);
        Decl* GetType() 
            {
               if(_varRef != nullptr) // get last item's type
               {
                   return _varRef->GetType();
               }
               else
               {
                    if(_ident->GetDecl()->IsArray()) // check for array
                    {
                        if(!_arrVal->HasVals()) // if there are no []
                        {
                            return _ident->GetDecl()->GetBaseType();
                        }                            
                        else // if there are []
                        {
                            return dynamic_cast<ArrayDecl*>(_ident->GetDecl()->GetBaseType())->GetType();
                        }                            
                    } 
                    else
                       return _ident->GetDecl()->GetBaseType(); 
               }
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
        string _name;
};
#endif

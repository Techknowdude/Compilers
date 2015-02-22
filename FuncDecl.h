#ifndef H_FUNCDECL
#define H_FUNCDECL

#include "DeclsNode.h"
#include "FuncDef.h"
#include "FuncHeader.h"
#include "StmtsNode.h"

class FuncDecl : public FuncDef
{
    public:
        FuncDecl(FuncHeader* header, StmtsNode* stmt = nullptr);
        FuncDecl(FuncHeader* header, DeclsNode* decls, StmtsNode* stmts);
        
        string toString();
        virtual Decl* GetBaseType()
        {
            return _header->GetBaseType();
        }
        
        virtual bool IsFloat() {return GetBaseType()->IsFloat();}
        virtual bool IsChar() {return GetBaseType()->IsFloat();}
        virtual bool IsInt() {return GetBaseType()->IsFloat();}
        virtual bool IsStruct() {return GetBaseType()->IsFloat();}
        virtual bool IsType() {return true;}
        virtual bool IsArray() {return GetBaseType()->IsFloat();}
        virtual bool IsFunc() {return GetBaseType()->IsFloat();}
        virtual string GetName() {return _header->GetName(); }

        Symbol* GetIdentifier() { return _header->GetIdentifier();}
    protected:
        FuncHeader* _header;
        StmtsNode* _stmts;
        DeclsNode* _decls;
};

#endif

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
        
        virtual bool IsFloat() {return false;}
        virtual bool IsChar() {return false;}
        virtual bool IsInt() {return false;}
        virtual bool IsStruct() {return false;}
        virtual bool IsType() {return true;}
        virtual bool IsArray() {return false;}
        virtual bool IsFunc() {return true;}
        virtual string GetName() {return _header->GetName(); }

        Symbol* GetIdentifier() { return _header->GetIdentifier();}
    protected:
        FuncHeader* _header;
        StmtsNode* _stmts;
        DeclsNode* _decls;
};

#endif

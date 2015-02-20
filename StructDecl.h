#ifndef H_STRUCTDECL
#define H_STRUCTDECL

#include "VarDecl.h"
#include "HashTable.h"
#include "DeclsNode.h"

class StructDecl : public VarDecl
{
    public:
        StructDecl(Symbol* id, DeclsNode* decls, HashTable* table);
        string toString();
        Symbol* GetMember(string check);
        bool IsType() { return true; }
        bool IsStruct() { return true; }
        bool IsChar() { return false; }
        bool IsInt() { return false; }
        bool IsFloat() { return false; }
        bool IsArray() { return false; }
        string GetName() { return _identifier->GetIdentifier(); }
    protected:
        Symbol* _identifier;
        DeclsNode* _decls;    
        HashTable* _table;
};

#endif

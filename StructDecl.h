#ifndef H_STRUCTDECL
#define H_STRUCTDECL

#include "VarDecl.h"
#include "HashTable.h"
#include "DeclsNode.h"

class StructDecl : public VarDecl
{
    public:
        StructDecl(Symbol* id, DeclsNode* decls);
        string toString();
    
    protected:
        Symbol* _identifier;
        DeclsNode* _decls;    
};

#endif

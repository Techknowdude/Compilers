/*
 * =====================================================================================
 *
 *    Description:	Struct Declaration node for AST
 *
 *        Version:  1.0
 *        Created:  02/21/2015 04:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Brandon Westmoreland (OIT), brandon.westmoreland@oit.edu
 *   Organization:  Oregon Tech
 *
 * =====================================================================================
 */
#ifndef H_STRUCTDECL
#define H_STRUCTDECL

#include "VarDecl.h"
#include "HashTable.h"
#include "DeclsNode.h"
#include "Symbol.h"

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

    private:
        void SetDeclNames();
};

#endif

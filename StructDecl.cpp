#include <list>
using std::list;

#include "StructDecl.h"

StructDecl::StructDecl(Symbol* identifier, DeclsNode* decls, HashTable* table)
    : _identifier(identifier), _decls(decls), _table(table)
{
}

string StructDecl::toString()
{
    string stringVal = "STRUCT: ";

    stringVal += _decls->toString();

    stringVal += " " + _identifier->toString();

    return stringVal;
}

Symbol* StructDecl::GetMember(string check)
{
    Symbol* sym = nullptr;
    if(_table->Contains(check))
        sym = (*_table)[check];

    return sym;
}

void StructDecl::SetDeclNames()
{
    _table->SetSymbolPrefix( _identifier->GetIdentifier() + ".");
}


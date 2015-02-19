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

bool StructDecl::IsMember(Symbol* check)
{
   return _table->Contains(check);
}


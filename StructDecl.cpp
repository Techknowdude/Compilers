#include <list>
using std::list;

#include "StructDecl.h"

StructDecl::StructDecl(Symbol* identifier, DeclsNode* decls)
    : _identifier(identifier), _decls(decls)
{

}

string StructDecl::toString()
{
    string stringVal = "STRUCT: ";

    stringVal += _decls->toString();

    stringVal += " " + _identifier->toString();

    return stringVal;
}

#include "FuncPrefix.h"

FuncPrefix::FuncPrefix(Symbol* type, Symbol* id)
    : _type(type), _id(id)
{

}

        
string FuncPrefix::toString()
{
    return _id->toString();
}


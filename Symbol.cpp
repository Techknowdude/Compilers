/**************************************
* 
* Compilers Lab 3
* Name: Brandon Westmoreland
*
**************************************/
#include "Symbol.h"

int Symbol::SymbolCount = 0;

Symbol::Symbol(string id, Decl* decl)
{
    _decl = decl;
    identifier = id;
    sequence = ++SymbolCount;
#ifdef DebugMode
        cout << "SYMBOL CREATED. Id: " + id + " Seq: " + std::to_string(sequence) << endl;
#endif
}

Symbol::Symbol()
{
}

Symbol & Symbol::operator=(const Symbol & rhs)
{
    if (this != &rhs)
        {
	    this->identifier = rhs.identifier;
	    this->sequence = rhs.sequence;
	}

    return *this;
}

bool Symbol::operator==(const Symbol & rhs)
{
    return identifier == rhs.identifier && sequence == rhs.sequence;
}

int Symbol::GetSequence()
{
    return sequence;
}
string Symbol::GetIdentifier()
{
    return identifier;
}

void Symbol::SetIdentifier(string newID)
{
    identifier = newID;
}

string Symbol::toString()
{
    return "sym: " + identifier + " " + std::to_string(sequence);
}

void Symbol::SetDecl(Decl* decl)
{
    _decl = decl;
}

Decl* Symbol::GetDecl()
{
    return _decl;
}

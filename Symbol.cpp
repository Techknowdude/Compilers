/**************************************
* 
* Compilers Lab 3
* Name: Brandon Westmoreland
*
**************************************/
#include "Symbol.h"

int Symbol::SymbolCount = 0;

Symbol::Symbol(string id)
{
	identifier = id;
	sequence = ++SymbolCount;
}

Symbol::Symbol()
{
	sequence = ++SymbolCount;
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

void Symbol::SetSequence(int seq)
{
	sequence = seq;
}
void Symbol::SetIdentifier(string newID)
{
	identifier = newID;
}

string Symbol::toString()
{
	return identifier;
}

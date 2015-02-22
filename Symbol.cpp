/*
 * =====================================================================================
 *
 *    Description:	Symbol class definitions
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
#include "Symbol.h"

int Symbol::SymbolCount = 0;

Symbol::Symbol(string id, Decl* decl)
{
    _decl = decl;
    identifier = id;
    sequence = ++SymbolCount;
    _name = id;
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

string Symbol::GetName()
{
    return _name;
}

void Symbol::SetName(string name)
{
    _name = name;
}

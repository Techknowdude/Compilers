/**************************************
* 
* Compilers Lab 3
* Name: Brandon Westmoreland
*
**************************************/
/************************************************************************
* Class: Symbol
*
* Constructors:
*	Symbol()
*
* Mutators:
*	~Symbol(string id)
*		This function sets identifier to the passed value and sets the sequence
*		to the SymbolCount and increments the count.
*
* Methods:
*	int GetSequence()
*		returns the sequence
*
*	string GetIdentifier()
*		returns the identifier
*
*	void SetIdentifier(string newID)
*		sets the identifier to the passed value
*
*************************************************************************/
#ifndef SYMBOL
#define SYMBOL
#include <string>
using std::string;

#include "AstNode.h"
#include "Decl.h"

class Symbol : public AstNode
{
public:
	Symbol(string id, Decl* decl = nullptr);
	Symbol();
	Symbol & operator=(const Symbol & rhs);
	bool operator==(const Symbol & rhs);

	int GetSequence();
	string GetIdentifier();

	void SetIdentifier(string newID);
	string toString();

        Decl* GetDecl();
        void SetDecl(Decl* decl);

protected:
	int sequence;
	string identifier;
        Decl* _decl;
	static int SymbolCount;

};
#endif

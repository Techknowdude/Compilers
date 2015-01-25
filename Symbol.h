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
*	void SetSequence(int seq)
*		sets the sequence to the passed value
*
*	void SetIdentifier(string newID)
*		sets the identifier to the passed value
*
*************************************************************************/
#ifndef SYMBOL
#define SYMBOL
#include <string>
using std::string;

class Symbol
{
public:
	Symbol(string id);
	Symbol();
	Symbol & operator=(const Symbol & rhs);
	bool operator==(const Symbol & rhs);

	int GetSequence();
	string GetIdentifier();

	void SetSequence(int seq);
	void SetIdentifier(string newID);

	string toString();

protected:
	int sequence;
	string identifier;
	static int SymbolCount;

};
#endif
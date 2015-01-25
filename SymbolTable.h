/************************************************************************
* Name: Brandon Westmoreland
*
* Class: SymbolTable
*
* Constructors:
*	SymbolTable()
*		Creates an empty SymbolTable object.
*
* Methods:
*	bool IdInCurScope(string id)
*		returns true if the current scope contains the passed identifier
*
*	bool IdExists(string id);
*		returns true if the hash table contains the id in any scope
*
*	void IncreaseScope();
*		increases the scope of the symbole table by adding a new hash table
*		to the list and uses that one for local checks.
*
*	void DecreaseScope();
*		decreases the scope of the symbol table by removing the top hash
*		table from the list	
*
*************************************************************************/
#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
#include <string>
#include <vector>
#include <list>
#include "HashTable.h"
#include "Symbol.h"

using std::list;
using std::vector;
using std::string;

class SymbolTable
{
public:
	SymbolTable();
	bool SymbolInCurScope(Symbol* find);
	bool SymbolExists(Symbol* find);
	bool SymbolInCurScope(string find);
	bool SymbolExists(string find);
	void IncreaseScope();
	void DecreaseScope();
	void InsertSymbol(string insert);
	void InsertSymbol(Symbol* insert);

protected:
	list<HashTable*> SymbolHashes;
	int defaultHashSize;

};
#endif

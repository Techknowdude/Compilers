/**************************************
* 
* Compilers Lab 3
* Name: Brandon Westmoreland
*
**************************************/

#include "SymbolTable.h"

int AsciiHash(string key)
{
	int sum = 0;
	for (int k = 0; k < key.length(); k++)
		sum = sum + int(key[k]);
	return  sum;
}


/**********************************************************************
* Purpose: Creates an empty SymbolTable object. Initializes the hash table list.
* Entry:
* Exit:
************************************************************************/
SymbolTable::SymbolTable() : SymbolHashes(), defaultHashSize(5)
{
	SymbolHashes.push_front(new HashTable(defaultHashSize));
	(*SymbolHashes.front()).setHash(AsciiHash);
}

/**********************************************************************
* Purpose:  Returns true if the current scope contains the passed identifier
* Entry:
* Exit:
************************************************************************/
bool SymbolTable::SymbolInCurScope(Symbol find)
{
	return SymbolHashes.front()->Contains(find);
}

/**********************************************************************
* Purpose:  Returns true if the current scope contains the passed identifier
* Entry:
* Exit:
************************************************************************/
void SymbolTable::InsertSymbol(Symbol newSymbol)
{
	SymbolHashes.front()->Insert(newSymbol.GetIdentifier(), newSymbol);
}

/**********************************************************************
* Purpose: Returns true if the hash table contains the id in any scope
* Entry:
* Exit:
************************************************************************/
bool SymbolTable::SymbolExists(Symbol find)
{
	list<HashTable*>::iterator iter;
	bool found = false;
	for (iter = SymbolHashes.begin(); iter != SymbolHashes.end(); ++iter)
	{
		if ((*iter)->Contains(find))
			found = true;
	}
	return found;
}

/**********************************************************************
* Purpose: Increases the scope of the symbole table by adding a new hash table
*			to the list and uses that one for local checks.
* Entry:
* Exit:
************************************************************************/
void SymbolTable::IncreaseScope()
{
	SymbolHashes.push_front(new HashTable(defaultHashSize));
	(*SymbolHashes.front()).setHash(AsciiHash);
}

/**********************************************************************
* Purpose: Decreases the scope of the symbol table by removing the top hash
*			table from the list
* Entry:
* Exit:
************************************************************************/
void SymbolTable::DecreaseScope()
{
	SymbolHashes.pop_front();
}


/**********************************************************************
* Purpose: Returns true if the hash table contains the id in any scope
* Entry:
* Exit:
************************************************************************/
bool SymbolTable::SymbolExists(string find)
{
	list<HashTable*>::iterator iter;
	bool found = false;
	for (iter = SymbolHashes.begin(); iter != SymbolHashes.end(); ++iter)
	{
		if ((*iter)->Contains(find))
			found = true;
	}
	return found;
}


/**********************************************************************
* Purpose:  Returns true if the current scope contains the passed identifier
* Entry:
* Exit:
************************************************************************/
bool SymbolTable::SymbolInCurScope(string find)
{
	return SymbolHashes.front()->Contains(find);
}

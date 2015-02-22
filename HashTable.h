/*
 * =====================================================================================
 *
 *    Description:	Hash Table used in Symbol table and struct
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
 /************************************************************************
* Class: HashTable
*
* Constructors:
*	HashTable()
*		Creates an empty HashTable object.
*	HashTable(const HashTable<V,U> & copy)
*		Creates a copy of another HashTable object.
*
* Mutators:
*	~HashTable()
*		This function sets data members of the HashTable
*		object to default values.
*	HashTable<V,U> & operator=(const HashTable<V,U> & rhs)
*		Equivocates two HashTable objects to each other
*	Symbol & operator[](string key)
*		This is the operator[] for the HashTable object.
*	void Insert(string key, Symbol val)
*		This inserts the Key and Value pair into the table.
*	void setHash(int (*hash)(string key))
*		Sets the function pointer to the hash function.
*	void Delete(string key)
*		This function removes the Key and Value pair from the table.
*	void Purge()
*		This function clears the hash table.
*
* Methods:
*	HashNode<string,Symbol> * inList(string key)
*		This function searches the hash table for the passed key.
*	void Traverse(void (*visit)(Symbol val))
*		This function calls the visit function on each HashNode.
*
*************************************************************************/
#ifndef H_HASHTABLE
#define H_HASHTABLE
#include <vector>
#include <list>
#include <string>
using std::string;
using std::list;
using std::vector;

#include "HashNode.h"
#include "Symbol.h"

//forward decl for traverse call
class StructDecl;

class HashTable
{
public:
	HashTable(int size );
	~HashTable();
	HashTable( const HashTable & copy );
	HashTable & operator=( const HashTable & rhs );

	Symbol* & operator[](string key);
	void Insert(string key, Symbol* val);
	void setHash(int (*hash)(string key));
	void Delete(string key);
	void Traverse(void (*visit)(Symbol* val));
	void Purge();
	bool Contains(Symbol* item);
	bool Contains(string item);
	bool ContainsType(string item);
        void SetSymbolPrefix(string pre);
        //int Count();
        //string toString();
private:
	HashNode<string,Symbol*> * inList(string key);

	int (*hash)(string key);
	vector<list<HashNode<string,Symbol*>*>> m_table;
};


#endif

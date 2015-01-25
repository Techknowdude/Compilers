/**************************************
* 
* Compilers Lab 3
* Name: Brandon Westmoreland
*
**************************************/
#include "HashTable.h"


/**********************************************************************
* Purpose:  This is the constructor for the HashTable object.
*
* Entry:	This is called when an HashTable object is declared.
*
* Exit:		This function creates an HashTable object.
************************************************************************/

HashTable::HashTable(int size) : hash(nullptr),  m_table(size)
{
}

/**********************************************************************
* Purpose:  This is the copy constructor for an HashTable object.
*
* Entry:	This is called when an HashTable object is already
*			declared and a new one is created using the old one
*			for reference.
*
* Exit:		This function creates a copy of the passed
*			HashTable object.
************************************************************************/

HashTable::HashTable(const HashTable & copy)
: hash(copy.hash), m_table(copy.m_table.size())
{
	*this = copy;
}

/**********************************************************************
* Purpose:  This is the destructor for the HashTable object.
*
* Entry:	This is called when an HashTable object is destroyed.
*
* Exit:		This function deallocates any memory the HashTable class uses.
************************************************************************/

HashTable::~HashTable()
{
	Purge();
}

/**********************************************************************
* Purpose:  This is the operator= for the HashTable object.
*
* Entry:	This is called when you try to equivocate two
*			HashTable objects to each other.
*
* Exit:		This function will set the invoking object's data members
*			to those on the right-hand side of the '='.
************************************************************************/

HashTable & HashTable::operator=(const HashTable & rhs)
{
	if (this != &rhs)
	{
		Purge();
		m_table.resize(rhs.m_table.size());
		this->hash = rhs.hash;
		list<HashNode<string, Symbol>*> temp;
		list<HashNode<string, Symbol>*>::const_iterator Listiter;
		// Move all the nodes into a temp list
		int tableSize = m_table.size();
		for (int bucket = 0; bucket < tableSize; ++bucket)
		{
			for (Listiter = rhs.m_table[bucket].begin();
				Listiter != rhs.m_table[bucket].end(); ++Listiter)
			{
				Insert((*Listiter)->m_key, (*Listiter)->m_value);
			}
		}
	}
	return *this;
}

/**********************************************************************
* Purpose:  This is the operator[] for the HashTable object.
*
* Entry:	This is called when the data at the Key is requested or created.
*
* Exit:		Data is returned or inserted depending on use.
************************************************************************/

Symbol & HashTable::operator[](string key)
{
	int index = hash(key) % m_table.size();
	HashNode<string, Symbol> * node = inList(key);
	if (node == nullptr)
	{
		node = new HashNode<string, Symbol>();
		node->m_key = key;
		m_table[index].push_front(node);
	}

	return node->m_value;
}

/**********************************************************************
* Purpose:  This inserts the Key and Value pair into the table.
*
* Entry:	Used by the client code to add data to the table.
*
* Exit:		A HashNode with the Key and Value is created and added to the
*			HashTable.
************************************************************************/

void HashTable::Insert(string key, Symbol val)
{
	if (inList(key) == nullptr)
	{
		int index = hash(key) % m_table.size();
		m_table[index].push_back(new HashNode<string, Symbol>(key, val));
	}
	else
		throw "Error! Key already in list";
}

/**********************************************************************
* Purpose:  Sets the function pointer to the hash function.
*
* Entry:	Used by the client code to change the hash used.
*
* Exit:		The new hash is set and used to rebuild the table.
************************************************************************/

void HashTable::setHash(int(*hash)(string key))
{
	if (this->hash != hash)
	{
		this->hash = hash;
		list<HashNode<string, Symbol>*> temp;
		vector<list<HashNode<string, Symbol>*>>::iterator iter;
		// Move all the nodes into a temp list
		for (iter = m_table.begin(); iter != m_table.end(); ++iter)
		{
			while (!iter->empty())
			{
				temp.push_front(iter->front());
				iter->pop_front();
			}
		}

		// insert data back in deleting nodes as they are replaced.
		HashNode<string, Symbol> * del = nullptr;
		while (!temp.empty())
		{
			del = temp.front();
			temp.pop_front();
			Insert(del->m_key, del->m_value);
			delete del;
		}
	}
}

/**********************************************************************
* Purpose:  This function removes the Key and Value pair from the table.
*
* Entry:	Used by the client code to modify the table.
*
* Exit:		The target pair is removed or an exception is thrown if no
*			match is found.
************************************************************************/

void HashTable::Delete(string key)
{
	HashNode<string, Symbol> * del = inList(key);
	int index = hash(key) % m_table.size();

	if (del != nullptr)
	{
		m_table[index].remove(del);
		delete del;
	}
	else
		throw "Key was not found in table";

}

/**********************************************************************
* Purpose:  This function calls the visit function on each HashNode.
*
* Entry:	Used by the client code to operate on all of the data.
*
* Exit:		Each HashNode is visited by the passed function.
************************************************************************/

void HashTable::Traverse(void(*visit)(Symbol val))
{
	list<HashNode<string, Symbol>*>::iterator iter;
	int size = m_table.size();
	for (int bucket = 0; bucket < size; ++bucket)
	{
		for (iter = m_table[bucket].begin(); iter != m_table[bucket].end(); ++iter)
		{
			visit((*iter)->m_value);
		}
	}
}

/**********************************************************************
* Purpose:  This function clears the hash table.
*
* Entry:	Used by the client code to remove all items from the table.
*
* Exit:		Each HashNode is removed and deallocated.
************************************************************************/

void HashTable::Purge()
{
	HashNode<string, Symbol> * del = nullptr;
	int size = m_table.size();
	for (int bucket = 0; bucket < size; ++bucket)
	{
		while (!m_table[bucket].empty())
		{
			del = m_table[bucket].front();
			m_table[bucket].pop_front();
			delete del;
		}
	}
}

/**********************************************************************
* Purpose:  This function searches the hash table for the passed key.
*
* Entry:	Used internally to find data to delete or prevent duplication.
*
* Exit:		returns a pointer to the HashNode or nullptr.
************************************************************************/
HashNode<string, Symbol> * HashTable::inList(string key)
{
	int index = hash(key) % m_table.size();
	list<HashNode<string, Symbol>*>::iterator iter;
	HashNode<string, Symbol> * pointer = nullptr;
	for (iter = m_table[index].begin(); iter != m_table[index].end(); ++iter)
	{
		if ((*iter)->m_key == key)
			pointer = *iter;
	}
	return pointer;
}



/**********************************************************************
* Purpose:  This is the constructor for the HashTable object.
*
* Entry:	This is called when an HashTable object is declared.
*
* Exit:		This function creates an HashTable object.
************************************************************************/

bool HashTable::Contains(Symbol value)
{
	vector<list<HashNode<string, Symbol>*>>::iterator vectIter;
	list<HashNode<string, Symbol>*>::iterator listIter;
	bool found = false;

	for (vectIter = m_table.begin(); !found && vectIter != m_table.end(); ++vectIter)
	{
		for (listIter = vectIter->begin(); !found && listIter != vectIter->end(); ++listIter)
		{
			if ((*listIter)->m_value == value)
				found = true;
		}
	}
	return found;
}

/**********************************************************************
* Purpose:  This is the constructor for the HashTable object.
*
* Entry:	This is called when an HashTable object is declared.
*
* Exit:		This function creates an HashTable object.
************************************************************************/
bool HashTable::Contains(string value)
{
	vector<list<HashNode<string, Symbol>*>>::iterator vectIter;
	list<HashNode<string, Symbol>*>::iterator listIter;
	bool found = false;

	for (vectIter = m_table.begin(); !found && vectIter != m_table.end(); ++vectIter)
	{
		for (listIter = vectIter->begin(); !found && listIter != vectIter->end(); ++listIter)
		{
			if ((*listIter)->m_value.GetIdentifier() == value)
				found = true;
		}
	}
	return found;
}

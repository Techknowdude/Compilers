/**************************************
* 
* Compilers Lab 3
* Name: Brandon Westmoreland
*
**************************************/
/************************************************************************
* Class: HashNode
*
* Constructors:
*	HashNode()
*		Creates an empty HashNode object.
*	HashNode(K key, V val)
*		Creates a HashNode object with the key and value.
*	HashNode(const HashNode<V,U> & copy)
*		Creates a copy of another HashNode object.
*
* Mutators:
*	~HashNode()
*		This function deallocates any memory used by the Node.
*	HashNode<V,U> & operator=(const HashNode<V,U> & rhs)
*		Equivocates two HashNode objects to each other
*
* Methods:
*	
*
*************************************************************************/
#ifndef H_HASHNODE
#define H_HASHNODE

template<typename K, typename V>
class HashNode
{
	friend class HashTable;
public:
	HashNode();
	HashNode(K key, V val);
	~HashNode();
	HashNode( const HashNode<K,V> & copy );
	HashNode<K,V> & operator=( const HashNode<K,V> & rhs );

private:
	K m_key;
	V m_value;
};

/**********************************************************************	
* Purpose:  This is the constructor for the HashNode object. 
*
* Entry:	This is called when an HashNode object is declared.
*
* Exit:		This function creates an HashNode object.
************************************************************************/
template<typename K, typename V>
HashNode<K,V>::HashNode() : m_key(), m_value()
{ }

/**********************************************************************	
* Purpose:  This is the copy constructor for the HashNode object. 
*
* Entry:	This is called when an HashNode object is declared using
*			another HashNode object.
*
* Exit:		This function creates an HashNode object with the Key and
*			Value of the other object.
************************************************************************/
template<typename K, typename V>
HashNode<K,V>::HashNode(K key, V val) 
	: m_key(key), m_value(val)
{ }

/**********************************************************************	
* Purpose:  This is the copy constructor for an HashNode object.
*
* Entry:	This is called when an HashNode object is already
*			declared and a new one is created using the old one
*			for reference.
*
* Exit:		This function creates a copy of the passed 
*			HashNode object.
************************************************************************/
template<typename K, typename V>
HashNode<K,V>::HashNode( const HashNode<K,V> & copy ) 
	: m_key(copy.m_key), m_value(copy.m_value)
{ }

/**********************************************************************	
* Purpose:  This is the destructor for the HashNode object.
*
* Entry:	This is called when an HashNode object is destroyed.
*
* Exit:		This function deallocates any memory the HashNode class uses.
************************************************************************/
template<typename K, typename V>
HashNode<K,V>::~HashNode()
{

}

/**********************************************************************	
* Purpose:  This is the operator= for the HashNode object.
*
* Entry:	This is called when you try to equivocate two
*			HashNode objects to each other.
*
* Exit:		This function will set the invoking object's data members
*			to those on the right-hand side of the '='.
************************************************************************/
template<typename K, typename V>
HashNode<K,V> & HashNode<K,V>::operator=( const HashNode<K,V> & rhs )
{
	if( this != &rhs )
	{
		m_key = rhs.m_key;
		m_value = rhs.m_value;
	}
	return *this;
}

#endif

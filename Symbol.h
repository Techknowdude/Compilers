/*
 * =====================================================================================
 *
 *    Description:	Symbol class for AST nodes
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

        string GetName();
        void SetName(string name);

protected:
	int sequence;
	string identifier;
        Decl* _decl;
	static int SymbolCount;
        string _name;

};
#endif

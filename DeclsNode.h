/*
 * =====================================================================================
 *
 *    Description:	Declarations Node for AST
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
#ifndef H_DECLSNODE
#define H_DECLSNODE

#include <string>
#include <list>
using std::list;
using std::string;

#include "Decl.h"

class DeclsNode : public Decl
{

    public:
        DeclsNode(Decl* node);
        virtual string toString();

        void AddNode(Decl* newNode);
        virtual string GetName() { return "DeclsNode"; }

    protected:
        list<Decl*> _decls;
};

#endif

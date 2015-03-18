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
        virtual int ComputeOffsets(int base)
        {
            // starting point set
            int offset = base;
            list<Decl*>::iterator iter;

            // compute offset for each child. track running offset
            for(iter = _decls.begin(); iter != _decls.end(); ++iter)
            {
                offset = (*iter)->ComputeOffsets(offset);
            }

            // size of decls is the sum of the decls - starting point
            _size = offset - base;

            return offset;
        }

        virtual void GenerateCode()
        {
            EmitString("// Allocate space for local variables.\n");
             
            list<Decl*>::iterator iter;
            for(iter = _decls.begin(); iter != _decls.end(); ++iter)
                (*iter)->GenerateCode();
                
        }

    protected:
        list<Decl*> _decls;
};

#endif

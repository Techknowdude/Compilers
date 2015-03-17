/*
 * =====================================================================================
 *
 *    Description:	Parameter Spec node for AST
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
#ifndef H_PARAMSSPEC
#define H_PARAMSSPEC

#include <list>
using std::list;
#include "VarDecl.h"
#include "AstNode.h"

class Paramsspec : public AstNode
{
    public:
        Paramsspec(VarDecl* varDecl);
        void AddNode(VarDecl* varDecl);
        string toString();
        virtual int ComputeOffsets(int base)
        {
            int offset = base;

            list<VarDecl*>::iterator iter;

            for(iter = _decls.begin(); iter != _decls.end(); ++iter)
            {
                offset = (*iter)->ComputeOffsets(offset);
            }
            return offset;
        }

        virtual void GenerateCode()
        {

        }
    protected:
        list<VarDecl*> _decls;
};

#endif


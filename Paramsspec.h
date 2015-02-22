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
#include "Paramspec.h"

class Paramsspec 
{
    public:
        Paramsspec(Paramspec* varDecl);
        void AddNode(Paramspec* varDecl);
        string toString();
    protected:
        list<Paramspec*> _decls;
};

#endif


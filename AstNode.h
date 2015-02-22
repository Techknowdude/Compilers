/*
 * =====================================================================================
 *
 *    Description:	AST Node base class
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
#ifndef H_ASTNODE
#define H_ASTNODE
#include <string>
using std::string;

class AstNode
{
    public:
    virtual string toString() = 0;

    // Since only some will throw errors, default to no error
    virtual bool HasSemanticError()
    {   
        return false;
    }
    virtual string GetError()
    {
        return "Ast Error";
    }
    private:

};

#endif

/*
 * =====================================================================================
 *
 *    Description:	Declaration Node base class for AST
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
#ifndef H_DECLBASE
#define H_DECLBASE

#include "AstNode.h"

class Decl : public virtual AstNode
{
    public:
        virtual Decl* GetBaseType() { return this; }
        virtual bool IsType() { return false; }
        virtual bool IsFunc() { return false; }
        virtual bool IsInt() { return false; }
        virtual bool IsChar() { return false; }
        virtual bool IsFloat() { return false; }
        virtual bool IsStruct() { return false; }
        virtual bool IsArray() { return false; }
        virtual Decl* GetType() {return this; }
        virtual string GetName() = 0;

        virtual string toString()
        {
            return "";
        }
    protected:
};

#endif

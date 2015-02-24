/*
 * =====================================================================================
 *
 *    Description:	Base Declaration class for AST
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
#ifndef H_BASEDECL
#define H_BASEDECL

#include "Decl.h"
#include "ExprNode.h"
#include "Symbol.h"

class BaseDecl : public Decl
{
    public:
        BaseDecl(Symbol* ident, int size, bool isFloat);

        virtual bool IsInt() { return !_isFloat; }
        virtual bool IsFloat() { return _isFloat; }
        virtual bool IsChar() { return _size == 1; }
        virtual bool IsType() { return true; }

        int Size() { return _size; }
        virtual string GetName();
        virtual int GetSize()
        {
            return _size;
        }
    protected:
        Symbol* _ident;
        int _size;
        bool _isFloat;
};

#endif

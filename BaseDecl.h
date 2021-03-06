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

extern int WORD_SIZE;

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
        virtual int ComputeOffsets(int base)
        {
            _offset = base;
        
            if(_size >= WORD_SIZE)
            {
                if(_offset % WORD_SIZE != 0)
                    _offset += WORD_SIZE = (_offset % WORD_SIZE);
            }

            return _offset + _size;
        }
        
        virtual void GenerateCode()
        {
            // emit code for var push
            EmitString("Stack_Pointer += " + std::to_string(_size) + ";\n");
        }
        
        string toString()
        {
            if(IsInt())
                return "int";
            else if(IsFloat())
                return "float";
            else if(IsChar())
                return "char";
            else
                return "nil";
        }
    protected:
        Symbol* _ident;
        bool _isFloat;
};

#endif

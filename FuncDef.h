/*
 * =====================================================================================
 *
 *    Description:	Function Definition Node for AST
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
#ifndef H_FUNCDEF
#define H_FUNCDEF

#include "VarDecl.h"

class FuncDef : public VarDecl
{
    public:
        virtual bool IsFloat() {return false;}
        virtual bool IsChar() {return false;}
        virtual bool IsInt() {return false;}
        virtual bool IsStruct() {return false;}
        virtual bool IsType() {return true;}
        virtual bool IsArray() {return false;}
        virtual bool IsFunc() {return true;}

};

#endif

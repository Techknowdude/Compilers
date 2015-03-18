/*
 * =====================================================================================
 *
 *    Description:	Function Declaration definitions
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
#include "FuncDecl.h"

FuncDecl::FuncDecl(FuncHeader* header, StmtsNode* stmts) 
    : _header(header), _stmts(stmts), _decls()
{
      //GetIdentifier()->SetDecl(this); 
}
        
FuncDecl::FuncDecl(FuncHeader* header, DeclsNode* decls, StmtsNode* stmts)
    : _header(header), _stmts(stmts), _decls(decls)
{
      //GetIdentifier()->SetDecl(this); 
}

 
string FuncDecl::toString()
{
    string stringVal = "(FUNC: ";

    stringVal += _header->toString();

    if(_decls != nullptr)
        stringVal += "\n" + _decls->toString();

    if(_stmts != nullptr)
        stringVal += "\n" + _stmts->toString();
    if(_size != 0)
        stringVal += "\nsize: " + std::to_string(_size);

    stringVal += "\n)";
    return stringVal;   
}

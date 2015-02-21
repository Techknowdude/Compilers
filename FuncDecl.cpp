#include "FuncDecl.h"

FuncDecl::FuncDecl(FuncHeader* header, StmtsNode* stmts) 
    : _header(header), _stmts(stmts), _decls()
{
    
}
        
FuncDecl::FuncDecl(FuncHeader* header, DeclsNode* decls, StmtsNode* stmts)
    : _header(header), _stmts(stmts), _decls(decls)
{

}

 
string FuncDecl::toString()
{
    string stringVal = "(FUNC: ";

    stringVal += _header->toString();

    if(_decls != nullptr)
        stringVal += "\n" + _decls->toString();

    if(_stmts != nullptr)
        stringVal += "\n" + _stmts->toString();
    stringVal += "\n)";
    return stringVal;   
}

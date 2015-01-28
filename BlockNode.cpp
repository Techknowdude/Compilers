#include "BlockNode.h"

BlockNode::BlockNode(AstNode* stmts, AstNode* decls) : _decls(decls), _stmts(stmts)
{

}

string BlockNode::toString()
{
    string stringVal = "BLOCK: \n{\n"; 
    if(_decls != nullptr)
    {
        stringVal +=  _decls->toString();
    }
    if(_stmts != nullptr)
    {
        stringVal += _stmts->toString();
    }
   
    stringVal += "}\n";
    
    return stringVal;
}

#include "BlockNode.h"

BlockNode::BlockNode(PrintNode* stmts, AstNode* decls) : _decls(decls), _stmts(stmts)
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
        stringVal += "STMTS:\n{\n" + _stmts->toString() + "\n}\n";
    }
    
    stringVal += "}\n";

    return stringVal;
}

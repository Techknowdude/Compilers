#include "StmtsNode.h"

StmtsNode::StmtsNode() : _stmts()
{

}

AstNode* AddNode(AstNode* newNode)
{
    _stmts.push_back(newNode);
}

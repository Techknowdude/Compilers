#ifndef H_STMTSNODE
#define H_SMTTSNODE

#include "AstNode.h"

class StmtsNode : public AstNode
{
    public:
    StmtsNode();
    AstNode* AddNode(AstNode* newNode);
    string toString();
    
    private:
    list<AstNode*> stmts;
};

#endif

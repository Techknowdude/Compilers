#ifndef H_STMTSNODE
#define H_STMTSNODE
#include <list>
#include "AstNode.h"
using std::list;

#include "StmtNode.h"

class StmtsNode : public AstNode
{
    public:
    StmtsNode(StmtNode* newNode);
    void AddNode(StmtNode* newNode);
    string toString();
    
    private:
    list<StmtNode*> _stmts;
};

#endif

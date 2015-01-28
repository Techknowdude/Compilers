#ifndef H_STMTSNODE
#define H_SMTTSNODE
#include <list>
#include "AstNode.h"
#include "PrintNode.h"

using std::list;


class StmtsNode : public AstNode
{
    public:
    StmtsNode(PrintNode* newNode);
    void AddNode(PrintNode* newNode);
    string toString();
    
    private:
    list<AstNode*> _stmts;
};

#endif

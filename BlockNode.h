#ifndef H_BLOCKNODE
#define H_BLOCKNODE

#include "AstNode.h"
#include "StmtNode.h"

class BlockNode : public StmtNode
{

    public:
    BlockNode(AstNode* stmts, AstNode* decls);
    string toString();

    private:
    AstNode* _decls;
    AstNode* _stmts;
};

#endif

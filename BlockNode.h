#ifndef H_BLOCKNODE
#define H_BLOCKNODE

#include "AstNode.h"

class BlockNode : public AstNode
{

    public:
    BlockNode(AstNode* stmts, AstNode* decls);
    string toString();

    private:
    AstNode* _decls;
    AstNode* _stmts;
};

#endif

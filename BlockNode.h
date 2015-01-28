#ifndef H_BLOCKNODE
#define H_BLOCKNODE

#include "AstNode.h"
#include "PrintNode.h"

class BlockNode : public AstNode
{

    public:
    BlockNode(PrintNode* stmts, AstNode* decls);
    string toString();

    private:
    AstNode* _decls;
    PrintNode* _stmts;
};

#endif

/*
 * =====================================================================================
 *
 *    Description:	Block Node for AST
 *
 *        Version:  1.0
 *        Created:  02/21/2015 04:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Brandon Westmoreland (OIT), brandon.westmoreland@oit.edu
 *   Organization:  Oregon Tech
 *
 * =====================================================================================
 */
#ifndef H_BLOCKNODE
#define H_BLOCKNODE

#include "AstNode.h"
#include "StmtNode.h"

class BlockNode : public StmtNode
{

    public:
    BlockNode(AstNode* stmts, AstNode* decls);
    string toString();
    virtual int ComputeOffsets(int base)
    {
        int offset = base;

        if(_decls != nullptr)
            offset = _decls->ComputeOffsets(offset);
        if(_stmts != nullptr)
            offset = _stmts->ComputeOffsets(offset);

        _size = offset - base;

        return base;
    }

    private:
    AstNode* _decls;
    AstNode* _stmts;
};

#endif

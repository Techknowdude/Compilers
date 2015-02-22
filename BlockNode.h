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

    private:
    AstNode* _decls;
    AstNode* _stmts;
};

#endif

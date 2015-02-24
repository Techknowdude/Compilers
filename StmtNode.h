/*
 * =====================================================================================
 *
 *    Description:	Statement Node base class for AST
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
#ifndef H_STMTNODE
#define H_STMTNODE

#include "AstNode.h"

class StmtNode : public AstNode
{
    public:
        StmtNode() : AstNode()
        {

        }
        virtual int ComputeOffsets(int base) { return base; }
};

#endif

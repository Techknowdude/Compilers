/*
 * =====================================================================================
 *
 *    Description:	Statements node for AST
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
    virtual int ComputeOffsets(int base)
    {
        int offset = base;
        list<StmtNode*>::iterator iter;
        for(iter = _stmts.begin(); iter != _stmts.end(); ++iter)
        {
            offset = (*iter)->ComputeOffsets(offset);
        }
        return base;
    }  

    virtual void GenerateCode()
    {
        list<StmtNode*>::iterator iter;

        for(iter = _stmts.begin(); iter != _stmts.end(); ++iter)
            (*iter)->GenerateCode();
    }

    private:
    list<StmtNode*> _stmts;
};

#endif

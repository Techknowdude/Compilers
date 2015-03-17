/*
 * =====================================================================================
 *
 *    Description:	Parameters Node for AST
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
#ifndef H_PARAMSNODE
#define H_PARAMSNODE

#include <list>
using std::list;

#include "ExprNode.h"
#include "Decl.h"

class ParamsNode : public virtual Decl
{
    public:
        ParamsNode(ExprNode* param = nullptr);
        void AddNode(ExprNode* newNode);

        virtual string toString();

        virtual string GetName() { return ""; }

        virtual int ComputeOffsets(int base)
        {
            list<ExprNode*>::iterator iter;
            for(iter = _paramList.begin(); iter != _paramList.end(); ++ iter)
            {
                (*iter)->ComputeOffsets(base);
            }
            return base;
        }
        virtual void GenerateCode()
        {
            list<ExprNode*>::iterator iter;

            for(iter = _paramList.begin(); iter != _paramList.end(); ++iter)
                (*iter)->GenerateCode();
        }
        
    protected:
        list<ExprNode*>_paramList;
};

#endif

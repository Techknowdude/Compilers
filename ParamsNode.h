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

#include "ParamNode.h"
#include "Decl.h"

class ParamsNode : public virtual Decl
{
    public:
        ParamsNode(ParamNode* param = nullptr);
        void AddNode(ParamNode* newNode);

        virtual string toString();

        virtual string GetName() { return ""; }

        virtual int ComputeOffsets(int base)
        {
            list<ParamNode*>::iterator iter;
            for(iter = _paramList.begin(); iter != _paramList.end(); ++ iter)
            {
                (*iter)->ComputeOffsets(base);
            }
            return base;
        }
        virtual void GenerateCode()
        {

        }
    protected:
        list<ParamNode*> _paramList;
};

#endif

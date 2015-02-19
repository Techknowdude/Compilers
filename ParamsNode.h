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
    protected:
        list<ParamNode*> _paramList;
};

#endif

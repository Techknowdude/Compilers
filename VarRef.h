#ifndef H_VARREF
#define H_VARREF

#include <string>
#include <list>
#include "ExprNode.h"
using std::string;
using std::list;

#include "ExprNode.h"

class VarRef : public ExprNode
{
    public:
        VarRef();
        VarRef(VarRef* varRef);
        void AddRef(VarRef* varRef);
        virtual string toString();
        virtual string GetID();
        virtual string GetArrVal();
    protected:
        list<VarRef*> _varRefs;
};
#endif

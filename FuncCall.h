#ifndef H_FUNCCALL
#define H_FUNCCALL

#include "StmtNode.h"
#include "ParamsNode.h"
#include "Symbol.h"

//class ParamsNode;

class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(Symbol* ident, ParamsNode* params);

        virtual string toString();

    protected:
        Symbol* _ident;
        ParamsNode* _params;
};

#endif

#ifndef H_FUNCCALL
#define H_FUNCCALL

#include "StmtNode.h"
#include "ParamsNode.h"
#include "Symbol.h"
#include "ExprNode.h"

//class ParamsNode;

class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(Symbol* ident, ParamsNode* params);
        virtual string toString();
        Decl* GetType(); // return the ident->GetType()

    protected:
        Symbol* _ident;
        ParamsNode* _params;
};

#endif

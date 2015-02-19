#ifndef H_INTTNODE
#define H_INTNODE

#include <string>
using std::string;

#include "ExprNode.h"
#include "SymbolTable.h"
#include "Symbol.h"

extern SymbolTable* symbolTableRoot;

class IntNode : public ExprNode
{
    public:
        IntNode(int intVal);
        string toString();

        int GetVal();

        Decl* GetType() { return _type; }


        
    protected:
        int _intVal;
        Decl* _type;
};
#endif

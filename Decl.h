#ifndef H_DECLBASE
#define H_DECLBASE

#include "AstNode.h"

class Decl : public AstNode
{
    public:
       virtual Decl* GetBaseType() { return this; }
       virtual bool IsType() { return false; }
       virtual bool IsFunc() { return false; }
       virtual bool IsInt() { return false; }
       virtual bool IsFloat() { return false; }
       virtual bool IsStruct() { return false; }
       virtual bool IsArray() { return false; }
    protected:
};

#endif

#ifndef H_DECLBASE
#define H_DECLBASE

#include "AstNode.h"

class Decl : public virtual AstNode
{
    public:
        virtual Decl* GetBaseType() { return this; }
        virtual bool IsType() { return false; }
        virtual bool IsFunc() { return false; }
        virtual bool IsInt() { return false; }
        virtual bool IsChar() { return false; }
        virtual bool IsFloat() { return false; }
        virtual bool IsStruct() { return false; }
        virtual bool IsArray() { return false; }

        virtual string GetName() = 0;

        virtual string toString()
        {
            return "";
        }
    protected:
};

#endif

#ifndef H_BASEDECL
#define H_BASEDECL

#include "Decl.h"
#include "ExprNode.h"
#include "Symbol.h"

class BaseDecl : public Decl
{
    public:
        BaseDecl(Symbol* ident, int size, bool isFloat);

        virtual bool IsInt() { return !_isFloat; }
        virtual bool IsFloat() { return _isFloat; }
        virtual bool IsChar() { return _size == 1; }
        virtual bool IsType() { return true; }

        int Size() { return _size; }
        virtual string GetName();
    protected:
        Symbol* _ident;
        int _size;
        bool _isFloat;
};

#endif

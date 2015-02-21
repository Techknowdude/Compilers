#ifndef H_FUNCDEF
#define H_FUNCDEF

#include "VarDecl.h"

class FuncDef : public VarDecl
{
    public:
        virtual bool IsFloat() {return false;}
        virtual bool IsChar() {return false;}
        virtual bool IsInt() {return false;}
        virtual bool IsStruct() {return false;}
        virtual bool IsType() {return true;}
        virtual bool IsArray() {return false;}
        virtual bool IsFunc() {return true;}

};

#endif

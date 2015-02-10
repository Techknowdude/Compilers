#ifndef H_PARAMSSPEC
#define H_PARAMSSPEC

#include <list>
using std::list;
#include "VarDecl.h"
#include "Paramspec.h"

class Paramsspec 
{
    public:
        Paramsspec(Paramspec* varDecl);
        void AddNode(Paramspec* varDecl);
        string toString();
    protected:
        list<Paramspec*> _decls;
};

#endif


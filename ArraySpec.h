#ifndef H_ARRAYSPEC
#define H_ARRAYSPEC

#include <list>
using std::list;

#include "VarDecl.h"

class ArraySpec : public VarDecl
{
    public:
        ArraySpec(int val);
        void AddSpec(int val);

        string toString();
    protected:
        list<int> _arraySpecs;
};

#endif

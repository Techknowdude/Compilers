#ifndef H_ARRAYSPEC
#define H_ARRAYSPEC

#include <string>
using std::string;
#include <list>
using std::list;

class ArraySpec
{
    public:
        ArraySpec();
        void AddSpec(int val);
        int NumSpecs();
        string toString();
    protected:
        list<int> _arraySpecs;

};

#endif

#ifndef H_DECLSNODE
#define H_DECLSNODE

#include <string>
#include <list>
using std::list;
using std::string;

#include "Decl.h"

class DeclsNode : public Decl
{

    public:
        DeclsNode(Decl* node);
        virtual string toString();

        void AddNode(Decl* newNode);
        virtual string GetName() { return ""; }

    protected:
        list<Decl*> _decls;
};

#endif

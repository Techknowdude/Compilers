#ifndef H_ASTNODE
#define H_ASTNODE
#include <string>
using std::string;

class AstNode
{
    public:
    virtual string toString() = 0;

    // Since only some will throw errors, default to no error
    virtual bool HasSemanticError()
    {   
        return false;
    }
    virtual string GetError()
    {
        return "Ast Error";
    }
    private:

};

#endif

#ifndef H_SCANSTMT
#define H_SCANSTMT

#include "StmtNode.h"
#include "VarRef.h"

class ScanStmt : public StmtNode
{
    public:
        ScanStmt(Symbol* varRef);

        string toString();
    protected:
        Symbol* _varRef;
};

#endif

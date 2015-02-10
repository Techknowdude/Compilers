#ifndef H_SCANSTMT
#define H_SCANSTMT

#include "StmtNode.h"
#include "VarRef.h"

class ScanStmt : public StmtNode
{
    public:
        ScanStmt(VarRef* varRef);

        string toString();
    protected:
        VarRef* _varRef;
};

#endif

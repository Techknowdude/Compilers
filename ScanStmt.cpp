#include "ScanStmt.h"

ScanStmt::ScanStmt(VarRef* varRef) : _varRef(varRef)
{
}

string ScanStmt::toString()
{
    return "SCAN: " + _varRef->toString();
}

#include "ScanStmt.h"

ScanStmt::ScanStmt(Symbol* varRef) : _varRef(varRef)
{
}

string ScanStmt::toString()
{
    return "SCAN: " + _varRef->toString();
}

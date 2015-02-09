#include "IfStmt.h"
        
IfStmt::IfStmt(ExprNode* expr, StmtNode* stmt) : _expr(expr), _stmt(stmt)
{

}

string IfStmt::toString()
{
    string stringVal = "(IF: ";
    if(_expr != nullptr)
        stringVal += _expr->toString() + "\n";
    if(_stmt != nullptr)
        stringVal += _stmt->toString() + "\n";
    stringVal += ")";
    return stringVal;
}

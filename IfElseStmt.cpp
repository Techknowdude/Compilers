#include "IfElseStmt.h"
        
IfElseStmt::IfElseStmt(ExprNode* expr, StmtNode* ifStmt, StmtNode* elStmt) : 
    _expr(expr), _ifStmt(ifStmt), _elStmt(elStmt)
{

}

string IfElseStmt::toString()
{
    string stringVal = "(IF: ";
    if(_expr != nullptr)
        stringVal += _expr->toString() + "\n";
    if(_ifStmt != nullptr)
        stringVal += _ifStmt->toString() + "\n";
    if(_elStmt != nullptr)
        stringVal += "ELSE:\n" + _elStmt->toString() + "\n";
    stringVal += ")";
    return stringVal;
}

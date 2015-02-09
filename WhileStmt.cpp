#include "WhileStmt.h"

WhileStmt::WhileStmt(ExprNode* expr, StmtNode* stmt) : _expr(expr), _stmt(stmt)
{

}

string WhileStmt::toString()
{
    return "(WHILE: " + _expr->toString() + "\n" + _stmt->toString() + "\n)";
}

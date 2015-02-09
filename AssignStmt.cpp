#include "AssignStmt.h"

AssignStmt::AssignStmt(VarRef* varRef, ExprNode* expr) : _varRef(varRef), _expr(expr)
{

}

string AssignStmt::toString()
{
    return "(ASSIGN: " + _varRef->toString() + " = " + _expr->toString() + ")";
}

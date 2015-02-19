#include "AssignStmt.h"

AssignStmt::AssignStmt(VarRef* varRef, ExprNode* expr) 
    : _varRef(varRef), _expr(expr), _err(), _hasErr(false)
{

    CheckForError();
}

string AssignStmt::toString()
{
    return "(ASSIGN: " + _varRef->toString() + " = " + _expr->toString() + ")";
}

void AssignStmt::CheckForError()
{
    Decl* lhs = _varRef->GetType();
    Decl* rhs = _expr->GetType();

   if(lhs != rhs) 
   {
        // Check for int, float, char
        if(lhs->IsChar())
        {
            if(!rhs->IsChar())
            {
                _err = "Cannot assign " + rhs->GetName() + " to a char";
                _hasErr = true;
            }
        }
        else if(lhs->IsInt())
        {
            if(!rhs->IsInt() && !rhs->IsChar())
            {
                _err = "Cannot assign " + rhs->GetName() + " to a int";
                _hasErr = true;
            }
        } 
        else if(lhs->IsFloat())
        {
            if(!rhs->IsFloat() && !rhs->IsInt() && !rhs->IsChar())
            {
                _err = "Cannot assign " + rhs->GetName() + " to a float";
                _hasErr = true;
            }
        }
        else
        {
            _err = "Cannot assign " + rhs->GetName() + " to a " + lhs->GetName();
            _hasErr = true;
        }
   }

}

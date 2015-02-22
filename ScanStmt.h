/*
 * =====================================================================================
 *
 *    Description:	Scan Statement node for AST
 *
 *        Version:  1.0
 *        Created:  02/21/2015 04:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Brandon Westmoreland (OIT), brandon.westmoreland@oit.edu
 *   Organization:  Oregon Tech
 *
 * =====================================================================================
 */
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

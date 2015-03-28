/*
 * =====================================================================================
 *
 *    Description:	Print Statement node for AST
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
#ifndef H_SCANNODE
#define H_SCANNODE

#include "StmtNode.h"
#include "VarRef.h"

class ScanNode : public StmtNode
{
    public:
    ScanNode(VarRef* ref);
    string toString();
    virtual int ComputeOffsets(int base)
    {
        return _ref->ComputeOffsets(base);
    }
    
    virtual void GenerateCode()
    {
        EmitString("scanf(\"%i\", ((int*)(&Memory[Frame_Pointer + " + std::to_string(_ref->GetOffset()) + "])));\n");
    }

    protected:
    VarRef* _ref;
};

#endif

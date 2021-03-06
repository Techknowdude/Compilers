/*
 * =====================================================================================
 *
 *    Description:	Function Declaration Node for AST
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
#ifndef H_FUNCDECL
#define H_FUNCDECL

#include "DeclsNode.h"
#include "FuncDef.h"
#include "FuncHeader.h"
#include "StmtsNode.h"

class FuncDecl : public FuncDef
{
    public:
        FuncDecl(FuncHeader* header, StmtsNode* stmt = nullptr);
        FuncDecl(FuncHeader* header, DeclsNode* decls, StmtsNode* stmts);
        
        string toString();
        virtual Decl* GetBaseType()
        {
            return _header->GetBaseType();
        }
        
        virtual bool IsFloat() {return GetBaseType()->IsFloat();}
        virtual bool IsChar() {return GetBaseType()->IsChar();}
        virtual bool IsInt() {return GetBaseType()->IsInt();}
        virtual bool IsStruct() {return GetBaseType()->IsStruct();}
        virtual bool IsType() {return false;}
        virtual bool IsArray() {return GetBaseType()->IsArray();}
        virtual bool IsFunc() {return GetBaseType()->IsFunc();}
        virtual string GetName() {return _header->GetName(); }

        Symbol* GetIdentifier() { return _header->GetIdentifier();}

        virtual int ComputeOffsets(int base)
        {
            // temp holder for offsets
            int offset = base;
            
            int paramOffset = _header->ComputeOffsets(0);

            // compute decls offset
            if(_decls != nullptr)
                offset = _decls->ComputeOffsets(0);
            // get size of function based on decls
            _size = offset - paramOffset;

            // compute stmts offsets
            if(_stmts != nullptr)
                offset = _stmts->ComputeOffsets(offset);
            return base;
        }

        virtual void GenerateCode()
        {
            // start function
            StartFunctionOutput();

            EmitString("int " + GetName() + "()\n");
            EmitString("{\n");
            
            if(_decls != nullptr)
                _decls->GenerateCode();
            if(_stmts != nullptr)
                _stmts->GenerateCode();

            EmitString("/* Deallocate local var space */\n");
            if(_decls != nullptr)
                EmitString("Stack_Pointer -= " + std::to_string(_decls->GetSize()) + ";\n");
            EmitString("}\n");
            // end function
            EndFunctionOutput();
        }
    protected:
        FuncHeader* _header;
        StmtsNode* _stmts;
        DeclsNode* _decls;
};

#endif

/*
 * =====================================================================================
 *
 *    Description:	Parameters Node for AST
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
#ifndef H_PARAMSNODE
#define H_PARAMSNODE

#include <list>
using std::list;

#include "ExprNode.h"
#include "codegen.h"
#include "Decl.h"
#include "Paramsspec.h"
#include "VarDecl.h"

class ParamsNode : public virtual Decl
{
    public:
        ParamsNode(ExprNode* param = nullptr);
        void AddNode(ExprNode* newNode);

        virtual string toString();

        virtual string GetName() { return ""; }

        virtual int ComputeOffsets(int base)
        {
            
            list<ExprNode*>::iterator iter;
            for(iter = _paramList.begin(); iter != _paramList.end(); ++ iter)
            {
                (*iter)->ComputeOffsets(base);
                int size = (*iter)->GetSize();
                if(size < 4) // make sure it's word aligned.
                    size = 4;
                _size += size;
            }
            return base;
        }
        virtual void GenerateCode()
        {
            list<ExprNode*>::iterator iter;
            
            for(iter = _paramList.begin(); iter != _paramList.end(); ++iter)
            {
                // push each item onto stack
                if((*iter)->GetType()->IsInt())
                {
                    EmitIntStackRef();
                }
                else if((*iter)->GetType()->IsFloat())
                {
                    EmitFloatStackRef();
                }
                EmitString(" = ");
                (*iter)->GenerateCode();
                EmitString(";\n");

                // adjust stack pointer
                EmitString("Stack_Pointer += " + std::to_string((*iter)->GetSize()) + ";\n");
            }
        }
        
        int GetNumber() {return _paramList.size();}


        bool Equals(Paramsspec* other)
        {
            bool allMatch = true;
            
            if(other == nullptr)
            {
                allMatch = _paramList.size() == 0;
            }
            else
            {
                // if they are the wrong size, they do not match
                if(other->GetNumber() != _paramList.size())
                    return false;
                // iterate through each list and compare
                list<ExprNode*>::iterator thisIter = _paramList.begin();
                list<VarDecl*>::iterator thatIter = other->GetIterStart();
                for(;allMatch && thisIter != _paramList.end() && thatIter != other->GetIterEnd(); )
                {
                    // check type matching
                    allMatch = (*thisIter)->GetType()->GetBaseType()->toString() == (*thatIter)->GetType()->GetBaseType()->toString();

                    ++thatIter;
                    ++thisIter;
                }
            }
            return allMatch;
        }
        
        string GetParamTypes() 
        {
            string nameList;
            list<ExprNode*>::iterator iter;
            for(iter = _paramList.begin(); iter != _paramList.end();)
            {
                nameList += (*iter)->GetType()->GetBaseType()->toString();
                ++iter;
                if(iter != _paramList.end())
                    nameList += ", ";
            }
            return nameList;
        }
    protected:
        list<ExprNode*>_paramList;
};

#endif

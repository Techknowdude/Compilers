/*
 * =====================================================================================
 *
 *    Description:	Parameter Spec node for AST
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
#ifndef H_PARAMSSPEC
#define H_PARAMSSPEC

#include <list>
using std::list;
#include "VarDecl.h"
#include "AstNode.h"

class Paramsspec : public AstNode
{
    public:
        Paramsspec(VarDecl* varDecl);
        void AddNode(VarDecl* varDecl);
        string toString();
        virtual int ComputeOffsets(int base)
        {
            int offset = base;

            list<VarDecl*>::iterator iter;

            for(iter = _decls.begin(); iter != _decls.end(); ++iter)
            {
                (*iter)->ComputeOffsets(offset - (*iter)->GetSize());
                offset -= (*iter)->GetSize();
            }
            return offset;
        }

        virtual void GenerateCode()
        {

        }

        int GetNumber() {return _decls.size();}
        list<VarDecl*>::iterator GetIterStart() {return _decls.begin();}
        list<VarDecl*>::iterator GetIterEnd() {return _decls.end();}

        bool Equals(Paramsspec* other)
        {
            bool areEqual = true;
            if(_decls.size() != other->_decls.size())
            {
                areEqual = false;
            }
            else
            {
                list<VarDecl*>::iterator thisIter = _decls.begin();
                list<VarDecl*>::iterator thatIter = other->_decls.begin();
                
                for(;areEqual && thisIter != _decls.end() && thatIter != other->_decls.end(); ++thisIter, ++thatIter)
                {
                    areEqual = (*thisIter)->Equals((*thatIter));
                }
            }
            return areEqual;
        }

        string GetParamTypes() 
        {
            string nameList;
            list<VarDecl*>::iterator iter;
            for(iter = _decls.begin(); iter != _decls.end();)
            {
                nameList += (*iter)->GetType()->GetBaseType()->toString();
                ++iter;
                if(iter != _decls.end())
                    nameList += ", ";
            }
            return nameList;
        }
    protected:
        list<VarDecl*> _decls;
};

#endif


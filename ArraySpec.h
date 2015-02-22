/*
 * =====================================================================================
 *
 *    Description:	Array Spec node for AST
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
#ifndef H_ARRAYSPEC
#define H_ARRAYSPEC

#include <string>
using std::string;
#include <list>
using std::list;

class ArraySpec
{
    public:
        ArraySpec();
        void AddSpec(int val);
        int NumSpecs();
        string toString();
    protected:
        list<int> _arraySpecs;

};

#endif

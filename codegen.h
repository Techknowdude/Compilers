#ifndef H_CODEGEN
#define H_CODEGEN

//*******************************************************
// Purpose: Utility functions for code generation
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>

bool InitOutput(const char *outfileName);
bool FinalizeOutput();
void StartFunctionOutput();
void EndFunctionOutput();
void EmitString(std::string str);
void EmitFloat(double val);
void RewriteFunctions();
std::string GenerateLabel();
void EmitPrintTemp();
void EmitPrintTemp_F();

//******************************************************
// Code added by Brandon Westmoreland 
// Date: 3/3/15
//

void EmitIntRef(int offset);
void EmitIntStackRef();
void EmitFloatRef(int offset);
void EmitFloatStackRef();
#endif

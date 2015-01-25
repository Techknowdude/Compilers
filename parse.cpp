#include <iostream>
#include "lex.h"
#include "parse.h"
#include "tokens.h"
using std::cout;
using std::endl;

int yylval = 0;
int token = -1;
int oldToken = -1;

//*******************************************
void Error(std::string expecting)
{
    std::cout << "Found " << yytext << " when expecting a " << expecting;
    std::cout << " in line " << yylineno << std::endl;
}
//*******************************************
int GetToken()
{
    if (token > 0)
    {
        oldToken = token;
        token = -1;
    } else 
    {
        oldToken = yylex();
    }

    return oldToken;
}
//*******************************************
void UnGetToken()
{
    token = oldToken;
}
//*******************************************
bool FindPROG()
{
    if(!FindSTMTS()) return false;

    int token = GetToken();
    if(token != END_TOKEN)
    {
	Error("'end'");
	return false;
    }
    return true;
}

//*****************************************
bool FindSTMTS()
{
	int token = GetToken();
	if(token == END_TOKEN) return true;
	UnGetToken();	
	
	// Find Stmt
	while(FindSTMT())
	{
		token = GetToken();
		UnGetToken();
		if(token == END_TOKEN) 
		{
			break;
		}
		else if (token == 0) return false;
	}

	return true;
}

//******************************************
bool FindSTMT()
{
	int token;
	if(FindEXPR()) 
	{
		token = GetToken();
		if(token != ';')
		{
			Error("';'");
			if(!FindError()) return false;
			return true;
		}
		cout << "Found a statement" << endl;
		return true;
	}
	if(!FindError()) return false;
	
	return true;
}

//******************************************
bool FindError()
{
	int token = GetToken();
	while(token != END_TOKEN && token != 0 && token != ';')
	{
		token = GetToken();
	}
	if(token == END_TOKEN)
		UnGetToken();
	if(token == END_TOKEN || token == ';')	return true;
	return false;
}

//******************************************
bool FindEXPR()
{
        int token = GetToken();
        if(token == '(') // Check for -> (EXPR)
        {
                if(!FindEXPR()) return false;
		
		token = GetToken();
		if(token != ')')
		{
			UnGetToken();
			Error("')'");
			return false;
		}

		if(FindEXPR_P()) return true; // Optional EXPR'
        }
	else // Check for -> TERM
	{
		UnGetToken(); //may not have (

		// Check for TERM
		// if not found, report ( not found
		if(!FindTERM())	return false;
	}
	return true;
}

//******************************************
bool FindEXPR_P()
{
	// Check PLUSOP (EXPR) EXPR_P

	if(!FindPLUSOP()) return true;
	
	int token = GetToken();
	if(token != '(')
	{
		UnGetToken();
		Error("'('");
		return false;
	}

	if(!FindEXPR()) return false;
	token = GetToken();
	if(token != ')')
	{
		UnGetToken();
		Error("')'");
		return false;
	}
	
	if(FindEXPR_P()) return true;
	return true;
}

//*****************************************
bool FindTERM()
{
	// Check for [EXPR]
	int token = GetToken();
	if(token == '[')
	{
		if(!FindEXPR()) return false;
		token = GetToken();
		if(token != ']')
		{
			UnGetToken();
			Error("']'");
			return false;
		}

		if(!FindTERM_P()) return false;
	}
	else if(token == INT_VAL) // Check for num (int)
	{
		return true;
	}
	else
	{
		UnGetToken();
		Error("'TERM'");
		return false;
	}

	return true;
}

//******************************************
bool FindPLUSOP()
{
	int token = GetToken();
	if(token != '+' && token != '-') 
	{
		UnGetToken();
		return false;
	}
	return true;
}


//******************************************
bool FindTERM_P()
{
        if(!FindTIMESOP()) return true;

	int token = GetToken();
	if(token != '[')
	{
		UnGetToken();
		Error("'['");
		return false;
	}
	if(!FindEXPR()) return false;
	token = GetToken();
	if(token != ']')
	{
		UnGetToken();
		Error("']'");
		return false;
	}
	if(FindTERM_P()) return true;

	return true;
}

//******************************************
bool FindTIMESOP()
{
	int token = GetToken();
	if( token == '*' || token == '/') return true;

	UnGetToken();
	return false;
}
        

/*******************************************
bool FindExample()
{
    if (!FindPART1()) return false;
    
    int token = GetToken();
    if (token != '+')
    {
        UnGetToken();
        return false;
    }

    if (!FindPART2()) return false;

    return true;
}
*/


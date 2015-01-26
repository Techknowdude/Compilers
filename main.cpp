// parser
//
// Phil Howard
//
// pwhoward@
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Symbol.h"
#include "SymbolTable.h"
#include "lex.h"
#include "langparse.h"

extern void *yyast_root;
    
int main(int argc, char **argv)
{
    std::cout << "Brandon Westmoreland" << std::endl;

    symbolTableRoot = new SymbolTable();

    const char *outfile_name;
    int result = 0;
    std::streambuf *cout_buf = std::cout.rdbuf();


    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    if (argc > 2)
    {
        outfile_name = argv[2];
    } else {
        outfile_name = "/dev/tty";
    }

    std::ofstream output(outfile_name);
    if (!output.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << outfile_name << "\n";
        exit(-1);
    }
    std::cout.rdbuf(output.rdbuf());

    result = yyparse();
    while (yyast_root != NULL)
    {
        if (result == 0)
        {
            output << "Successful compilation\n";
        } else {
            output << "Errors in compile\n";
            return result;
        }

        result = yyparse();
    }

    output.close();
    std::cout.rdbuf(cout_buf);

    return result;
}

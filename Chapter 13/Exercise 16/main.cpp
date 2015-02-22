#include <iostream>

#include "Parser.hpp"
#include "Lexer.hpp"
#include "Error.hpp"

std::map<std::string,double> table;

int main(int argc, char* argv[])
{
	// insert pre-defined names:
	table["pi"] = 3.1415926535897932385;
	table["e"]  = 2.7182818284590452354;

	while (std::cin) {
		Lexer::get_token();
		if (Lexer::curr_tok == Lexer::END) break;
		if (Lexer::curr_tok == Lexer::PRINT) continue;
		std::cout << Parser::expr(false) << '\n';
	}

	return Error::no_of_errors;	
}
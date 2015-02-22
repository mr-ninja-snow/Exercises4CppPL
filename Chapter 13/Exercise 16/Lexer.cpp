#include <iostream>
#include "Lexer.hpp"
#include "Error.hpp"

Lexer::Token_value Lexer::curr_tok;
double Lexer::number_value;
std::string Lexer::string_value;

Lexer::Token_value Lexer::get_token()
{
	char ch = 0;
	std::cin>>ch;

	switch (ch) {
	case 0:
		return END;
	case ';':
		return curr_tok=PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok=Token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		std::cin.putback(ch);
		std::cin >> number_value;
		return curr_tok=NUMBER;
	default:			// NAME, NAME =, or error
		if (isalpha(ch)) {
			std::cin.putback(ch);
			std::cin>>string_value;
			std::cout<<"debug: " << string_value << "\n";
			return curr_tok=NAME;
		}
		Error::error("bad token");
		return curr_tok=PRINT;
	}
}
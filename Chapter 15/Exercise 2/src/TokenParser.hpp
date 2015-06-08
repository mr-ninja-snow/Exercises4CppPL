#ifndef TOKENPARSER_HPP__
#define TOKENPARSER_HPP__

#include <string>

#include "desk_calc.hpp"

namespace token_parser
{

enum eTokenValue {
	NAME,
	NUMBER,
	END,
	PLUS    ='+',
	MINUS   ='-',
	MUL     ='*',
	DIV     ='/',
	PRINT   =';',
	ASSIGN  ='=',
	LP      ='(',
	RP      =')'
};

eTokenValue get_token();

bool CheckForPrintCmd();
bool CheckForExitCmd();

eTokenValue CurrentToken();

double NumberValue();
std::string StringValue();

} // namespace token_parser

#endif /* end of include guard: TOKENPARSER_HPP__ */

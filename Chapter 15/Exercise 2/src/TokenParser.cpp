#include<sstream>

#include "TokenParser.hpp"
#include "desk_calc_err.hpp"


#include<iostream>

namespace token_parser
{

namespace token_parser_impl
{
eTokenValue g_currToken = PRINT;
double      g_numberValue;
std::string g_stringValue;
}

bool CheckForExitCmd()
{
	if (token_parser_impl::g_currToken == END) { return true; }
	return false;
}

bool CheckForPrintCmd()
{
	if (token_parser_impl::g_currToken == PRINT) { return true; }
	return false;
}

eTokenValue CurrentToken()
{
	return token_parser_impl::g_currToken;
}

double NumberValue()
{
	return token_parser_impl::g_numberValue;
}

std::string StringValue()
{
	return token_parser_impl::g_stringValue;
}

eTokenValue get_token()
{
	char ch;

	do	// skip whitespace except '\en'
	{
		if(! std::cin.get(ch)) { return token_parser_impl::g_currToken = END; }
	}
	while (ch != '\n' && std::isspace(ch));

	switch (ch)
	{
	case ';':
	case '\n':
	{
		return token_parser_impl::g_currToken = PRINT;
	}
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
	{
		return token_parser_impl::g_currToken = eTokenValue(ch);
	}
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
	{
		std::cin.putback(ch);
		std::cin >> token_parser_impl::g_numberValue;

		return token_parser_impl::g_currToken = NUMBER;
	}
	default:			// NAME, NAME=, or error
	{
		if (std::isalpha(ch))
		{
			token_parser_impl::g_stringValue = ch;

			while ( std::cin.get(ch) && std::isalnum(ch))
			{
				token_parser_impl::g_stringValue += ch;	// g_stringValue.push_back(ch);
			}				// to work around library bug

			std::cin.putback(ch);

			return token_parser_impl::g_currToken = NAME;
		}

		{
			std::stringstream ss;
			ss << "'" << ch << "' is a bad token!";
			dc_errors::error(ss.str().c_str());
		}

		return token_parser_impl::g_currToken = PRINT;
	}
	} // switch (ch)
}

} // namespace token_parser
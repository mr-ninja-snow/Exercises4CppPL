#include<iostream>

#include "desk_calc.hpp"

// @V ToDo: remove the implementation details of the dc from token parser implementation (g_bGetNextToken)
// @V ToDo: look into add Doxygen parameters to all of the functions presented
// @V ToDo: look into reading line by line from stdin and going to the next line if there is an error

namespace desk_calc
{

namespace desk_calc_impl
{

bool g_bGetNextToken = false;

// std::map<std::string,double> g_table;

double prim()		// handle primaries
{
	if (g_bGetNextToken)
	{
		g_bGetNextToken = false;
		token_parser::get_token();
	}

	switch (token_parser::CurrentToken())
	{
	case token_parser::NUMBER:		// floating-point constant
	{
		double v = token_parser::NumberValue();
		g_bGetNextToken = false;
		token_parser::get_token();

		return v;
	}
	case token_parser::NAME:
	{
		// double& v = g_table[token_parser::StringValue()];

		if (token_parser::get_token() == token_parser::ASSIGN)
		{
			g_bGetNextToken = true;
			v = expr();
		}

		return v;
	}
	case token_parser::MINUS:		// unary minus
	{
		g_bGetNextToken = true;
		return -prim();
	}
	case token_parser::LP:
	{
		g_bGetNextToken = true;
		double e = expr();

		if (token_parser::CurrentToken() != token_parser::RP) { return dc_errors::error(") expected"); }
		g_bGetNextToken = false;
		token_parser::get_token();		// eat ')'

		return e;
	}
	default:
	{
		return dc_errors::error("primary expected");
	}
	} // switch (token_parser::CurrentToken())
}

double term()		// multiply and divide
{
	double left = prim();

	for (;;)
	{
		switch (token_parser::CurrentToken())
		{
		case token_parser::MUL:
		{
			g_bGetNextToken = true;
			left *= prim();
			break;
		}
		case token_parser::DIV:
		{
			g_bGetNextToken = true;
			if (double d = prim())
			{
				left /= d;
				break;
			}

			return dc_errors::error("divide by 0");
		}
		default:
		{
			return left;
		}
		} // switch (token_parser::CurrentToken())
	}
}

double expr()		// add and subtract
{
	double left = term();

	for (;;)
	{
		switch (token_parser::CurrentToken())
		{
		case token_parser::PLUS:
		{
			g_bGetNextToken = true;
			left += term();
			break;
		}
		case token_parser::MINUS:
		{
			g_bGetNextToken = true;
			left -= term();
			break;
		}
		default:
		{
			return left;
		}
		} // switch (token_parser::CurrentToken())
	}
}
} // namespace desk_calc_impl

int calculator()
{
	// desk_calc_impl::g_table["pi"] = 3.1415926535897932385;	// insert predefined names
	// desk_calc_impl::g_table["e"] = 2.7182818284590452354;

	while (std::cin)
	{
		desk_calc_impl::g_bGetNextToken = false;
		token_parser::get_token();

		if (token_parser::CheckForExitCmd()) { break; }
		if (token_parser::CheckForPrintCmd()) { continue; }

		std::cout << desk_calc_impl::expr() << '\n';
	}

	return dc_errors::g_NoOfErrors; // @VS move to a getter function
}

} // namespace desk_calc
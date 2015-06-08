#include <iostream>
#include "desk_calc_err.hpp"


namespace dc_errors
{

int g_NoOfErrors;

double error(const char* s)
{
	g_NoOfErrors++;
	std::cerr << "error: " << s << '\n';
	return 1;
}

} // namespace dc_errors
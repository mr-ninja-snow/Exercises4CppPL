#include <iostream>
#include "Error.hpp"

int Error::no_of_errors;

double Error::error(const char* s)
{
	std::cerr << "error: " << s << '\n';
	no_of_errors++;
	return 1;
}

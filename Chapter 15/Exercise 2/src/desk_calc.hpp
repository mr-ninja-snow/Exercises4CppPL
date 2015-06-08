#ifndef DESK_CALC_HPP__
#define DESK_CALC_HPP__

#include <string>
#include <cctype>
// #include<map>

#include "desk_calc_err.hpp"
#include "TokenParser.hpp"

namespace desk_calc
{

int calculator();

namespace desk_calc_impl
{
// extern std::map<std::string,double> g_table;

double prim();		// handle primaries

double term();		// multiply and divide

double expr();		// add and subtract
} // namespace desk_calc_impl

} // namespace desk_calc

#endif /* end of include guard: DESK_CALC_HPP__ */
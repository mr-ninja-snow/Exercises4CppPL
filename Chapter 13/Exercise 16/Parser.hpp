#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <map>

extern std::map<std::string,double> table;	// global; see sec9.???

namespace Parser {

	double prim(bool get);		// handle primaries
	double term(bool get);		// multiply and divide
	double expr(bool get);		// add and subtract

}

#endif
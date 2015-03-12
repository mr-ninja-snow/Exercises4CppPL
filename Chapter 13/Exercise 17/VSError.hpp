#ifndef VS_ERROR_HPP
#define VS_ERROR_HPP

#include <string>
#include <cstdarg>
#include <vector>

namespace VSError {

	const std::vector<std::string> SupportedFormatDirevtives{ "%s", "%c", "%d"};

	std::string vsError(const std::string msgWithFormat, ...);

}

#endif
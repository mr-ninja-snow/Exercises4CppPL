#include "VSError.hpp"

#include <iostream>
#include <algorithm>

namespace {

	int countSubstring(const std::string& str, const std::string& sub);

	const std::vector<std::string> GetOrderOfDirectives(const std::string& str)
	{

		std::vector<std::string> directiveOrder{0};

		for(const std::string directive : VSError::SupportedFormatDirevtives)
		{
			std::cout << "Debug : " << directive << "\n";

			// vstepano rework
			// directiveCount += countSubstring(str, directive);
		}

		return directiveCount;
	}

	// Helper functions 

	// Copied from http://rosettacode.org/wiki/Count_occurrences_of_a_substring#C.2B.2B
	// returns count of non-overlapping occurrences of 'sub' in 'str'
	int countSubstring(const std::string& str, const std::string& sub)
	{
		if (sub.length() == 0)
		{
			return 0;
		}

		int count = 0;
		for (size_t offset = str.find(sub);
			offset != std::string::npos;
			offset = str.find(sub, offset + sub.length()))
		{
			++count;
		}

		return count;
	}

}

namespace VSError {

	std::string vsError(const std::string msgWithFormat, ...)
	{
		va_list args;
		va_start (args, msgWithFormat);

		const std::vector<std::string> irectiveOrder{ GetOrderOfDirectives(msgWithFormat) };
		const unsigned char numberOfArgs{irectiveOrder.size()};

		std::cout << "Debug : numberOfArgs - " << int( numberOfArgs ) << "\n";

		for (int i=0; i < numberOfArgs; i++)
		{
			int num = va_arg (args,int); // get next argument
			sum += num;
		}

		va_end (args);
		
		return std::string{"foo"};
	}

}
#include "VSError.hpp"

#include <iostream>
#include <algorithm>      // std::find
#include <utility>      // std::pair

namespace {

	std::vector<size_t> getSubStrOffsets(const std::string& str, const std::string& sub);

	typedef std::pair<const std::string, std::vector<size_t>> directiveStrOffsets_t;

	const std::vector<std::pair<const std::string, size_t>> GetOrderOfDirectives(const std::string& str)
	{

		// std::vector<std::string> directiveOrder{0};
		std::vector<directiveStrOffsets_t> directivesAndOffsets{};
		size_t directiveCount{0};

		for(const std::string directive : VSError::SupportedFormatDirevtives)
		{
			std::cout << "Debug : " << directive << "\n";

			std::vector<size_t> offsets{ getSubStrOffsets( str, directive ) };
			directivesAndOffsets.push_back( directiveStrOffsets_t{ directive, offsets } );
			directiveCount += offsets.size();

			// vstepano rework
			// directiveCount += getSubStrOffsets(str, directive);
		}

		// vstepano almost similar names
		for( auto directiveOffsets : directivesAndOffsets)
		{
			std::cout << "Debug : \n\tdirective - " << directiveOffsets.first << "\n";
			for( auto offset : directiveOffsets.second)
			{
				std::cout << "\t\t\t" << offset << "\n";
			}
		}

		std::vector<std::pair<const std::string, size_t>> directiveOrderWithOffset{};

		for (int i = 0; i < directiveCount; ++i)
		{
			size_t minOffset{0};
			size_t dMinIndex{0};
			size_t dIndex{0};

			std::cout << "Debug : 1" << ", " << minOffset << ", " << dMinIndex << ", " << dIndex << "\n";
			for( auto directiveOffsets : directivesAndOffsets )
			{
				if ( directiveOffsets.second.size() )
				{
					if ( minOffset > directiveOffsets.second[0] )
					{
						dMinIndex = dIndex;
						minOffset = directiveOffsets.second[0];
					}
				}

				dIndex++;
			}
			std::cout << "Debug : 2" << ", " << minOffset << ", " << dMinIndex << ", " << dIndex << "; directiveOffsets.second.size() - "<< directivesAndOffsets[dMinIndex].second.size()<< "\n";

			directiveOrderWithOffset.push_back( std::pair<const std::string, size_t>{ directivesAndOffsets[dMinIndex].first, directivesAndOffsets[dMinIndex].second[0]} );

			std::cout << "Debug : 2,2\n";
			std::vector<size_t> tmp { directivesAndOffsets[dMinIndex].second };
			std::cout << "Debug : 2,3\n";
			tmp.erase( tmp.begin() + 1);
			std::cout << "Debug : 2,4\n";
			directivesAndOffsets[dMinIndex].second = tmp;

			// directivesAndOffsets[dMinIndex].second.erase( directivesAndOffsets[dMinIndex].second.begin() + 1);

			std::cout << "Debug : 3" << ", " << minOffset << ", " << dMinIndex << ", " << dIndex << "; directiveOffsets.second.size() - "<< directivesAndOffsets[dMinIndex].second.size()<< "\n";
		}

		for( auto directiveOffset : directiveOrderWithOffset)
		{
			std::cout << "Debug : \n\tdirective - " << directiveOffset.first << " its offset - " << directiveOffset.second << "\n";
		}

		return directiveOrderWithOffset;
	}

	// Helper functions 

	// Copied and modified from http://rosettacode.org/wiki/Count_occurrences_of_a_substring#C.2B.2B
	// returns count of non-overlapping occurrences of 'sub' in 'str'
	std::vector<size_t> getSubStrOffsets(const std::string& str, const std::string& sub)
	{
		if (sub.length() == 0)
		{
			return std::vector<size_t>{};
		}

		// int count = 0;
		std::vector<size_t> offsetsOfSubStr{};
		for (size_t offset = str.find(sub);
			offset != std::string::npos;
			offset = str.find(sub, offset + sub.length()))
		{
			// ++count;
			offsetsOfSubStr.push_back(offset);
		}

		return offsetsOfSubStr;
	}

}

namespace VSError {

	std::string vsError(const std::string msgWithFormat, ...)
	{
		va_list args;
		va_start (args, msgWithFormat);

		const std::vector<std::pair<const std::string, size_t>> irectiveOrder{ GetOrderOfDirectives(msgWithFormat) };
		const unsigned char numberOfArgs{ static_cast<unsigned char>( irectiveOrder.size() ) };

		std::cout << "Debug : numberOfArgs - " << int( numberOfArgs ) << "\n";

		// for (int i=0; i < numberOfArgs; i++)
		// {
		// 	int num = va_arg (args,int); // get next argument
		// 	sum += num;
		// }

		va_end (args);
		
		return std::string{"foo"};
	}

}
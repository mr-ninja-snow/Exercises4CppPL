#include "MacroProcessor.hpp"
#include <sstream> // std::stringstream
#include <cctype> // std::isalpha
#include <map>

namespace {

	enum
	{
		FIRST_TOKEN,
		SECOND_TOKEN
	};

	enum
	{
		FIRST_CHAR
	};

	std::map<std::string, std::string> g_DefineMap{};

	//------------------------------------------------------
	//Macro Processor functions
	//------------------------------------------------------

	bool ProcessMacro(std::vector<std::string>& tokens)
	{
		if (tokens.size() && tokens[FIRST_TOKEN] == std::string{"#define"})
		{
			std::cout << "Info : This is a macdo definition!\n";

			if (std::isalpha(tokens[SECOND_TOKEN][FIRST_CHAR]) && tokens.size() > 2)
			{
				std::cout << "Info : macro syntax is correct, saving macro...";


			}
			else
			{
				std::cout << "Info : Syntax error in macdo definition!\n";
			}
		}
		else
		{
			std::cout << "Info : This is NOT a macdo definition!\n";
		}

	}

	//------------------------------------------------------
	//Helper functions
	//------------------------------------------------------
	std::vector<std::string> tokenizeStringBySpace(std::string& inputString)
	{
		std::vector<std::string> tokens{};
		std::stringstream ss{inputString};
		std::string s{};

		while (getline(ss, s, ' '))
		{
			tokens.push_back(s);
			std::cout << "Debug: Extracted token from line: " << s << "\n";
		}

		return tokens;
	}

	//reused from answer to : http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	std::string trim(const std::string& str, const std::string& whitespace = " \t")
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return ""; // no content

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	//reused from answer to : http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	std::string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t")
	{
		// trim first
		auto result = trim(str, whitespace);

		// replace sub ranges
		auto beginSpace = result.find_first_of(whitespace);
		while (beginSpace != std::string::npos)
		{
			const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
			const auto range = endSpace - beginSpace;

			result.replace(beginSpace, range, fill);

			const auto newStart = beginSpace + fill.length();
			beginSpace = result.find_first_of(whitespace, newStart);
		}

		return result;
	}

}

void MacroProcessor::ProcessInput(std::string& inputString)
{
	inputString = reduce(inputString);
	std::cout << "Debug: removed all of the extra whitespace: " << inputString << "\n";

	std::vector<std::string> tokens{tokenizeStringBySpace(inputString)};

	ProcessMacro(tokens);
}


#include "MacroProcessor.hpp"
#include <iostream>
#include <sstream> // std::stringstream
#include <cctype> // std::isalpha, std::isspace
#include <vector>
#include <map>


namespace {

	enum
	{
		FIRST_TOKEN,
		SECOND_TOKEN,
		THIRD_TOKEN,
		FORTH_TOKEN
	};

	enum
	{
		FIRST_CHAR
	};

	typedef std::map<std::string, std::string> macro_map_t;
	macro_map_t g_DefineMap{};

	void dump_map(const macro_map_t& map);
	std::vector<std::string> tokenizeString(std::string const& inputString);

	//------------------------------------------------------
	//Macro Processor functions
	//------------------------------------------------------

	inline void SaveMacro( std::vector<std::string>& tokens )
	{
		if ( std::isalpha(tokens[THIRD_TOKEN][FIRST_CHAR]) && tokens.size() > 2 )
		{
			std::cout << "Info : macro syntax is correct, saving macro..." << "\n";

			std::string macroValue{};
			if ( tokens.size() > 3 )
			{
				for ( int i = FORTH_TOKEN + 1; i < tokens.size(); ++i )
				{
					macroValue += tokens[i];
				}
			}

			g_DefineMap[tokens[THIRD_TOKEN]] = macroValue;

			//debug map printout
			dump_map(g_DefineMap);
		}
		else
		{
			std::cout << "Info : Syntax error in macro definition!\n";
		}

	}

	inline void ExpandMacroInUse( std::vector<std::string>& tokens )
	{
		std::string macroExpansionResult{};
		bool foundMacro;

		do
		{
			foundMacro = false;

			for ( std::vector<std::string>::iterator itr = tokens.begin(); itr != tokens.end(); ++itr )
			{
				if ( g_DefineMap.find(*itr) != g_DefineMap.end() )
				{
					*itr = g_DefineMap[*itr];
					foundMacro = true;
				}
			}

			for ( int i = 0; i < tokens.size(); ++i )
			{
				macroExpansionResult += tokens[i];
			}

			std::cout << "Info : Macro expansion result:\n" << "\t\t" << macroExpansionResult << "\n";

			if (foundMacro)
			{
				tokens = tokenizeString(macroExpansionResult);
			}
			macroExpansionResult.clear();
		}
		while (foundMacro);
	}

	bool ProcessMacro( std::vector<std::string>& tokens )
	{
		if (tokens.size() && tokens[FIRST_TOKEN] == std::string{"#define"})
		{
			std::cout << "Info : This is a macro definition!\n";

			SaveMacro(tokens);
		}
		else
		{
			std::cout << "Info : This is NOT a macro definition!\n";

			ExpandMacroInUse(tokens);
		}

	}


	//------------------------------------------------------
	//Helper functions
	//------------------------------------------------------
	// should be a template
	inline void pushBack(std::vector<std::string>& vs, std::string s)
	{
		vs.push_back(s);
		std::cout << "Debug: Extracted token from line: " << s << "\n";
	}

	std::vector<std::string> tokenizeString(std::string const& inputString)
	{
		std::string currentToken;
		std::vector<std::string> tokens;

		for (int i = 0; i < inputString.size(); ++i)
		{
			if (isalpha(inputString[i]))
			{
				currentToken.push_back(inputString[i]);
			}
			else
			{
				if (currentToken.size())
				{
					pushBack(tokens, currentToken);
					pushBack(tokens, std::string{inputString[i]});

					currentToken.clear();
				}
				else
				{
					if (inputString[i] == '#')
					{
						currentToken.push_back(inputString[i]);
						continue;
					}

					pushBack(tokens, std::string{inputString[i]});
				}
			}
		}

		if (currentToken.size())
		{
			pushBack(tokens, currentToken);
		}

		return tokens;
	}

	//reused from answer to : http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	std::string trim(const std::string& str, const std::string& whitespace = " \t")
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if ( strBegin == std::string::npos )
			return ""; // no content

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr( strBegin, strRange) ;
	}

	//reused from answer to : http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	std::string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t")
	{
		// trim first
		auto result = trim( str, whitespace) ;

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

	//reused (and moded) from answer to :http://stackoverflow.com/questions/1063453/how-to-display-map-contents
	void dump_map(const macro_map_t& map)
	{
		std::cout << "Debug: Contents of map:\n";
		for ( macro_map_t::const_iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << "\t\tKey: " << it->first << "\tValue: " << it->second << "\n";
		}
	}

}

void MacroProcessor::ProcessInput( std::string& inputString )
{
	inputString = reduce(inputString);
	std::cout << "Debug: removed all of the extra whitespace: " << inputString << "\n";

	std::vector<std::string> tokens{tokenizeString(inputString)};

	ProcessMacro(tokens);
}


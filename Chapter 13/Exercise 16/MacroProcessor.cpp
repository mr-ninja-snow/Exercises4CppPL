#include "MacroProcessor.hpp"
#include <stdexcept> // std::runtime_error
#include <algorithm> // std::find
#include <iterator> // std::distance
#include <iostream>
#include <sstream> // std::stringstream
#include <cstdlib> // std::exit()
#include <utility> // std::move
#include <cctype> // std::isalpha, std::isspace
#include <vector>
#include <map>


namespace {

	//@VS comment: THIS LOOKS LIKE SH*T
	enum
	{
		FIRST_TOKEN,
		SECOND_TOKEN,
		THIRD_TOKEN,
		FORTH_TOKEN,
		FIFTH_TOKEN
	};

	enum
	{
		SKIP_SPACE_CHAR = 1,
		MACRO_NAME_LOCATION = THIRD_TOKEN,
		TOKEN_AFTER_PARENTHESIS = FIFTH_TOKEN
	};

	enum
	{
		FIRST_CHAR
	};

	//@VS comment: THIS LOOKS LIKE SH*T
	enum
	{
		THREE_TOKENS = 3
	};

	enum
	{
		ERROR_EXIT_CODE = 33
	};

	typedef std::map<std::string, std::string> macro_map_t;
	macro_map_t g_DefineMap{};

	struct macroWParams_s
	{
		size_t numberOfParams;
		std::vector<std::string> paramTokensInUse;
	};

	typedef std::map<std::string, macroWParams_s> macro_with_param_map_t;
	macro_with_param_map_t g_DefineWithParamMap{};

	void dump_map(const macro_map_t& map);
	std::vector<std::string> tokenizeString(std::string const& inputString);

	//------------------------------------------------------
	//Macro Processor functions
	//------------------------------------------------------

	// @VS comment: don't like the types of params that are passed; not really self documenting
	inline std::vector<std::string> ProcessMacroDefinition(std::vector<std::string>::const_iterator firstElemOfDef, std::vector<std::string>::const_iterator lastElemOfDef, std::vector<std::string>& parameterNames)
	{
		std::vector<std::string> paramTokensInUse{firstElemOfDef + SKIP_SPACE_CHAR, lastElemOfDef};

		char paramUsageMask{0};

		for (std::string& token : paramTokensInUse)
		{
			if (token.size() > 1)
			{
				std::vector<std::string>::iterator it = std::find(parameterNames.begin(), parameterNames.end(), token);

				if (it != parameterNames.end())
				{
					int pos = std::distance(parameterNames.begin(), it);

					std::ostringstream stringStream;
					stringStream << "param_" << pos;

					token = std::string{stringStream.str()};
					paramUsageMask |= 1 << pos;
				}
			}
		}

		// std::cout << "Debug :\t\t\tParams in use\n";
		for (auto token : paramTokensInUse)
		{
			std::cout << "\t\t\t\t'" << token << "'\n";
		}

		for (int i = 0; i < parameterNames.size(); ++i)
		{
			if ( !(paramUsageMask & (1 << i)) )
			{
				throw std::runtime_error(std::string{"Error : Syntax error in macro definition! Not all of the parameters are used in the definition.\n"});
			}
		}

		return paramTokensInUse;
	}

	inline void writeMacroToMap(const std::string& macroName, const size_t numberOfParams, std::vector<std::string>& paramTokensInUse)
	{

		macroWParams_s mwp{numberOfParams, paramTokensInUse};

		std::ostringstream stringStream;
		stringStream.str("");
		stringStream << macroName << "(";
		g_DefineWithParamMap[std::string{stringStream.str()}] = mwp;
	}

	inline void SaveMacroWithParams( std::vector<std::string>& tokens )
	{
		std::cout << "Info : macro syntax is correct, saving macro with parameters..." << "\n";

		std::vector<std::string> parameterNames{};
		int parameterIndex{0};

		bool readyForNextParam{true};

		for (int i = TOKEN_AFTER_PARENTHESIS;; ++i)
		{

			switch(tokens[i][FIRST_CHAR])
			{
			case ')':
				{
					try
					{

						if (parameterNames.size() > 9)
						{
							throw std::runtime_error(std::string{"Error : This program doesn't support macros with more than 9 parameters"});
						}

						std::vector<std::string> paramTokensInUse {ProcessMacroDefinition(tokens.begin() + i + 1, tokens.end(), parameterNames)};

						writeMacroToMap(tokens[MACRO_NAME_LOCATION], parameterNames.size(), paramTokensInUse);

						return;
					}
					catch(const std::runtime_error& error)
					{
						std::cout << error.what();
						std::exit(ERROR_EXIT_CODE);
					}
				}
			case ',':
				{
					if (!readyForNextParam)
					{
						readyForNextParam = true;
						continue;
					}
					else
					{
						std::cout << "Error : Syntax error in macro definition! Expected ',', instead received next parameter.\n";
						return;
					}
				}
			case ' ':
				{
					continue;
				}
			default:
				{
					break;
				}
			};

			if ( std::isalpha(tokens[i][FIRST_CHAR]) && readyForNextParam)
			{
				// std::cout << "Debug : Save " << tokens[i] << "\n";

				parameterNames.push_back(tokens[i]);

				std::ostringstream stringStream;
				stringStream << "param_" << parameterIndex++;
				
				tokens[i] = std::string{stringStream.str()};

				readyForNextParam = false;
				continue;
			}
			else
			{
				std::cout << "Error : Syntax error in macro definition! Expected ',', instead received next parameter.\n";
				return;
			}
		}
	}

	inline void SaveMacro( std::vector<std::string>& tokens )
	{
		if ( tokens[FORTH_TOKEN][FIRST_CHAR] == '(' && tokens.size() > THREE_TOKENS )
		{
			SaveMacroWithParams(tokens);
		}
		else
		{
			if ( std::isalpha(tokens[MACRO_NAME_LOCATION][FIRST_CHAR]) && tokens.size() > THREE_TOKENS )
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

				g_DefineMap[tokens[MACRO_NAME_LOCATION]] = macroValue;

				//debug map printout
				dump_map(g_DefineMap);
			}
			else
			{
				std::cout << "Error : Syntax error in macro definition!\n";
			}
		}

	}

	inline void SubstetuteMacroParams(std::string& param, int& parameterIndex, std::vector<std::string>& localMacroExpansionResult)
	{
		std::ostringstream stringStream;
		stringStream << "param_" << parameterIndex++;

		auto localItr = std::find(localMacroExpansionResult.begin(), localMacroExpansionResult.end(), stringStream.str());
		while(localItr != localMacroExpansionResult.end())
		{
			*localItr = param;
			localItr = std::find(++localItr, localMacroExpansionResult.end(), stringStream.str());
		}

		// std::cout << "Debug : param" << param << "\n";

		param = std::string{""};
	}

	inline void ExpandMacroWithParams( std::vector<std::string>& tokens, std::string macroName, std::vector<std::string>::iterator itr )
	{
		auto itrParamBegin = itr;
		std::vector<std::string>::iterator itrParamEnd = std::find(++itrParamBegin, tokens.end(), std::string{')'});
		std::vector<std::string> macroParams{++itrParamBegin, itrParamEnd };

		macroWParams_s mwp = g_DefineWithParamMap[macroName];
		std::vector<std::string> localMacroExpansionResult = mwp.paramTokensInUse;

		std::string param{};
		int parameterIndex{0};
		for(std::string& token : macroParams)
		{
			if (token[FIRST_CHAR] == ' ')
			{
				continue;
			}

			if (token[FIRST_CHAR] != ',')
			{
				param += token;
			}
			else
			{
				SubstetuteMacroParams(param, parameterIndex, localMacroExpansionResult);
			}
		}

		SubstetuteMacroParams(param, parameterIndex, localMacroExpansionResult);

		// std::cout << "Debug :\t\t\tlocal Macro Expansion Result\n";
		for (auto token : localMacroExpansionResult)
		{
			std::cout << "\t\t\t\t" << token << "\n";
		}

		//replace macro in tokens
		std::vector<std::string> newTokens{tokens.begin(), itr};
		newTokens.insert(newTokens.end(), localMacroExpansionResult.begin(), localMacroExpansionResult.end());

		if (itrParamEnd + 1 != tokens.end())
		{
			newTokens.insert(newTokens.end(), itrParamEnd + 1, tokens.end());
		}

		tokens = std::move(newTokens);
	}

	inline bool LookForMacroUsage( std::vector<std::string>& tokens )
	{
		for ( std::vector<std::string>::iterator itr = tokens.begin(); itr != tokens.end(); ++itr )
		{

			if ( g_DefineMap.find(*itr) != g_DefineMap.end() )
			{
				*itr = g_DefineMap[*itr];

				return true;
			}
			else
			{
				if ( (itr + 1 != tokens.end()) && (*(itr + 1))[FIRST_CHAR] == '(')
				{
					std::ostringstream stringStream;
					stringStream << *itr << '(';

					if ( g_DefineWithParamMap.find(stringStream.str()) != g_DefineWithParamMap.end() )
					{
						ExpandMacroWithParams( tokens, stringStream.str(), itr);

						return true;
					}
				}
			}
		}

		return false;
	}

	inline void ExpandMacroInUse( std::vector<std::string>& tokens )
	{
		std::string macroExpansionResult{};
		bool foundMacro;

		do
		{
			foundMacro = LookForMacroUsage(tokens);

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
		// std::cout << "Debug: Extracted token from line: " << s << "\n";
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
		// std::cout << "Debug: Contents of map:\n";
		for ( macro_map_t::const_iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << "\t\tKey: " << it->first << "\tValue: " << it->second << "\n";
		}
	}

}

void MacroProcessor::ProcessInput( std::string& inputString )
{
	inputString = reduce(inputString);
	// std::cout << "Debug: removed all of the extra whitespace: " << inputString << "\n";

	std::vector<std::string> tokens{tokenizeString(inputString)};

	ProcessMacro(tokens);
}


#include <iostream>

#include "MacroProcessor.hpp"

// #include "Parser.hpp"
// #include "Lexer.hpp"
// #include "Error.hpp"

/*
	A PLANT UML sequence diagram of the Macro Processor:
	Bob ->> CIN: input string
	note left: there will be no C++ syntax check; All of the input strings will be considered valid C++ code
	CIN ->> MacroProcessor: ProcessInput
	activate MacroProcessor
	MacroProcessor -> MacroProcessor: RemoveExtraWhiteSpaces
	MacroProcessor -> MacroProcessor: CheckIfMacroDefinition 
	note right: check if line starts with '#'
	alt is a macro definition
		MacroProcessor -> MacroProcessor: CheckMacroSyntax 
		note right: check if line has the "define" key word (with a space) after '#' 
		alt macro syntax correct
			MacroProcessor -> MacroProcessor: SaveMacroDefinition
			note right: save to std dictionary
		else macro syntax incorrect
			MacroProcessor ->> COUT : print("Error: Incorrect syntax for macro definition") 
		end
	else is not a macro definition
		MacroProcessor -> MacroProcessor: ExtractTokens
		note right: will pars the input into tokens
		MacroProcessor -> MacroProcessor: SearchTokensForMacros
		note right: will create a map<token, macro>
		alt found macros in tokens
			MacroProcessor -> MacroProcessor: ReplaceTokensWithMacros
		end	
		MacroProcessor ->> COUT : PrintResultingString 
	end
	deactivate MacroProcessor
*/

// std::map<std::string,double> table;

int main(int argc, char* argv[])
{

	while (std::cin)
	{
		std::string line;
		
		while (getline(std::cin, line))
		{
			MacroProcessor::ProcessInput(line);
		}
		// Lexer::get_token();
		// if (Lexer::curr_tok == Lexer::END) break;
		// if (Lexer::curr_tok == Lexer::PRINT) continue;
		// std::cout << Parser::expr(false) << '\n';
	}

	return Error::no_of_errors;	
}

// look into
// const string hexdigits = "0123456789ABCDEF";
// cout << "Enter a series of numbers between 0 and 15 separated by spaces. Hit ENTER when finished: " << endl;
// string line;
// string result;
// if (getline(cin, line)) // get the whole line
// {
//     istringstream iss(result); // break them by spaces
//     int i;
//     while (iss >> i)
//     {
//         result += hexdigits[i];
//         result += " ";
//     }
//     cout << "Your hex result:  " << result << endl;
// }
// else
// {
//     cout << "Error handling input!" << endl;
// }

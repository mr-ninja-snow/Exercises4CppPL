#include <iostream>

#include "MacroProcessor.hpp"

/*
OBSOLETE
	A PLANT UML sequence diagram of the Macro Processor:
	Bob ->> CIN: input string
	note left: there will be no C++ syntax check; All of the input strings will be considered valid C++ code
	CIN ->> MacroProcessor: ProcessInput
	activate MacroProcessor
	MacroProcessor -> MacroProcessor: RemoveExtraWhiteSpaces
	MacroProcessor -> MacroProcessor: CheckIfMacroDefinition
	note right: check if line starts with '#define '
	alt is a macro definition
		MacroProcessor -> MacroProcessor: CheckMacroSyntax 
		note right: check if line has a token-string after the "define" key word
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

int main(int argc, char* argv[])
{
	std::string line;

	do
	{
		std::cout << ">";
		getline(std::cin, line);

		MacroProcessor::ProcessInput(line);
	}
	while (std::cin);

	return 0;
}
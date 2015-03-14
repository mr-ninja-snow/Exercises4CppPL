#include <iostream>

#include "VSError.hpp"
#include <fstream>

int main(int argc, char* argv[])
{
	std::string line;
	std::ifstream infile("input.txt");

	while (std::getline(infile, line))
	{
		std::cout << "Info : input \n\n" << line << "\n\n";
		std::cout << "Info : output \n\n" << VSError::vsError(line, 333, 'V', "'this is a test str'") << "\n\n";
		// std::cout << "Info : output \n\n" << VSError::vsError( "This %d is %c test ", 333, 'V') << "\n\n";
		// std::cout << "Info : output \n\n" << VSError::vsError( "This %c %s test ", 'V', "'this is a test str'") << "\n\n";
		// std::cout << "Info : output \n\n" << VSError::vsError( "This %d %d test ", 333, 344) << "\n\n";

		std::cin.ignore();
	}

	std::cout << "Info : Reached end of input file\n";

	return 0;
}

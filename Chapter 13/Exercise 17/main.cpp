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
		VSError::vsError(line);

		std::cin.ignore();
	}

	std::cout << "Info : Reached end of input file\n";

	return 0;
}
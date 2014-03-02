#include <iostream>
#include <string>

int main(int argc, const char* arfgv[])
{ 
	std::string cmdLineInput{arfgv};

	std::cout << "This line was passed as an argument: " << cmdLineInput << "\n";
}

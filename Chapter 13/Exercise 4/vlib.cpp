#include <iostream>	//std::cout, std::cerr
#include <fstream>
#include "vlib.hpp"

namespace exercise_4{
	
	int ArgProc(const int argc, const char* argv[]) noexcept
	{
		try{
			for (int i = eStaringIndex; i < argc; ++i)
			{
				OutputContentsOfFile(argv[i]);
			}
		}
		catch(...)
		{
			std::cerr << "Something went wrong when printing contents of the files"; 
			return 1;
		}

		return 0;
	}

	void OutputContentsOfFile(const char* fileName)
	{

		std::ifstream myfile;
		myfile.open (fileName);
		std::string line;

		if (myfile.is_open())
		{

			std::cout << "\n\n\nHere is the contents of " << fileName << std::endl;

			while ( std::getline(myfile,line) )
			{
				std::cout << '\t' << line << '\n';
			}

			myfile.close();
		}
		else
		{
			std::cerr << "Couldn't open the " << fileName << " file.\n";
		}

	}
}

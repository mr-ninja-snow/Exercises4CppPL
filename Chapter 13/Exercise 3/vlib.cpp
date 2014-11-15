#include <iostream>	//std::cout, std::cerr
#include "vlib.hpp"

namespace exercise_3{
	
	int ArgProc(const int argc, const char* argv[]) noexcept
	{
		try{
			for (int i = eStaringIndex; i < argc; ++i)
			{
				PrintHelloForName(argv[i]);
			}
		}
		catch(...)
		{
			std::cerr << "Something went wrong when printing a 'hello message'"; 
			return 1;
		}

		return 0;
	}

	void PrintHelloForName(const char* name)
	{
		std::cout << "\n\n\tHello, " << name << "!\n";
	}
}

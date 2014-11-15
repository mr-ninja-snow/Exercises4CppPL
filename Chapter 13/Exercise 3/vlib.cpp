#include <iostream>	//std::cout, std::cerr

namespace exercise_3{
	
	int ArgProc(const int argc, const char* argv[])
	{
		try{
			for (int i = 0; i < argc; ++i)
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
		std::cout << "Hello, " << name;
	}
}

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>

typedef void (*fooBarFuncPointer)(int);

struct funcHelper
{
	std::string name;
	fooBarFuncPointer func;
};

enum 
{
	MAX_CALL_LEVEL = 10000
};

void foobar(int callLevel, funcHelper fh)
{
	// try
	// {
	
		if ( callLevel < MAX_CALL_LEVEL )
		{
			fh.func( ++callLevel );
		}
		else
		{
			std::stringstream ss{};
			ss << fh.name << " function reached maximum call level!\n" ;
			throw std::runtime_error{ ss.str() };
		}
	// }
	// catch (std::exception& e)
	// {
	// 	std::cerr << "(2.0)exception caught: " << e.what() << '\n';
	// }
}

void foo(int callLevel = 0)
{
	std::string st{};
	foobar(callLevel, funcHelper{"foo", foo});
}

void bar(int callLevel = 0)
{
	std::string st{};
	try
	{
		foobar(callLevel, funcHelper{"bar", bar});
	}
	catch (std::exception& e)
	{
		std::cerr << "(2.0)exception caught: " << e.what() << '\n';
	}
}

int main(int argc, char* argv[])
{

	std::clock_t begin = clock();

	try
	{
		bar();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Time elapsed: " << elapsed_secs << " sec\n";

	return 0;
}

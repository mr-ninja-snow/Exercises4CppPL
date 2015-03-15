#include "VSPrint.hpp"

#include <iostream>

namespace VSPrint {

	void print(int i)
	{
		std::cout << "Function: print(int)\n";
		std::cout << i << "\n";
	}

	void print(long l)
	{
		std::cout << "Function: print(long)\n";
		std::cout << l << "\n";
	}

	void print(char c)
	{
		std::cout << "Function: print(char)\n";
		std::cout << c << "\n";
	}

	void print(const char* pTC)
	{
		std::cout << "Function: print(const char*)\n";
		std::cout << pTC << "\n";
	}

	void print(double d)
	{
		std::cout << "Function: print(double)\n";
		std::cout << d << "\n";
	}

}
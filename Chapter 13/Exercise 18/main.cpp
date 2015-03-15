#include <iostream>

#include "VSPrint.hpp"

long factorial(int num)
{
	long long res{1};

	while( num > 0 )
	{
		res *= num--;
	}

	return res;
}

int main(int argc, char* argv[])
{

	// char c{'c'};
	// std::cout << "\n exact match: invoke print(char)\n";
	// VSPrint::print(c);         // exact match: invoke print(char)

	// int i{333};
	// std::cout << "\n exact match: invoke print(int)\n";
	// VSPrint::print(i);         // exact match: invoke print(int)

	// short s{ static_cast<short>(-1) };
	// std::cout << "\n integral promotion: invoke print(int)\n";
	// VSPrint::print(s);         // integral promotion: invoke print(int)

	// float f{33.33};
	// std::cout << "\n float to double promotion: print(double)\n";
	// VSPrint::print(f);         // float to double promotion: print(double)


	// std::cout << "\n exact match: invoke print(char)\n";
	// VSPrint::print('a');       // exact match: invoke print(char)

	// std::cout << "\n exact match: invoke print(int)\n";
	// VSPrint::print(49);        // exact match: invoke print(int)

	// std::cout << "\n exact match: invoke print(int)\n";
	// VSPrint::print(0);         // exact match: invoke print(int)

	// std::cout << "\n exact match: invoke print(const char*)\n";
	// VSPrint::print("a");       // exact match: invoke print(const char*)

	// std::cout << "\n nullptr_t to const char* promotion: invoke print(cost char*)\n";
	// VSPrint::print(nullptr);   // nullptr_t to const char* promotion: invoke print(cost char*)

	int num{10};
	std::cout << "\n Factorial of " << num << "\n";
	VSPrint::print( factorial(num));

	return 0;
}

#include <iostream>

#include "VSDate.hpp"

int main(int argc, char* argv[])
{

	VSDate::date_s date{};

	std::cout << date;

	std::cin >> date;

	std::cout << date;

	return 0;
}

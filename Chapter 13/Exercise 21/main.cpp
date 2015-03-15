#include <iostream>

#include "VSDate.hpp"

int main(int argc, char* argv[])
{
	VSDate::date_s date = { 29, 2, 2007 };

	std::cout << date;
	VSDate::addDay(date);
	std::cout << date;

	std::cout << "\n-----------------------------\n";
	date = VSDate::date_s{ 29, 2, 2008 };
	std::cout << date;
	std::cout << "\n-----------------------------\n";
	VSDate::addDay(date);
	std::cout << date;

	std::cout << "\n-----------------------------\n";
	VSDate::addMonth(date);
	std::cout << date;

	std::cout << "\n-----------------------------\n";
	VSDate::addYear(date);
	std::cout << date;
	std::cout << "\n-----------------------------\n";

	return 0;
}

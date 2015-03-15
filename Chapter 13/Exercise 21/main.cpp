#include <iostream>

#include "VSDate.hpp"

int main(int argc, char* argv[])
{

	VSDate::date_s date = { 29, 2, 2007};

	std::cout << date;
	addDay(date);
	std::cout << date;

	date = VSDate::date_s{29, 2, 2008};
	std::cout << date;
	VSDate::addDay(date);
	std::cout << date;
	VSDate::addMonth(date);
	std::cout << date;
	VSDate::addYear(date);
	std::cout << date;

	return 0;
}

#include "VSDate.hpp"

#include <iostream>

namespace VSDate {

	std::ostream& operator<<(std::ostream& out, date_s& date)
	{
		out << "Day: " << int( date.day ) << " Month: " << int( date.month ) << " Year: " << date.year << "\n";
	}

	std::istream& operator>>(std::istream& in, date_s& date)
	{
		std::cout << "Day: ";
		in >> date.day;
		std::cin.ignore();

		std::cout << "Month: ";
		in >> date.month;
		std::cin.ignore();

		std::cout << "Year: ";
		in >> date.year;
		std::cin.ignore();
	}

}
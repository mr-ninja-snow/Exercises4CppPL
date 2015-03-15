#ifndef VS_Date_HPP
#define VS_Date_HPP

#include <iostream>
#include <vector>

namespace VSDate {

	enum
	{
		NUMBER_OF_MONTHS = 12
	};

	const std::vector<short> numberOfDaysInMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	struct date_s
	{
		unsigned short day{1};
		unsigned short month{1};
		unsigned short year{1970};
	};

	bool validDate( date_s& date );

	// date_s operator+();
	void addDays( date_s& date );
	void addMonth( date_s& date );
	void addYear( date_s& date );

	std::ostream& operator<<( std::ostream& out, date_s& date );
	std::istream& operator>>( std::istream& in, date_s& date );

}

#endif
#ifndef VS_Date_HPP
#define VS_Date_HPP

#include <iostream>

namespace VSDate {

	struct date_s
	{
		short day{1};
		short month{1};
		short year{1970};
	};

	std::ostream& operator<<(std::ostream& out, date_s& date);
	std::istream& operator>>(std::istream& in, date_s& date);

}

#endif
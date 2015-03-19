#ifndef VS_Date_HPP
#define VS_Date_HPP

#include <iostream>
#include <vector>

namespace VSDate
{

	enum
	{
		NUMBER_OF_MONTHS = 12
	};

	const std::vector<short> numberOfDaysInMonth{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	struct date_s
	{
		unsigned short day;
		unsigned short month;
		unsigned short year;
	};

	namespace WeekDayCalc
	{
		const std::vector<short> monthTable{ 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

		enum eLeepYearMonthTable
		{
			JAN = 6,
			FEB = 2
		};

		enum eWeekDays
		{
			SUN,
			MON,
			TUS,
			WEN,
			THR,
			FRI,
			SAT
		};

		short getCenturyNumber(const short& year);

		eWeekDays calculateWeekDay(const date_s& date);

		date_s getNextModaysDate(const date_s& date);

	}



	bool validDate( date_s& date );

	void addDay( date_s& date );
	void addMonth( date_s& date );
	void addYear( date_s& date );

	std::ostream& operator<<( std::ostream& out, date_s& date );
	std::istream& operator>>( std::istream& in, date_s& date );

}

#endif
#include "VSDate.hpp"

#include <iostream>

namespace {

	bool isLeapYear(short year)
	{

		if ( year % 4 )
		{
			return false;
		}
		else
		{
			if ( year % 100 )
			{
				return true;
			}
			else
			{
				if ( year % 400 )
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}

	}

}

namespace VSDate {

	bool validDate( date_s& date )
	{
		if ( date.year == 0 )
		{
			return false;
		}

		if ( date.month < 1 || date.month > 12 )
		{
			return false;
		}

		if ( date.month == 2 && isLeapYear( date.year ) )
		{
			if ( date.day >= 1 && date.day <= (numberOfDaysInMonth[date.month - 1] + 1) )
			{
				return true;
			}
		}
		else
		{
			if ( date.day >= 1 && date.day <= numberOfDaysInMonth[date.month - 1])
			{
				return true;
			}
		}

		return false;
	}

	void addDay( date_s& date )
	{
		if ( validDate( date ) )
		{
			if ( date.day + 1 > numberOfDaysInMonth[date.month - 1] )
			{
				date.day = 1;
				addMonth( date );
			}
			else
			{
				date.day++;
			}
		}
		else
		{
			std::cout << "Error: Could add a day, passed date parameter was a invalid date\n";
		}
	}

	void addMonth( date_s& date )
	{
		if ( validDate( date ) )
		{
			if ( date.month + 1 > NUMBER_OF_MONTHS )
			{
				date.month = 1;
				addYear( date );
			}
			else
			{
				date.month++;
			}
		}
		else
		{
			std::cout << "Error: Could add a month, passed date parameter was a invalid date\n";
		}
	}

	void addYear( date_s& date )
	{
		if ( validDate( date ) )
		{
			date.year++;
		}
		else
		{
			std::cout << "Error: Could add a month, passed date parameter was a invalid date\n";
		}
	}

	short WeekDayCalc::getCenturyNumber(const short& year)
	{
		switch( ( year / 100 ) % 4 )
		{
		case 0:
		{
			return 6;
		}
		case 1:
		{
			return 4;
		}
		case 2:
		{
			return 2;
		}
		case 3:
		{
			return 0;
		}
		}
	}

	WeekDayCalc::eWeekDays WeekDayCalc::calculateWeekDay(const date_s& d)
	{
		const short cLastTwoDigitsOfYear = d.year % 100;
		const short cCenturyNumber = getCenturyNumber( d.year );

		if ( isLeapYear( d.year ) && (( d.month == 1 ) || ( d.month == 2 )) )
		{
			return static_cast<WeekDayCalc::eWeekDays>(( d.day + ( d.month == 1 ? JAN : FEB ) + cLastTwoDigitsOfYear + ( (int) cLastTwoDigitsOfYear / 4 ) + cCenturyNumber ) % 7 );
		}
		else
		{
			return static_cast<WeekDayCalc::eWeekDays>(( d.day + monthTable[d.month-1] + cLastTwoDigitsOfYear + ( (int) cLastTwoDigitsOfYear / 4 ) + cCenturyNumber ) % 7 );
		}
	}

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
#include "VSBTree.hpp"

#include <iostream>

// namespace {

// 	bool isLeapYear(short year)
// 	{

// 		if ( year % 4 )
// 		{
// 			return false;
// 		}
// 		else
// 		{
// 			if ( year % 100 )
// 			{
// 				return true;
// 			}
// 			else
// 			{
// 				if ( year % 400 )
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					return true;
// 				}
// 			}
// 		}

// 	}

// }

// namespace VSDate {

// 	void addDay( date_s& date )
// 	{
// 		if ( validDate( date ) )
// 		{
// 			if ( date.day + 1 > numberOfDaysInMonth[date.month - 1] )
// 			{
// 				date.day = 1;
// 				addMonth( date );
// 			}
// 			else
// 			{
// 				date.day++;
// 			}
// 		}
// 		else
// 		{
// 			std::cout << "Error: Could add a day, passed date parameter was a invalid date\n";
// 		}
// 	}

// }

#ifndef util_DateUtil_h
#define util_DateUtil_h

#if _MSC_VER > 1000
#  pragma once
#endif

#include <ctime>

namespace my { namespace util {

// Month enumeration
// NOT using enum class in C+11 for backward compatability
struct Month
{
  enum type
  {
	JANUARY = 1,
	FEBRUARY = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUGUST = 8,
	SEPTEMBER = 9,
	OCTOBER = 10,
	NOVEMBER = 11,
	DECEMBER = 12
  };
};

// Day of Week enumeration
// NOT using enum class in C+11 for backward compatability
struct DayOfWeek
{
  enum type
  {
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
  };
};

class DateTimeUtil {
public:
  /**
  * Get today's year, month, day by using built-in standard library.
  * No Boost nor C++11 for backward compatability. 
  * Good enough for testing general date classes, especially on older systems.
  */
  static int getCurrentYear();
  static int getCurrentMonth();
  static int getCurrentDay();
  
  /**
  * Similar to getCurrentMonth but enforce the limited enumeration of months.
  */
  static Month::type getCurrentMonthName() { return static_cast<Month::type>( getCurrentMonth() );}

private:
};

}} // end my::util

#endif // util_DateUtil_h


#ifndef util_DateUtil_h
#define util_DateUtil_h

#if _MSC_VER > 1000
#  pragma once
#endif

#include <ctime>

namespace my { namespace util {

// TODO: define Month enum
// TODO: define DayOfWeek enum

class DateTimeUtil {
public:
  /*
  * Get today's year, month, day by using built-in standard library (no Boost nor C++11)
  * Good enough for testing general date classes.
  */
  static int getCurrentYear();
  static int getCurrentMonth();
  static int getCurrentDay();

private:
};

}} // end my::util

#endif // util_DateUtil_h
#include "DateUtil.h"

namespace my { namespace util {

int DateTimeUtil::getCurrentYear()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  // Year in std::tm counted from 1900
  return now->tm_year + 1900;
}

int DateTimeUtil::getCurrentMonth()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  // Month in std::tm is zero-based
  return now->tm_mon + 1;
}

int DateTimeUtil::getCurrentDay()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  return now->tm_mday;
}

WeekDay::type DateTimeUtil::getCurrentWeekday()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  return static_cast<WeekDay::type> (now->tm_wday);
}

}} // end namespace my::qatest
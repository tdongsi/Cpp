#include "DateUtil.h"

namespace my { namespace util {

int DateTimeUtil::getCurrentYear()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  return now->tm_year + 1900;
}

int DateTimeUtil::getCurrentMonth()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  return now->tm_mon + 1;
}

int DateTimeUtil::getCurrentDay()
{
  std::time_t res = std::time(NULL);
  const std::tm* now = std::localtime(&res);
  return now->tm_mday;
}

}} // end namespace my::qatest
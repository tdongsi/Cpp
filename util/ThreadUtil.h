#ifndef util_ThreadUtil_h
#define util_ThreadUtil_h

#if _MSC_VER > 1000
#  pragma once
#endif

#ifdef _WIN32
// needed for Sleep function on windows
#include <windows.h> 
#else
//needed for sleep function on unix/POSIX
#include <unistd.h> 
#endif

namespace my { namespace util {

class ThreadUtil {
public:
  /*
  * Sleep for the given number of seconds.
  * No Boost nor C++11 for backward compatability, on older systems.
  */
  static void sleep(int seconds);

private:
};

}} // end my::util

#endif // util_ThreadUtil_h
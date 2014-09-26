#include "ThreadUtil.h"

namespace my { namespace util {

void ThreadUtil::sleep(int seconds)
{
  if ( seconds > 0 ) {
    #ifdef _WIN32
    Sleep(seconds*1000); // argument of Sleep in milliseconds
    #else
    sleep(seconds); //in seconds needed for sleep function on unix/POSIX
    #endif
  }
}

}} // end namespace my::qatest


#ifndef util_PerformanceUtil_h
#define util_PerformanceUtil_h

#if _MSC_VER > 1000
#  pragma once
#endif

#include <cstdlib>

#ifdef _WIN32
// need for reading memory usage on Windows

// If this does not work, do the following in VS
// Project->Linker->Additional dependencies: add psapi.lib
#pragma comment(lib, "psapi.lib")

#include <windows.h>
#include <psapi.h>

#elif __APPLE__
// need for reading memory usage on MacOS
#include<mach/mach.h>

#elif __linux
// need for reading memory usage on Linux
#include <cstring>
#include <cstdio>

#endif

namespace my { namespace util {

class PerformanceUtil {

public:
  /**
  * Returns the amount of physical memory in byte used by the current process
  * TODO: size_t may be the better data type than "int"
  */
  static int getPhysicalMemUsedByMe();

private:
  /**
  * Helper function: Remove the last three characters, for ' kB', from line
  * Convert the parsed string to integer
  */
  static int parseStatusLine(char* line);

};

}} // end my::util

#endif // util_PerformanceUtil_h
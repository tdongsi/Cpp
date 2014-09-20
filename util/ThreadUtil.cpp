#include "ThreadUtil.h"

namespace my { namespace util {

void ThreadUtil::sleep(unsigned seconds)
{
	#ifdef _WIN32
	Sleep(seconds*1000); // argument of Sleep in milliseconds
	#else
	sleep(seconds); //in seconds needed for sleep function on unix/POSIX
	#endif
}

}} // end namespace my::qatest
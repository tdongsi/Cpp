#include "PerformanceUtil.h"

namespace my { namespace util {

// The code is heavily C
// TODO: Consider using C++ for clarity
int PerformanceUtil::parseStatusLine(char* line){
	std::size_t length = strlen(line);
	while ( !isdigit(*line) ) line++;
	// Three for ' kB' in the string
	line[length-3] = '\0';
	int number = atoi(line);
	return number;
}


int PerformanceUtil::getPhysicalMemUsedByMe()
{
	#ifdef _WIN32
		// reading memory usage on Windows
		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*) &pmc, sizeof(pmc));
		int physMemUsedByMe = pmc.WorkingSetSize;
		
		return physMemUsedByMe;
	#elif __APPLE__
		// reading memory usage on MacOS
		
		// resident size is in t_info.resident_size;
		struct task_basic_info t_info;
		mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
		int physMemUsedByMe = 0;

		if (KERN_SUCCESS != task_info(mach_task_self(),
									  TASK_BASIC_INFO, (task_info_t)&t_info, 
									  &t_info_count))
		{
			printf( "Cannot get memory info on Mac\n" );
		} else {
			physMemUsedByMe = t_info.resident_size;
		}
		
		return physMemUsedByMe;
		
	#elif __linux
		// reading memory usage on Linux
		
		// the basic idea is to read and parse /proc/self/status pseudo-filesystem
		FILE* file = fopen("/proc/self/status", "r");
		int result = -1;
		char line[128];

		while (fgets(line, 128, file) != NULL){
			if (strncmp(line, "VmRSS:", 6) == 0){
				result = PerformanceUtil::parseStatusLine(line); // NOTE: this value is in KB
				break;
			}
		}
		fclose(file);
		
		const int BYTE_PER_KB = 1024;
		int physMemUsedByMe = BYTE_PER_KB * result;
		
		return physMemUsedByMe;
	#endif
}

}} // end namespace my::qatest
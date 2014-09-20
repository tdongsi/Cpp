#include <cstdlib>
#include <cstdio>
#include "PerformanceUtil.h"

int main ()
{
  int amount = 200000;
  char * buffer;
  
  int physMemUsedByMe = my::util::PerformanceUtil::getPhysicalMemUsedByMe();
  printf ( "Before: %d\n", physMemUsedByMe );
  
  buffer = (char*) malloc (amount);
  if (buffer==NULL) exit (1);
  
  physMemUsedByMe = my::util::PerformanceUtil::getPhysicalMemUsedByMe();
  // The number is sometimes not exactly incremented by "amount" on Mac.
  printf ( "After: %d\n", physMemUsedByMe );
  
  free (buffer);

  return 0;
}
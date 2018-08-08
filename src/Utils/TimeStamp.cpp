#ifdef _WIN32
#include <windows.h>
#include <stdint.h>
#define FILETIME_TO_UNIX 116444736000000000i64
#else
#include <sys/time.h>
#endif
#include <stdlib.h>
#include "TimeStamp.h"

#ifdef _WIN32
double get_timestamp () {
	FILETIME ft;
	GetSystemTimePreciseAsFileTime (&ft);
	int64_t t = ((int64_t) ft.dwHighDateTime << 32L) | (int64_t) ft.dwLowDateTime;
	return (t - FILETIME_TO_UNIX) / (10.0 * 1000.0 * 1000.0);
}
#else
double get_timestamp ()
{
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return (double) (tv.tv_sec) + (double) (tv.tv_usec) / 1000;
}
#endif

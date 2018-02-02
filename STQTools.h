#include "STQInclude.h"

#ifndef STQ_TOOLS_H
#define STQ_TOOLS_H

int *STQ_generating_random_number_int(int min, int max, int len);
int *STQ_generating_random_number_rise_int(int start, int len);
int *STQ_generating_random_number_drop_int(int end, int len);
int *STQ_generating_random_number_diff_int(int max);
int *STQ_generating_random_number_diff_during_int(int min, int max, int len);

void STQ_for_each_int(int * arr, int len);

void STQ_swap_int(int *a, int *b);

#if 0
	时间单位还有：秒(s)、毫秒(ms)、微秒 (μs)、纳秒(ns)、皮秒(ps)、飞秒(fs)、阿秒、渺秒

	1s = 10^3 ms = 10^6 us = 10^9 ns = 10^12 ps = 10^15 fs=10^18阿秒=10^21渺秒=10^43普朗克常数  
	
	#include <time.h> 
	time_t time(time_t *tloc);
   	char *asctime(const struct tm *tm);
   	char *asctime_r(const struct tm *tm, char *buf);
   	char *ctime(const time_t *timep);
   	char *ctime_r(const time_t *timep, char *buf);
   	struct tm *gmtime(const time_t *timep);
   	struct tm *gmtime_r(const time_t *timep, struct tm *result);
   	struct tm *localtime(const time_t *timep);
   	struct tm *localtime_r(const time_t *timep, struct tm *result);
   	time_t mktime(struct tm *tm);

   	#include <sys/time.h>
   	int gettimeofday(struct timeval *tv, struct timezone *tz);
   	int settimeofday(const struct timeval *tv, const struct timezone *tz);
	
   	#include <sys/timeb.h>
   	int ftime(struct timeb *tp);

   	#include <time.h>
   	double difftime(time_t time1, time_t time0);

   	struct tm {
		int tm_sec;    /* Seconds (0-60) */
		int tm_min;    /* Minutes (0-59) */
		int tm_hour;   /* Hours (0-23) */
		int tm_mday;   /* Day of the month (1-31) */
		int tm_mon;    /* Month (0-11) */
		int tm_year;   /* Year - 1900 */
		int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
		int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
		int tm_isdst;  /* Daylight saving time */
	};

	struct timeval {
		time_t      tv_sec;     /* seconds */
		suseconds_t tv_usec;    /* microseconds */
	};

	struct timezone {
		int tz_minuteswest;     /* minutes west of Greenwich */
		int tz_dsttime;         /* type of DST correction */
	};

	struct timeb {
		time_t         time;
		unsigned short millitm;
		short          timezone;
		short          dstflag;
	};

#endif

void point_bit_to_one(unsigned char *bit, size_t size, unsigned int value, unsigned int * idx, unsigned char * bitMove);
int  point_bit_to_value(unsigned char *bit, size_t size, unsigned int index, unsigned char bitMove);

void STQ_set_clock(struct timeval *clk);
double STQ_get_diff_sec(struct timeval *start, struct timeval *end);
int64_t STQ_get_diff_msec(struct timeval *start, struct timeval *end) ;
int64_t STQ_get_diff_usec(struct timeval *start, struct timeval *end);

struct timeval stq_start, stq_end;

#define PRINTF_VOID_FUN_TIME_SEC(name, arg1, ...) \
	{ 							\
		STQ_set_clock(&stq_start); \
		name(arg1, ## __VA_ARGS__); \
		STQ_set_clock(&stq_end); \
		printf(NONE "["#name"] %lf - sec\n", STQ_get_diff_sec(&stq_start, &stq_end)); \
	} \

#define PRINTF_VOID_FUN_TIME_MSEC(name, arg1, ...) \
	{ 							\
		STQ_set_clock(&stq_start); \
		name(arg1, ## __VA_ARGS__); \
		STQ_set_clock(&stq_end); \
		printf(NONE "["#name"] %ld - msec\n", STQ_get_diff_msec(&stq_start, &stq_end)); \
	} \

#define PRINTF_VOID_FUN_TIME_USEC(name, arg1, ...) \
	{ 							\
		STQ_set_clock(&stq_start); \
		name(arg1, ## __VA_ARGS__); \
		STQ_set_clock(&stq_end); \
		printf(NONE "["#name"] %ld - usec\n", STQ_get_diff_usec(&stq_start, &stq_end)); \
	} \

#define PRINTF_FREE_FUN_TIME_SEC(name, tmp, arg1, ...) \
	{ 							\
		STQ_set_clock(&stq_start); \
		tmp = name(arg1, ## __VA_ARGS__); \
		STQ_set_clock(&stq_end); \
		printf(NONE "["#name"] %lf - sec\n", STQ_get_diff_sec(&stq_start, &stq_end)); \
	} \

#define PRINTF_FREE_FUN_TIME_MSEC(name, tmp, arg1, ...) \
	{ 							\
		STQ_set_clock(&stq_start); \
		tmp = name(arg1, ## __VA_ARGS__); \
		STQ_set_clock(&stq_end); \
		printf(NONE "["#name"] %ld - msec\n", STQ_get_diff_msec(&stq_start, &stq_end)); \
	} \

#define PRINTF_FREE_FUN_TIME_USEC(name, tmp, arg1,...) \
	{ 							\
		STQ_set_clock(&stq_start); \
		tmp = name(arg1, ## __VA_ARGS__); \
		STQ_set_clock(&stq_end); \
		printf(NONE "["#name"] %ld - usec\n", STQ_get_diff_usec(&stq_start, &stq_end)); \
	} \

#endif // STQ_TOOLS_H

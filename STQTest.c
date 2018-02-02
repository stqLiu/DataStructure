//#define STQ_DEBUG 1

#include "STQ.h"

#if 0
	STQ_LOG_NONE("a","bsssssssss");
	STQ_LOG_RED("a","bsssssssss%d",1);
	STQ_LOG_LIGHT_RED("a","bsssssssss%d",1);
	STQ_LOG_BLUE("a","bsssssssss%d",1);
	STQ_LOG_LIGHT_BLUE("a","bsssssssss%d",1);
	STQ_LOG_DARY_GRAY("a","bsssssssss%d",1);
	STQ_LOG_LIGHT_CYAN("a","bsssssssss%d",1);
	STQ_LOG_PURPLE("a","bsssssssss%d",1);
	STQ_LOG_LIGHT_PURPLE("a","bsssssssss%d",1);
	STQ_LOG_BROWN("a","bsssssssss%d",1);
	STQ_LOG_YELLOW("a","bsssssssss%d",1);
	STQ_LOG_LIGHT_GRAY("a","bsssssssss%d",1);
	STQ_LOG_WHITE("a","bsssssssss%d",1);
#endif
#if 0
	STQ_LOGE("STQ_LOGE","%d, %s", 1234, "stq_log");
	STQ_LOGW("STQ_LOGW","%d, %s", 1234, "stq_log");
	STQ_LOGM("STQ_LOGM","%d, %s", 1234, "stq_log");
	STQ_LOGD("STQ_LOGD","%d, %s", 1234, "stq_log");
#endif


int main(int argc, char const *argv[])
{

	STQ_LOGE("E", "PRINTF_FREE_FUN_TIME_USEC");
	STQ_LOGD("D", "PRINTF_FREE_FUN_TIME_USEC");

#if 1

	int *src;

	PRINTF_FREE_FUN_TIME_USEC(STQ_generating_random_number_int, src, 0, RANDS_MAX, MAX_NUMBER)

	STQ_for_each_int(src, MAX_NUMBER);

	//STQ_bitmap_sort(src, MAX_NUMBER, RANDS_MAX);
	STQ_merge_sort(src, MAX_NUMBER);

	STQ_for_each_int(src, MAX_NUMBER);

	if(src){
		free(src);
	}

#endif

	

	return 0;
}

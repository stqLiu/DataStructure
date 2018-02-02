#include "STQInclude.h"

#ifndef STQ_LOG_H
#define STQ_LOG_H

#define STQ_DEBUG 1

#ifndef STQ_DEBUG 
#define STQ_DEBUG 0
#endif

#ifndef USER_VERSION 
#define DEBUG_VERSION 0
#else
#define DEBUG_VERSION 1
#endif

#define NONE                "\033[m"  
#define RED                 "\033[0;32;31m"  
#define LIGHT_RED           "\033[1;31m"  
#define GREEN               "\033[0;32;32m"  
#define LIGHT_GREEN     	"\033[1;32m"  
#define BLUE                "\033[0;32;34m"  
#define LIGHT_BLUE         	"\033[1;34m"  
#define DARY_GRAY         	"\033[1;30m"  
#define CYAN                "\033[0;36m"  
#define LIGHT_CYAN         	"\033[1;36m"  
#define PURPLE              "\033[0;35m"  
#define LIGHT_PURPLE   		"\033[1;35m"  
#define BROWN               "\033[0;33m"  
#define YELLOW              "\033[1;33m"  
#define LIGHT_GRAY        	"\033[0;37m"  
#define WHITE               "\033[1;37m"  

#define STQ_LOGD(TAG,format,...) \
		{ \
			if(STQ_DEBUG) \
				STQ_LOG_NONE(TAG,format,##__VA_ARGS__); \
		} \

#define STQ_LOGM(TAG,format,...) STQ_LOG_LIGHT_CYAN(TAG,format,##__VA_ARGS__)
#define STQ_LOGW(TAG,format,...) STQ_LOG_YELLOW(TAG,format,##__VA_ARGS__)
#define STQ_LOGE(TAG,format,...) STQ_LOG_LIGHT_RED(TAG,format,##__VA_ARGS__)

#define STQ_LOG_NONE(TAG,format,...) fprintf(stderr, NONE "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_RED(TAG,format,...) fprintf(stderr, RED "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_LIGHT_RED(TAG,format,...) fprintf(stderr, LIGHT_RED "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_BLUE(TAG,format,...) fprintf(stderr, BLUE "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_LIGHT_BLUE(TAG,format,...) fprintf(stderr, LIGHT_BLUE "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_DARY_GRAY(TAG,format,...) fprintf(stderr, DARY_GRAY "["TAG"] "format"\n",## __VA_ARGS__)
#define STQ_LOG_LIGHT_CYAN(TAG,format,...) fprintf(stderr, LIGHT_CYAN "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_PURPLE(TAG,format,...) fprintf(stderr, PURPLE "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_LIGHT_PURPLE(TAG,format,...) fprintf(stderr, LIGHT_PURPLE "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_BROWN(TAG,format,...) fprintf(stderr, BROWN "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_YELLOW(TAG,format,...) fprintf(stderr, YELLOW "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_LIGHT_GRAY(TAG,format,...) fprintf(stderr, LIGHT_GRAY "["TAG"] "format"\n", ##__VA_ARGS__)
#define STQ_LOG_WHITE(TAG,format,...) fprintf(stderr, WHITE "["TAG"] "format"\n", ##__VA_ARGS__)



#endif // STQ_LOG_H


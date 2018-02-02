#include "STQTools.h"

int *STQ_generating_random_number_int(int min, int max, int len) {
	
	int * array = malloc(len * sizeof(int));

	for (int i = 0; i < len; ++i)
	{
		srand((unsigned)time(0) + rand());
		array[i] = rand() % (max - min + 1) + min;
	}

	return array;
}

int *STQ_generating_random_number_rise_int(int start, int len) { 
	
	int * array = malloc(len * sizeof(int));

	for (int i = 0; i < len; ++i)
	{
		array[i] = i + start;
	}

	return array;
}

int *STQ_generating_random_number_drop_int(int end, int len) { 
	
	int * array = malloc(len * sizeof(int));

	for (int i = 0; i < len; ++i)
	{
		array[i] = end - i;
	}

	return array;	
}

int *STQ_generating_random_number_diff_int(int max) { 

	int * array = malloc((max + 1) * sizeof(int));
	
	for (int i = 0; i < max+1; ++i)
	{
		array[i] = i;
	}

	for (int i = 1; i < max+1; ++i)
	{
		STQ_swap_int(&array[i], &array[rand()%i]);
	}

	return array;
}


int *STQ_generating_random_number_diff_during_int(int min, int max, int len) {

	int * array = malloc(len * sizeof(int));
	char *tmp  = malloc((max + 1) * sizeof(char));

	for (int i = 0; i < max+1; ++i)
	{
		tmp[i] = 0;
	}

	int index = 0;
	for (int i = 0; i < len; ++i)
	{
		srand((unsigned)time(0) + rand());
		index = rand() % (max - min + 1) + min;

		while(tmp[index] > 0) {
			++index;
			if(index > max) {
				index = min;
			}
		}

		tmp[index] = 1;
		array[i] = index;
	}

	free(tmp);

	return array;
}

inline void STQ_swap_int(int *a, int *b) {
#if 0
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
#endif
#if 1
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b; 
#endif
#if 0
	int tmp = *a;
	*a = *b;
	*b = tmp;
#endif
}

void STQ_for_each_int(int * arr, int len) {
	printf("{");
	for (int i = 0; i < len-1; ++i)
	{	
		printf("%d, ", arr[i]);
	}
	printf("%d}\n", arr[len-1]);
}

inline void STQ_set_clock(struct timeval *clk) {
	gettimeofday(clk, NULL);
}

inline double STQ_get_diff_sec(struct timeval *start, struct timeval *end) {
	return ((end->tv_sec + (double)end->tv_usec/1000000) - (start->tv_sec + (double)start->tv_usec/1000000));
}

inline int64_t STQ_get_diff_msec(struct timeval *start, struct timeval *end) {
	return ((end->tv_sec*1000 + end->tv_usec/1000) - (start->tv_sec*1000 + start->tv_usec/1000));
}

inline int64_t STQ_get_diff_usec(struct timeval *start, struct timeval *end) {
	return ((end->tv_sec*1000*1000 + end->tv_usec) - (start->tv_sec*1000*1000 + start->tv_usec));
}

void point_bit_to_one(unsigned char *bit, size_t size, unsigned int value, unsigned int * idx, unsigned char * bitMove) {

	unsigned int index = value >> 3;
	if(index >= size)
		return;
	
	unsigned char j = value - (index << 3);
	
	bit[index] |= (1<<j);

	if(idx && bitMove){
		*idx = index;
		*bitMove = j;
	}
}

int point_bit_to_value(unsigned char *bit, size_t size, unsigned int index, unsigned char bitMove) {
	
	if(index >= size)
		return -1;

	if(bit[index] & (1<<bitMove)) {

		return ((index<<3)+bitMove);
	}
				
	return -1;
}
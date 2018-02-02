#include "STQSort.h"

static void __quick_sort(int * src, int l, int h) {
	if(l < h) {
		int post = src[l];
		int low = l;
		int high = h;

		while(low < high) {
			while(low < high && src[high] >= post) {
			    high--;
			}
			src[low] = src[high];

			while(low < high && src[low] <= post) {
			    low++;
			}
			src[high] = src[low];
		}
		src[low] = post;
		__quick_sort(src, l, low - 1);
		__quick_sort(src, low + 1, h);
	}
}

void __partition_quick_sort();

void STQ_quick_sort(int * src, int size) {
	__quick_sort(src, 0, size - 1);
}

void STQ_bubble_sort(int * src, int size) {
    for (int i = 0; i < size - 1; i++) {
    	int flag = 1;
    	for (int j = 0; j < size - 1 - i; j++) {
        	if (src[j] > src[j + 1]) {
            	STQ_swap_int(&src[j], &src[j+1]);
            	flag = 0;
       	 	}
    	}
    	if (flag) {
        	break;
	    }
	}
}

void STQ_insert_sort(int * src, int size) {
	for (int i = 0; i < size-1; ++i)
	{
		int j = i;
		int temp = src[j+1];
		for (; j >= 0 && src[j] > temp; j--)
		{
			src[j+1] = src[j];
		}
		src[j+1] = temp;
	}
}

void STQ_binary_insert_sort(int * src, int size) {
	int key, left, right, middle;
    for (int i=1; i<size; i++)   
    {   
		key = src[i];   
		left = 0;   
		right = i-1;   
		while (left<=right)   
		{   
	        middle = (left+right)/2;   
	        if (src[middle]>key)   
	            right = middle-1;   
	        else   
	        	left = middle+1;   
		}   
		 
		for(int j=i-1; j>=left; j--)   
		{   
			src[j+1] = src[j]; 
		}   
		   
		src[left] = key;          
    }
}


void STQ_shell_sort(int * src, int size) {

	int fp = (size -1) / 2;

	int s = 2;

	while(1) {

		int post = (size -1) / s;
		
		if(post != fp)
			post = 1;

		for (int i = 0; i <= size - 1 - post; i++)
		{
			int j = i;
			int temp = src[j+post];
			for (; j >=0 && src[j] > temp; j-=post)
			{
				src[j+post] = src[j];
			}
			src[j+post] = temp;
		}

		if(post != fp)
			break;

		s++;
	}
}
void STQ_select_sort(int * src, int size) {
	
	int a,b;
	for (int i = 0; i < size-1; ++i)
	{
		a = i;
		b = i;

		for (int j = a+1; j < size; ++j)
		{
			if(src[b] > src[j]) {
				b = j;
			}
		}

		if(b != a) {
			STQ_swap_int(&src[a], &src[b]);
		}
	}
}

void STQ_bilateral_bubble_sort(int * src, int size) {

	int low = 0, high = size -1;

	while(low < high) {

		for (int i = low; i < high; ++i)
		{
			if(src[i] > src[i+1])
				STQ_swap_int(&src[i], &src[i+1]);
		}

		high--;

		for (int i = high; i > low; i--)
		{
			if(src[i] < src[i-1])
				STQ_swap_int(&src[i], &src[i-1]);
		}

		low++;
	}
}

void __adjustment_heap(int * src, int index, int size) {
	
	int left =  2 * index + 1;
	int rigth = 2 * index + 2;
	int min = index;

	if(left < size && src[left] > src[min]) {
		min = left;
	}

	if(rigth < size && src[rigth] > src[min]) {
		min = rigth;
	}

	if(index != min) {
		STQ_swap_int(&src[index], &src[min]);
		__adjustment_heap(src, min, size);
	}

}

void __generate_heap(int * src, int size) {

	for (int i = (size / 2 - 1); i >= 0; i--)
	{
		__adjustment_heap(src, i, size);
	}
}

void STQ_heap_sort(int * src, int size) {
	__generate_heap(src, size);
	while(size > 1) {
		STQ_swap_int(&src[--size], &src[0]);
		__adjustment_heap(src, 0, size);
	}
}

// [1 3] megre [2 4]  ===> lowS == 0 highS == 2  number == 2
void __megre_split(int * src, int lowS, int highS, int hightE) {

	int tmp[hightE-lowS];
	int index = 0;
	int ls = lowS;
	int hs = highS;
	while(lowS < hs && highS < hightE) {
		if(src[lowS] > src[highS]) {
			tmp[index] = src[highS];
			highS++;
		}else{
			tmp[index] = src[lowS];
			lowS++;
		}
		index++;
	}
	while(lowS < hs) {
		tmp[index] = src[lowS];
		index++;
		lowS++;
	}

	while(highS < hightE) {
		tmp[index] = src[highS];
		index++;
		highS++;
	}

	index = 0;

	for (int i = ls; i <  hightE; ++i)
	{
		src[i] = tmp[index++];
	}
}

void STQ_merge_sort(int * src, int size){

	int post = size >> 1;
	int end;
	int step = 1;
	while(step <= post) {
		for (int i = 0; i < size; i+=(step<<1))
		{	
			end = ((i+(step<<1)) >= size) ? size : (i+(step<<1));
			__megre_split(src, i, i+step, end);
		}
		step = step << 1;
	}

	//last once megre, dont do it cause sort not success!
	__megre_split(src, 0, step, size);
}	


//as STQ_bitmap_sort, youself can implements
void STQ_bucket_sort(int * src, int size){
	//1.split bucket
	//2.to do bucket sort,you can use [quicksort ...]
}

//as STQ_bitmap_sort,youself can implements
void STQ_count_sort(int * src, int size){
	//array count
}

//as STQ_bitmap_sort,youself can implements
void STQ_radix_sort(int * src, int size){
	//number split[1-9 1-9(*10) 1-9(*100) ... ]
}

//everyone number is diff
void STQ_bitmap_sort(int * src, int size, int max) {
	
	unsigned char *bit = malloc(max*sizeof(char));

	memset(bit, 0, max);

	for (int i = 0; i < size; ++i)
	{
		point_bit_to_one(bit, max, src[i], NULL, NULL);
	}

	int count = 0;
	for (unsigned int index = 0; index < max; ++index)
	{
		for (unsigned bitMove = 0; bitMove < 8; ++bitMove)
		{
			int tmp = point_bit_to_value(bit, max, index, bitMove);
			if(tmp >= 0) {
				src[count++] = tmp;
			}
		}
	}

	free(bit);
}

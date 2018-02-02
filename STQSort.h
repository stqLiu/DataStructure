#include "STQTools.h"

#ifndef STQ_SORT_H
#define STQ_SORT_H

void STQ_quick_sort(int * src, int size);
void STQ_bubble_sort(int * src, int size);
void STQ_insert_sort(int * src, int size);
void STQ_binary_insert_sort(int * src, int size);
void STQ_shell_sort(int * src, int size);
void STQ_select_sort(int * src, int size);
//bilateral bubble sort
void STQ_bilateral_bubble_sort(int * src, int size);
void STQ_heap_sort(int * src, int size);
void STQ_merge_sort(int * src, int size);
void STQ_bucket_sort(int * src, int size);
void STQ_count_sort(int * src, int size);
void STQ_radix_sort(int * src, int size);
// max is in src to max number 
void STQ_bitmap_sort(int * src, int size, int max);

#endif // STQ_SORT_H

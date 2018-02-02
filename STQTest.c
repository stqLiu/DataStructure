#include "STQ.h"

void test_time() {
	struct timeval start, end;
	STQ_set_clock(&start);
	for (int i = 0; i < 100000; ++i)
	{
		for (int j = 0; j < 10000; ++j) {

		}
	}
	STQ_set_clock(&end);

	printf("[S]  %lf\n", STQ_get_diff_sec(&start, &end));
	printf("[mS] %ld\n", STQ_get_diff_msec(&start, &end));
	printf("[uS] %ld\n", STQ_get_diff_usec(&start, &end));
}

int main(int argc, char const *argv[])
{

	// understand questuion
	// select right algorithm
	// select right data struct
	// coding
	// test code

	struct stq_hlist_head head;
	struct stq_hlist node1;
	struct stq_hlist node2;
	struct stq_hlist node3;
	struct stq_hlist node4;
	struct stq_hlist node5;
	struct stq_hlist node6;

	stq_init_hlist_head(&head);
	stq_init_hlist(&node1);
	stq_init_hlist(&node2);
	stq_init_hlist(&node3);
	stq_init_hlist(&node4);
	stq_init_hlist(&node5);
	stq_init_hlist(&node6);

	printf("[1 node %p , &node->next %p]\n", &node1, &node1.next);
	printf("[2 node %p , &node->next %p]\n", &node2, &node2.next);
	printf("[3 node %p , &node->next %p]\n", &node3, &node3.next);
	printf("[4 node %p , &node->next %p]\n", &node4, &node4.next);
	printf("[5 node %p , &node->next %p]\n", &node5, &node5.next);
	printf("[6 node %p , &node->next %p]\n", &node6, &node6.next);

	stq_add_hlist_head(&head, &node1);

	stq_add_hlist_before(&node2, &node1);
	stq_add_hlist_before(&node3, &node2);

	stq_add_hlist_behind(&node4, &node3);
	stq_add_hlist_behind(&node5, &node3);
	stq_add_hlist_behind(&node6, &node3);

	printf("[head %p, first %p]\n", &head, head.first);
	printf("[1 next %p , *pprev %p]\n", node1.next, *node1.pprev);
	printf("[2 next %p , *pprev %p]\n", node2.next, *node2.pprev);
	printf("[3 next %p , *pprev %p]\n", node3.next, *node3.pprev);
	printf("[4 next %p , *pprev %p]\n", node4.next, *node4.pprev);
	printf("[5 next %p , *pprev %p]\n", node5.next, *node5.pprev);
	printf("[6 next %p , *pprev %p]\n", node6.next, *node6.pprev);

	printf("[next %p , pprev %p]\n", node2.next, node2.pprev);

# if 0

	[1 node 0x7ffdeee1f410 , &node->next 0x7ffdeee1f410]
	[2 node 0x7ffdeee1f420 , &node->next 0x7ffdeee1f420]
	[3 node 0x7ffdeee1f430 , &node->next 0x7ffdeee1f430]
	[4 node 0x7ffdeee1f440 , &node->next 0x7ffdeee1f440]
	[5 node 0x7ffdeee1f450 , &node->next 0x7ffdeee1f450]
	[6 node 0x7ffdeee1f460 , &node->next 0x7ffdeee1f460]
	[head 0x7ffdeee1f400, first 0x7ffdeee1f430]
	[1 next (nil) , *pprev 0x7ffdeee1f410]
	[2 next 0x7ffdeee1f410 , *pprev 0x7ffdeee1f420]
	[3 next 0x7ffdeee1f460 , *pprev 0x7ffdeee1f430]
	[4 next 0x7ffdeee1f420 , *pprev 0x7ffdeee1f440]
	[5 next 0x7ffdeee1f440 , *pprev 0x7ffdeee1f450]
	[6 next 0x7ffdeee1f450 , *pprev 0x7ffdeee1f460]
	[next 0x7ffdeee1f410 , pprev 0x7ffdeee1f440]

#endif

#if 0

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

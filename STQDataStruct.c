#include "STQDataStruct.h"

/*********************************List********************************************/

void init_list_head(struct list_node * head) {
	head->next = head;
	head->prev = head;
}

void add_node(struct list_node * node, struct list_node * prev, struct list_node * next) {
	next->prev = node;
	node->prev = prev;
	node->next = next;
	prev->next = node;
}

void add_node_head(struct list_node * node, struct list_node * head) {
	add_node(node, head, head->next);
}

void add_node_tail(struct list_node * node, struct list_node * head) {
	add_node(node, head->prev, head);
}

void del_node(struct list_node * prev, struct list_node * next) {
	prev->next = next;
	next->prev = prev;
}

void del_node_head(struct list_node * node) {
	del_node(node->prev, node->next);
}

int list_is_empty(struct list_node * head) {
	if(head->next == head->prev)
		return 1;
	return 0;
}



/********************************Queue***************************************/

void init_Queue(struct Queue * q, int max_size) {
	q->head = 0;
	q->tail = 0;
	q->max_size = max_size;
	q->size = 0;
}

int push_Queue(struct Queue * q) {
	if(q->size < (q->max_size) && (q->size >= 0)){
		int index = q->head;
		q->head = (q->head + 1) % q->max_size;
		q->size += 1;
		return index;
	}
	return -1;
}

int pop_Queue(struct Queue * q) {
	if((q->size > 0) && (q->size <= (q->max_size))){
		int index = q->tail;
		q->tail = (q->tail + 1) % q->max_size;
		q->size -= 1;
		return index;
	}
	return -1;
}

int queue_is_empty(struct Queue * q) {
	if(q->size == 0)
		return 1;
	return 0;
}

/********************************hlist*****************************************/

void stq_init_hlist_head(struct stq_hlist_head *head) {
	head->first = NULL;
}

void stq_init_hlist(struct stq_hlist *node) {
	node->next = NULL;
	node->pprev = NULL;
}

void stq_add_hlist_head(struct stq_hlist_head * head, struct stq_hlist * node) {
	struct stq_hlist *first =  head->first;
	node->next = first;
	if(first)
		first->pprev = &node->next;
	node->pprev = &head->first;
	head->first = node;
}

void stq_add_hlist_before(struct stq_hlist * node, struct stq_hlist * next) {

	node->pprev = next->pprev;
	node->next = next;
	next->pprev = &node->next;
	*(node->pprev) = node;
}

void stq_add_hlist_behind(struct stq_hlist * node, struct stq_hlist * prev) {

	node->pprev = &prev->next;
	if(prev->next)
		prev->next->pprev = &node->next;
	node->next = prev->next;
	prev->next = node;
}
#include "STQInclude.h"

#ifndef STQ_DATA_STRUCT_H
#define STQ_DATA_STRUCT_H

/*********************************List********************************************/
struct list_node
{
	struct list_node *prev;
	struct list_node *next;
};  //loop  bidirectional list

#define list_entry(ptr, type, member) 	\
	container_of(ptr, type, member)

#define container_of(ptr, type, member) \
	(type *)((char *)(ptr) - (char *) &((type *)0)->member)

#define for_list_entry(post, head) \
	for(post = (head)->next; post != head; post = post->next)

// init list head
void init_list_head(struct list_node * head) ;

void add_node(struct list_node * node, struct list_node * prev, struct list_node * next);

// head insert
void add_node_head(struct list_node * node, struct list_node * head);

//tail insert
void add_node_tail(struct list_node * node, struct list_node * head);

void del_node(struct list_node * prev, struct list_node * next) ;

//head delete
void del_node_head(struct list_node * node);

int  list_is_empty(struct list_node * head);

/********************************Queue***************************************/

struct Queue
{
	int head;
	int tail;
	int max_size;   // max size
	int size;       // effective number
};

void init_Queue(struct Queue * q, int max_size);
int  push_Queue(struct Queue * q);
int  pop_Queue(struct Queue * q);
int  queue_is_empty(struct Queue * q);

/********************************hlist*****************************************/

struct stq_hlist
{
	struct stq_hlist *next;
	struct stq_hlist **pprev;
};

struct stq_hlist_head {
	struct stq_hlist *first;
};

void stq_init_hlist_head(struct stq_hlist_head *head);

void stq_init_hlist(struct stq_hlist *node);

void stq_add_hlist_head(struct stq_hlist_head * head, struct stq_hlist * node);

void stq_add_hlist_before(struct stq_hlist * node, struct stq_hlist * next);

void stq_add_hlist_behind(struct stq_hlist * node, struct stq_hlist * prev);

/********************************RBtree****************************************/

/********************************Btree*****************************************/

/********************************2-3-4Btree************************************/

/********************************TrieBtree*************************************/

/********************************HashMap***************************************/

/********************************skiplist**************************************/


#endif // STQ_DATA_STRUCT_H
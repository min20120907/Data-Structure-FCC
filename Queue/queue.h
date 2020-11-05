#include "../LinkedList/LinkList.h"
#ifndef _queue_h
#define _queue_h
typedef struct _Queue {
	node_p head;
	node_p tail;
}queue, *queuePtr;

queuePtr touchQueue();
void enqueue(queuePtr q);
void dequeue(queuePtr q);

int is_full(queuePtr q);
int is_empty(queuePtr q);



#endif

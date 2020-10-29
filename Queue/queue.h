#ifdef _queue_h
#define _queue_h
struct _Queue {
	UserData head;
	UserData tail;
}queue, *queuePtr;

queuePtr enqueue(queuePtr q);
queuePtr dequeue(queuePtr q);

int is_full(queuePtr q);
int is_empty(queuePtr q);



#endif

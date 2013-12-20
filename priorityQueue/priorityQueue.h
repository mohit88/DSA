#include "../linkedList/linkedList.h"

typedef struct {
	void* data;
	int priority;
}Element;
typedef int CompareFunc(void* priority1,void* priority2);

typedef List PriorityQueue;

PriorityQueue* createPriorityQ();

int enqueue(PriorityQueue* priorityQ,Element* data,CompareFunc* compare);
Element* dequeue(PriorityQueue* priorityQ);
void disposePriorityQ(PriorityQueue* priorityQ);
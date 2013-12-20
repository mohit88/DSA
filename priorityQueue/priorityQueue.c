#include "priorityQueue.h"
#include <stdlib.h>

PriorityQueue* createPriorityQ(){
	return createList();
}

int getInsertingPosition(PriorityQueue* priorityQ ,Element* data,CompareFunc* compare){
	int i = 0,comparisonResult,priority;
	Node* nextNode = priorityQ->head;
	if(priorityQ->length==0) return 0;
	while(nextNode!=NULL){
		priority = ((Element*)(nextNode->data))->priority;
		if(0 > compare(&(data->priority),&priority))break;
		i++;
		nextNode = nextNode->next;
	}
	return i;
}

int enqueue(PriorityQueue *priorityQ, Element *data, CompareFunc *compare){
	int position = getInsertingPosition(priorityQ, data,compare);
	return insert(priorityQ, position, data);
}

Element* dequeue(PriorityQueue *priorityQ){
	return (Element*)deleteNode(priorityQ, 0);
}

void disposePriorityQ(PriorityQueue* priorityQ){
	disposeList(priorityQ);
}

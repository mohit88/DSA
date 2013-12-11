#include "processShedular.h"
#include <stdlib.h>

int compareFunc(const void* a,const void* b){
	return ((Process*)b)->priority - ((Process*)a)->priority;
}

void sortProcessQueue(Queue *processQueue){
	qsort(processQueue->data, processQueue->capacity, processQueue->elementSize, compareFunc);
}

void nextProcess(Queue *processQueue){
	enqueue(processQueue,dequeue(processQueue));
}

void processShedular(Queue* processQueue){
	sortProcessQueue(processQueue);
	while(!isEmpty(processQueue)){	
	}
}
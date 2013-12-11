#include "testUtils.h"
#include "processShedular.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void createProcess(Process* process, char* name,int priority,int secTime){
	strcpy(process->name, name);
	process->priority = priority;
	process->secTime = secTime;
}

int areQueueEqual(Queue* expected,Queue* actual){
	int result = expected->elementSize == actual->elementSize
					&& expected->capacity == actual->capacity 
					&& expected->front	== actual->front 
					&& expected->rear	== actual->rear;
	if(!result) return result;
	if(isEmpty(expected)) return result;
	return 0 == memcmp(expected->data, actual->data,(expected->capacity-1)*(expected->elementSize));
}



void test_sort_process_queue_by_priority(){
	Process process[3];
	Queue *expected = create(3, sizeof(Process));
	Queue *processQueue = create(3, sizeof(Process));
	createProcess(&process[0],"git",3,70);
	createProcess(&process[1],"note pad plus",1,10);
	createProcess(&process[2],"Browser",5,500);
	enqueue(processQueue, &process[0]);
	enqueue(processQueue, &process[1]);
	enqueue(processQueue, &process[2]);
	enqueue(expected, &process[2]);
	enqueue(expected, &process[0]);
	enqueue(expected, &process[1]);
	sortProcessQueue(processQueue);
	ASSERT(areQueueEqual(expected,processQueue));
	dispose(expected);
	dispose(processQueue);
}

void test_move_process_to_rear_of_queue(){
	Process process[3];
	Queue *expected = create(3, sizeof(Process));
	Queue *processQueue = create(3, sizeof(Process));
	createProcess(&process[0],"git",3,70);
	createProcess(&process[1],"note pad plus",1,10);
	createProcess(&process[2],"Browser",5,500);
	enqueue(processQueue, &process[0]);
	enqueue(processQueue, &process[1]);
	enqueue(processQueue, &process[2]);
	enqueue(expected, &process[0]);
	enqueue(expected, &process[1]);
	enqueue(expected, &process[2]);
	expected->front += 1;expected->rear += 1;
	nextProcess(processQueue);
	ASSERT(areQueueEqual(expected,processQueue));
	dispose(expected);
	dispose(processQueue);
}

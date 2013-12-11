#include "circularQueue.h"

typedef struct{
	char name[256];
	int priority;
	int secTime;
} Process;

void sortProcessQueue(Queue* processQueue);
void nextProcess(Queue* processQueue);
void processShedular(Queue* processQueue);
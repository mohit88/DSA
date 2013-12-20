#include "processShedular.h"
#include <stdlib.h>

Schedular* createSchedular(){
	return createList();
}

int getInsertingPosition(Schedular* schedular ,Process* process){
	int i = 0,priority;
	Node* nextNode = schedular->head;
	if(schedular->length==0) return 0;
	while(nextNode!=NULL){
		priority = ((Process*)(nextNode->data))->priority;
		if(priority < process->priority)break;
		i++;
		nextNode = nextNode->next;
	}
	return i;
}


int schedule(Schedular *schedular, Process *process){
	int position = getInsertingPosition(schedular, process);
	process->waitingStatus = position;
	return insert(schedular, position, process);
}

Process* timeSlice(Schedular *schedular, int stime){
	Process* nextProcess,
	*currentProcess = deleteNode(schedular, 0);
	Node* nextNode = schedular->head;
	currentProcess->pTime = currentProcess->pTime - stime;
	if(currentProcess->pTime > 0 )
		insert(schedular, schedular->length, currentProcess);
	while(nextNode!=NULL){
		nextProcess = (Process*)(nextNode->data);
		nextProcess->waitingStatus = (nextProcess->waitingStatus - 1 + schedular->length)%schedular->length;
		nextNode = nextNode->next;
	}
	return currentProcess;
}

void disposeSchedular(Schedular *schedular){
	disposeList(schedular);
}
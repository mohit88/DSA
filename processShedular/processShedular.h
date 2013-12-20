#include "../linkedList/linkedList.h"

typedef struct {
	char pname[256];
	int pTime;
	int priority;
	int waitingStatus;
} Process;

typedef List Schedular;

Schedular* createSchedular();
int schedule(Schedular* schedular, Process* process);
Process* timeSlice(Schedular* schedular,int time);
void disposeSchedular(Schedular* schedular);

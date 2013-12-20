#include "testUtils.h"
#include "processShedular.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areProcessEqual(Process* expected,Process* actual){
	int result = 	0 == strcmp(expected->pname, actual->pname)
					&& expected->pTime == actual->pTime
					&& expected->priority == actual->priority
					&& expected->waitingStatus == actual->waitingStatus;	
	return result;
}
void createProcess(Process* process, char* name,int priority,int pTime,int waitingStatus){
	strcpy(process->pname, name);
	process->pTime = pTime;
	process->priority = priority;
	process->waitingStatus = waitingStatus;
}

void test_sort_process_queue_by_priority(){
	Process process[3];
	Schedular *schedular = createSchedular();
	createProcess(&process[0],"git",3,70,0);
	createProcess(&process[1],"note pad plus",1,10,0);
	createProcess(&process[2],"Browser",5,500,0);
	ASSERT(schedule(schedular,&process[0]));
	ASSERT(schedule(schedular,&process[1]));
	ASSERT(schedule(schedular,&process[2]));
	disposeSchedular(schedular);
}

void test_time_slice_the_first_in_priority_queue(){
	Process process[3];
	Schedular *schedular = createSchedular();
	Process expected[3];
	Process* actual;
	createProcess(&expected[0], "Browser", 5, 490, 2);
	createProcess(&expected[1],"git",3,60,1);
	createProcess(&expected[2],"note pad plus",1,0,0);
	createProcess(&process[0],"git",3,70,0);
	createProcess(&process[1],"note pad plus",1,10,0);
	createProcess(&process[2],"Browser",5,500,0);
	ASSERT(schedule(schedular,&process[0]));
	ASSERT(schedule(schedular,&process[1]));
	ASSERT(schedule(schedular,&process[2]));
	actual = timeSlice(schedular,10);
	ASSERT(areProcessEqual(&expected[0], actual));	
	actual = timeSlice(schedular,10);
	ASSERT(areProcessEqual(&expected[1], actual));
	disposeSchedular(schedular);
}


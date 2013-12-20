#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_create_priority_queue");
	setup();
		test_create_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_insert_data_with_priority_into_priority_queue");
	setup();
		test_insert_data_with_priority_into_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_insert_data_with_priority_into_priority_queue_having_more_than_1_elements");
	setup();
		test_insert_data_with_priority_into_priority_queue_having_more_than_1_elements();
	tearDown();
	testEnded();
	testStarted("test_delete_from_priority_Queue");
	setup();
		test_delete_from_priority_Queue();
	tearDown();
	testEnded();
	testStarted("test_delete_from_priority_Queue_having_two_elements");
	setup();
		test_delete_from_priority_Queue_having_two_elements();
	tearDown();
	testEnded();
	testStarted("test_insert_data_with_priority__in_Decend_into_priority_queue_having_more_than_1_elements");
	setup();
		test_insert_data_with_priority__in_Decend_into_priority_queue_having_more_than_1_elements();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

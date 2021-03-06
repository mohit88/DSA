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

	testStarted("test_creating_stack_of_length_3");
	setup();
		test_creating_stack_of_length_3();
	tearDown();
	testEnded();
	testStarted("test_pushing_element_in_stack");
	setup();
		test_pushing_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_cant_push_element_in_full_stack");
	setup();
		test_cant_push_element_in_full_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_stack");
	setup();
		test_pop_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_element_from_an_empty_stack");
	setup();
		test_poping_element_from_an_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_retriving_top_element_of_stack");
	setup();
		test_retriving_top_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_cant_retrive_top_element_from_an_empty_stack");
	setup();
		test_cant_retrive_top_element_from_an_empty_stack();
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

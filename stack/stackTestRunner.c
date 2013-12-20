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

	testStarted("test_creating_stack_initialize_with_zero");
	setup();
		test_creating_stack_initialize_with_zero();
	tearDown();
	testEnded();
	testStarted("test_pushing_integer_in_null_stack");
	setup();
		test_pushing_integer_in_null_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_integer_in_full_stack");
	setup();
		test_pushing_integer_in_full_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_double_in_null_stack");
	setup();
		test_pushing_double_in_null_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_double_in_full_stack");
	setup();
		test_pushing_double_in_full_stack();
	tearDown();
	testEnded();
	testStarted("test_pushing_string_in_null_stack");
	setup();
		test_pushing_string_in_null_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_integer_from_null_stack");
	setup();
		test_poping_integer_from_null_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_integer_from_full_stack");
	setup();
		test_poping_integer_from_full_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_double_from_null_stack");
	setup();
		test_poping_double_from_null_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_double_from_full_stack");
	setup();
		test_poping_double_from_full_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_string_from_null_stack");
	setup();
		test_poping_string_from_null_stack();
	tearDown();
	testEnded();
	testStarted("test_poping_string_from_string_stack");
	setup();
		test_poping_string_from_string_stack();
	tearDown();
	testEnded();
	testStarted("test_retrive_top_element_from_null_stack");
	setup();
		test_retrive_top_element_from_null_stack();
	tearDown();
	testEnded();
	testStarted("test_retrive_top_element_from_stack");
	setup();
		test_retrive_top_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_stack_is_empty");
	setup();
		test_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_stack_is_not_empty");
	setup();
		test_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_stack_is_full");
	setup();
		test_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_stack_is_not_full");
	setup();
		test_stack_is_not_full();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

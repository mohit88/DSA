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

	testStarted("test_put_key_and_value_in_hash_map");
	setup();
		test_put_key_and_value_in_hash_map();
	tearDown();
	testEnded();
	testStarted("test_put_value_which_has_already_present_key_in_hash_map");
	setup();
		test_put_value_which_has_already_present_key_in_hash_map();
	tearDown();
	testEnded();
	testStarted("test_get_value_which_is_not_present_key_in_hash_map");
	setup();
		test_get_value_which_is_not_present_key_in_hash_map();
	tearDown();
	testEnded();
	testStarted("test_removing_specific_key_and_value_from_hash_map");
	setup();
		test_removing_specific_key_and_value_from_hash_map();
	tearDown();
	testEnded();
	testStarted("test_removing_key_and_value_which_is_not_present_in_hash_map");
	setup();
		test_removing_key_and_value_which_is_not_present_in_hash_map();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

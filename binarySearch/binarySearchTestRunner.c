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

	testStarted("test_search_3_in_array_of_one_element");
	setup();
		test_search_3_in_array_of_one_element();
	tearDown();
	testEnded();
	testStarted("test_search_2_in_array_of_two_element");
	setup();
		test_search_2_in_array_of_two_element();
	tearDown();
	testEnded();
	testStarted("test_search_3_in_array_of_three_element");
	setup();
		test_search_3_in_array_of_three_element();
	tearDown();
	testEnded();
	testStarted("test_search_30_in_array_of_four_element");
	setup();
		test_search_30_in_array_of_four_element();
	tearDown();
	testEnded();
	testStarted("test_search_56_in_array_of_five_element");
	setup();
		test_search_56_in_array_of_five_element();
	tearDown();
	testEnded();
	testStarted("test_search_3_in_array_of_eight_element");
	setup();
		test_search_3_in_array_of_eight_element();
	tearDown();
	testEnded();
	testStarted("test_search_3p0_in_array_of_one_element");
	setup();
		test_search_3p0_in_array_of_one_element();
	tearDown();
	testEnded();
	testStarted("test_search_2p0_in_array_of_two_element");
	setup();
		test_search_2p0_in_array_of_two_element();
	tearDown();
	testEnded();
	testStarted("test_search_3p0_in_array_of_three_element");
	setup();
		test_search_3p0_in_array_of_three_element();
	tearDown();
	testEnded();
	testStarted("test_search_3p00_in_array_of_four_element");
	setup();
		test_search_3p00_in_array_of_four_element();
	tearDown();
	testEnded();
	testStarted("test_search_56p0_in_array_of_five_element");
	setup();
		test_search_56p0_in_array_of_five_element();
	tearDown();
	testEnded();
	testStarted("test_search_3p0_in_array_of_eight_element");
	setup();
		test_search_3p0_in_array_of_eight_element();
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

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

	testStarted("test_parentheses_are_proper_in_string_having_no_character");
	setup();
		test_parentheses_are_proper_in_string_having_no_character();
	tearDown();
	testEnded();
	testStarted("test_parentheses_are_proper_in_string_having_only_alphabets_character");
	setup();
		test_parentheses_are_proper_in_string_having_only_alphabets_character();
	tearDown();
	testEnded();
	testStarted("test_parentheses_are_proper_in_string_having_opening_and_closing_bracket");
	setup();
		test_parentheses_are_proper_in_string_having_opening_and_closing_bracket();
	tearDown();
	testEnded();
	testStarted("test_parentheses_are_not_proper_in_string_having_closing_and_opening_bracket");
	setup();
		test_parentheses_are_not_proper_in_string_having_closing_and_opening_bracket();
	tearDown();
	testEnded();
	testStarted("test_parentheses_are_proper_in_string_having_20_character");
	setup();
		test_parentheses_are_proper_in_string_having_20_character();
	tearDown();
	testEnded();
	testStarted("test_parentheses_are_not_proper_in_string_having_20_character");
	setup();
		test_parentheses_are_not_proper_in_string_having_20_character();
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

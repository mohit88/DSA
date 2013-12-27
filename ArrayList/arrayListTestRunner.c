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

	testStarted("test_insert_element");
	setup();
		test_insert_element();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_elements");
	setup();
		test_insert_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_interns_grows_beyond_capacity");
	setup();
		test_interns_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_index_beyond_length");
	setup();
		test_should_not_insert_at_index_beyond_length();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_negative_index");
	setup();
		test_should_not_insert_at_negative_index();
	tearDown();
	testEnded();
	testStarted("test_insert_at_middle_should_shift_the_elements");
	setup();
		test_insert_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_when_list_is_null");
	setup();
		test_should_not_insert_when_list_is_null();
	tearDown();
	testEnded();
	testStarted("test_remove_last_element_from_arraylist");
	setup();
		test_remove_last_element_from_arraylist();
	tearDown();
	testEnded();
	testStarted("test_remove_middle_element_from_arraylist");
	setup();
		test_remove_middle_element_from_arraylist();
	tearDown();
	testEnded();
	testStarted("test_should_not_remove_element_on_index_out_of_bound");
	setup();
		test_should_not_remove_element_on_index_out_of_bound();
	tearDown();
	testEnded();
	testStarted("test_add_element_at_last_only_using_add_functionality");
	setup();
		test_add_element_at_last_only_using_add_functionality();
	tearDown();
	testEnded();
	testStarted("test_serach_element_in_array_list");
	setup();
		test_serach_element_in_array_list();
	tearDown();
	testEnded();
	testStarted("test_serach_element_which_is_absent_in_array_list");
	setup();
		test_serach_element_which_is_absent_in_array_list();
	tearDown();
	testEnded();
	testStarted("test_array_iterator_with_two_elements_has_next");
	setup();
		test_array_iterator_with_two_elements_has_next();
	tearDown();
	testEnded();
	testStarted("test_array_iterator_with_zero_elements_dont_have_next");
	setup();
		test_array_iterator_with_zero_elements_dont_have_next();
	tearDown();
	testEnded();
	testStarted("test_accessing_next_element_using_array_iterator");
	setup();
		test_accessing_next_element_using_array_iterator();
	tearDown();
	testEnded();
	testStarted("test_accessing_next_element_of_iterator_of_NULL_array_List_gives_NULL");
	setup();
		test_accessing_next_element_of_iterator_of_NULL_array_List_gives_NULL();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

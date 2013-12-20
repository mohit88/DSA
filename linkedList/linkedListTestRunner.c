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

	testStarted("test_create_linked_list_with_head_NULL");
	setup();
		test_create_linked_list_with_head_NULL();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_in_empty_linked_list");
	setup();
		test_inserting_data_in_empty_linked_list();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_in_linked_list_having_only_head");
	setup();
		test_inserting_data_in_linked_list_having_only_head();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_at_tail_in_linked_list");
	setup();
		test_inserting_data_at_tail_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_in_between_linked_list");
	setup();
		test_inserting_data_in_between_linked_list();
	tearDown();
	testEnded();
	testStarted("test_inserting_data_on_zeroth_index_of_linked_list_having_atleast_one_element");
	setup();
		test_inserting_data_on_zeroth_index_of_linked_list_having_atleast_one_element();
	tearDown();
	testEnded();
	testStarted("test_cant_insert_data_in_linked_list_on_index_out_of_range");
	setup();
		test_cant_insert_data_in_linked_list_on_index_out_of_range();
	tearDown();
	testEnded();
	testStarted("test_deleting_first_node_of_linked_list_having_only_one_element");
	setup();
		test_deleting_first_node_of_linked_list_having_only_one_element();
	tearDown();
	testEnded();
	testStarted("test_delete_first_element_of_linked_list_having_three_element_atleast");
	setup();
		test_delete_first_element_of_linked_list_having_three_element_atleast();
	tearDown();
	testEnded();
	testStarted("test_deleting_node_on_last_index_of_linked_list_having_atleast_three_element");
	setup();
		test_deleting_node_on_last_index_of_linked_list_having_atleast_three_element();
	tearDown();
	testEnded();
	testStarted("test_deleting_node_in_between_of_linked_list_having_atleast_three_element");
	setup();
		test_deleting_node_in_between_of_linked_list_having_atleast_three_element();
	tearDown();
	testEnded();
	testStarted("test_deleting_last_node_of_linked_list_having_only_two_element");
	setup();
		test_deleting_last_node_of_linked_list_having_only_two_element();
	tearDown();
	testEnded();
	testStarted("test_deleting_first_node_of_linked_list_having_only_two_element");
	setup();
		test_deleting_first_node_of_linked_list_having_only_two_element();
	tearDown();
	testEnded();
	testStarted("test_retriving_last_node_in_linked_list");
	setup();
		test_retriving_last_node_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_retriving_head_node_in_linked_list");
	setup();
		test_retriving_head_node_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_retriving_2nd_node_in_linked_list");
	setup();
		test_retriving_2nd_node_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_retriving_out_of_range_node_in_linked_list");
	setup();
		test_retriving_out_of_range_node_in_linked_list();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

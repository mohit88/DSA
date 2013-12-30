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

	testStarted("test_insert_child_node_to_root_in_tree");
	setup();
		test_insert_child_node_to_root_in_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_two_child_node_to_root_in_tree");
	setup();
		test_insert_two_child_node_to_root_in_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_child_node_to_random_parent_in_tree");
	setup();
		test_insert_child_node_to_random_parent_in_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_root_node_in_tree_having_root_node_already");
	setup();
		test_insert_root_node_in_tree_having_root_node_already();
	tearDown();
	testEnded();
	testStarted("test_delete_child_node_of_root_from_tree");
	setup();
		test_delete_child_node_of_root_from_tree();
	tearDown();
	testEnded();
	testStarted("test_should_not_delete_node_having_children");
	setup();
		test_should_not_delete_node_having_children();
	tearDown();
	testEnded();
	testStarted("test_should_not_delete_node_which_is_not_present");
	setup();
		test_should_not_delete_node_which_is_not_present();
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

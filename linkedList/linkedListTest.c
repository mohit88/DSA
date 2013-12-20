#include "testUtils.h"
#include "linkedList.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
List* integerList;
void setup(){
	integerList = createList();
}

void tearDown(){
	disposeList(integerList);
}

void test_create_linked_list_with_head_NULL(){
	List* actual = createList();
	ASSERT(0 == actual->length);
	ASSERT(NULL == actual->head);
	ASSERT(NULL == actual->tail);
}

void test_inserting_data_in_empty_linked_list(){
	int _8 = 8;
	void * data;
	ASSERT(insert(integerList,0,&_8));
	data = integerList->head->data;
	ASSERT(1 == integerList->length);
	ASSERT(_8==*(int*)data);
	ASSERT(integerList->head == integerList->tail);
}

void test_inserting_data_in_linked_list_having_only_head(){
	int _4 = 4,_8 = 8;
	void * nextData;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_8));
	nextData = integerList->tail->data;
	ASSERT(2 == integerList->length);
	ASSERT(_8==*(int*)nextData);
}

void test_inserting_data_at_tail_in_linked_list(){
	int _4 = 4,_8 = 8;
	void * nextData;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_8));
	ASSERT(insert(integerList, 2, &_4));
	nextData = integerList->tail->data;
	ASSERT(3 == integerList->length);
	ASSERT(_4==*(int*)nextData);
	
}

void test_inserting_data_in_between_linked_list(){
	int _4 = 4,_8 = 8,_16 = 16;
	Node * nextNode;
	ASSERT(insert(integerList,0,&_16));
	ASSERT(insert(integerList,1,&_8));
	ASSERT(insert(integerList, 1, &_4));
	nextNode = integerList->head->next;
	ASSERT(3 == integerList->length);
	ASSERT(_4==*(int*)(nextNode->data));
}

void test_inserting_data_on_zeroth_index_of_linked_list_having_atleast_one_element(){
	int _4 = 4,_8 = 8;
	Node * nextNode;
	ASSERT(insert(integerList,0,&_4));
	nextNode = integerList->head;
	ASSERT(insert(integerList,0,&_8));
	ASSERT(2 == integerList->length);
	ASSERT(_8 == *(int*)(integerList->head->data));
	ASSERT(nextNode == integerList->head->next);
	ASSERT(nextNode->next == NULL);
	ASSERT(nextNode->previous == integerList->head);
}

void test_cant_insert_data_in_linked_list_on_index_out_of_range(){
	int _4 = 4,_8 = 8;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(0 == insert(integerList,2,&_8));
	ASSERT(1 == integerList->length);
	ASSERT(_4 == *(int*)(integerList->head->data));
	ASSERT(integerList->head->next == NULL);
}

void test_deleting_first_node_of_linked_list_having_only_one_element(){
	int _4 = 4;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(_4 == *(int*)deleteNode(integerList, 0));
	ASSERT(0 == integerList->length);
	ASSERT(NULL == integerList->head);
	ASSERT(NULL == integerList->tail);
}

void test_delete_first_element_of_linked_list_having_three_element_atleast(){
	int _4 = 4,_5 = 5,_6 = 6;
	Node* nextHead;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	nextHead = integerList->head->next;
	ASSERT(_4 == *(int*)deleteNode(integerList, 0));
	ASSERT(2 == integerList->length);
	ASSERT(nextHead == integerList->head);
	ASSERT(NULL== integerList->head->previous);
}

void test_deleting_node_on_last_index_of_linked_list_having_atleast_three_element(){
	int _4 = 4,_5 = 5,_6 = 6;
	Node* nextTail; 
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	nextTail = integerList->tail->previous;
	ASSERT(_6 == *(int*)deleteNode(integerList, 2));
	ASSERT(2 == integerList->length);
	ASSERT(nextTail == integerList->tail);
}

void test_deleting_node_in_between_of_linked_list_having_atleast_three_element(){
	int _4 = 4,_5 = 5,_6 = 6;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	ASSERT(_5 == *(int*)deleteNode(integerList, 1));
	ASSERT(2 == integerList->length);
}

void test_deleting_last_node_of_linked_list_having_only_two_element(){
	int _4 = 4,_5 = 5;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(_5 == *(int*)deleteNode(integerList, 1));
	ASSERT(1 == integerList->length);
	ASSERT(integerList->tail == integerList->head);
}

void test_deleting_first_node_of_linked_list_having_only_two_element(){
	int _4 = 4,_5 = 5;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(_4 == *(int*)deleteNode(integerList,0));
	ASSERT(1 == integerList->length);
	ASSERT(integerList->tail == integerList->head);
}

void test_retriving_last_node_in_linked_list(){
	int _4 = 4,_5 = 5,_6;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	ASSERT(_6 == *(int*)getElement(integerList,2));
}

void test_retriving_head_node_in_linked_list(){
	int _4 = 4,_5 = 5,_6;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	ASSERT(_4 == *(int*)getElement(integerList,0));
}

void test_retriving_2nd_node_in_linked_list(){
	int _4 = 4,_5 = 5,_6;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	ASSERT(_5 == *(int*)getElement(integerList,1));
}

void test_retriving_out_of_range_node_in_linked_list(){
	int _4 = 4,_5 = 5,_6;
	ASSERT(insert(integerList,0,&_4));
	ASSERT(insert(integerList,1,&_5));
	ASSERT(insert(integerList,2,&_6));
	ASSERT(NULL == getElement(integerList,4));
}


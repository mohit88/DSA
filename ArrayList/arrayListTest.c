#include <stdlib.h>
#include <string.h>
#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_remove_last_element_from_arraylist(){
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 2, &tanbirka);
	ASSERT(&tanbirka == removeElement(internsPtr,2));
	ASSERT(NULL == get(internsPtr, 2));
}

void test_remove_middle_element_from_arraylist(){
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 2, &tanbirka);
	ASSERT(&ji == removeElement(internsPtr,1));
	ASSERT(NULL == get(internsPtr, 2));
	ASSERT(&tanbirka == get(internsPtr, 1));
}

void test_should_not_remove_element_on_index_out_of_bound(){
	int noOfElements = 0;	
	ArrayList intern = create(noOfElements);
	ArrayList *	internPtr = &intern;
	ASSERT(NULL == removeElement(internPtr,2));	
}


void test_add_element_at_last_only_using_add_functionality(){
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	add(internsPtr,&tanbirka);	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
	ASSERT(&tanbirka == get(internsPtr, 2));
}

int compareInterns(void* first,void* second){
	Intern* firstIntern = (Intern*)first;
	Intern* secondIntern = (Intern*)second;
	int result = firstIntern->id == secondIntern->id
				&& firstIntern->age == secondIntern->age
				&& 0 == strcmp(firstIntern->name,secondIntern->name);
	return result;				
}

void test_serach_element_in_array_list(){
	int result;
	add(internsPtr,&prateek);
	add(internsPtr,&ji);
	ASSERT(&prateek == get(internsPtr,0));
	ASSERT(&ji == get(internsPtr, 1));
	result = search(internsPtr,&prateek,compareInterns);
	ASSERT(&prateek == get(internsPtr,result));
}

void test_serach_element_which_is_absent_in_array_list(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka",34};
	add(internsPtr,&prateek);
	add(internsPtr,&ji);
	ASSERT(&prateek == get(internsPtr,0));
	ASSERT(&ji == get(internsPtr, 1));
	ASSERT(-1 == search(internsPtr,&tanbirka,compareInterns));
}

void test_array_iterator_with_two_elements_has_next() {
	ArrayIterator it;
	add(internsPtr,&prateek);
	add(internsPtr,&ji);
	it = getIterator(internsPtr);
	ASSERT(it.hasNext(&it));
}

void test_array_iterator_with_zero_elements_dont_have_next() {
	ArrayIterator it = getIterator(internsPtr);
	ASSERT(0 == it.hasNext(&it));
}

void test_accessing_next_element_using_array_iterator() {
	ArrayIterator it;
	Intern *res;
	insert(internsPtr, 0, &prateek);
	it = getIterator(internsPtr);
	res = (Intern*)it.next(&it);
	ASSERT(compareInterns(&prateek, res));
}
void test_accessing_next_element_of_iterator_of_NULL_array_List_gives_NULL() {
	ArrayIterator it = getIterator(internsPtr);
	Intern *res;
	res = (Intern*)it.next(&it);
	ASSERT(NULL == res);
}
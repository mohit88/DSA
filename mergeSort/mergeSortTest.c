#include "testUtils.h"
#include "mergeSort.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

int areEqual(void** expected,void** actual,int size){
	int result = 1,index;
	for (index = 0; index < size; ++index){
		result = result && expected[index] == actual[index];
	}
	return result;
}

void test_sorting_array_of_2_integers_using_merge_sort(){
	int _1 = 1,_2 = 2;
	void* unsortedList[2] = {&_2,&_1};
	void* sortedList[2] = {&_1,&_2};
	mergeSort(unsortedList,2,compareInteger);
	ASSERT(areEqual(sortedList,unsortedList,2));
}

void test_sorting_array_of_4_integers_using_merge_sort(){
	int _1 = 1,_2 = 2,_3 = 3,_4 = 4;
	void* unsortedList[4] = {&_3,&_2,&_4,&_1};
	void* sortedList[4] = {&_1,&_2,&_3,&_4};
	mergeSort(unsortedList,4,compareInteger);
	ASSERT(areEqual(sortedList,unsortedList,4));
}


void test_sorting_array_of_3_integers_using_merge_sort(){
	int _1 = 1,_2 = 2,_3 = 3;
	void* unsortedList[3] = {&_3,&_2,&_1};
	void* sortedList[3] = {&_1,&_2,&_3};
	mergeSort(unsortedList,3,compareInteger);
	ASSERT(areEqual(sortedList,unsortedList,3));
}

void test_sorting_array_of_5_integers_using_merge_sort(){
	int _1 = 1,_2 = 2,_3 = 3,_4 = 4,_5 = 5;
	void* unsortedList[5] = {&_3,&_5,&_2,&_4,&_1};
	void* sortedList[5] = {&_1,&_2,&_3,&_4,&_5};
	mergeSort(unsortedList,5,compareInteger);
	ASSERT(areEqual(sortedList,unsortedList,5));
}

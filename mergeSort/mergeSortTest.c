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
		result = result && (expected[index] == actual[index]);
	}
	return result;
}

void test_sorting_array_using_merge_sort(){
	int _1 = 1,_2 = 2;
	void* unsortedList[2] = {&_2,&_1};
	void* sortedList[2] = {&_1,&_2};
	mergeSort(unsortedList,2,compareInteger);
	ASSERT(areEqual(sortedList,unsortedList,2));
}

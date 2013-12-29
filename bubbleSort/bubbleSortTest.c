#include "testUtils.h"
#include "bubbleSort.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

int areEqual(void* expected,void* actual,int bitSize){
	return 0 == memcmp(expected,actual,bitSize);
}

void test_sorting_array_using_binary_sort(){
	int unsortedList[5] = {5,3,2,4,1};
	int sortedList[5] = {1,2,3,4,5};
	bubbleSort(unsortedList,5,sizeof(int),compareInteger);
	ASSERT(areEqual(sortedList,unsortedList,5*sizeof(int)));
}

int compareDouble(void* first,void* second){
	return *(double*)first - *(double*)second;
}


void test_sorting_double_serise_using_binary_sort(){
	double unsortedList[5] = {5.0,3.0,2.0,4.0,1.0};
	double sortedList[5] = {1.0,2.0,3.0,4.0,5.0};
	bubbleSort(unsortedList,5,sizeof(double),compareDouble);
	ASSERT(areEqual(sortedList,unsortedList,5*sizeof(double)));
}

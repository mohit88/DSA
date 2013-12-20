#include "testUtils.h"
#include "iSort.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(void* expected,void* actual,int length,int elementSize){
	return 0 == memcmp(expected,actual,length*elementSize);
}

int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

void test_sorting_five_integer_elements(){
	int unSortedIntegers[5] = {4,5,3,6,2};
	int sortedIntegers[5] = {2,3,4,5,6};
	isort(unSortedIntegers, 5, sizeof(int), compareInteger);
	ASSERT(areEqual(sortedIntegers,unSortedIntegers, 5, sizeof(int)));
}

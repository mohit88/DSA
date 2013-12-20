#include "testUtils.h"
#include "binarySearch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(const void*a ,const void* b){
	return *(int*)a-*(int*)b;
}

int compareDouble(const void*a ,const void* b){
	return *(double*)a-*(double*)b;
}

void test_search_3_in_array_of_one_element(){
	int oneInteger[1] = {4};
	int _3 = 3;
	void* result = binarySearch(&_3,oneInteger,1,sizeof(int),compareInteger);
	ASSERT(NULL == result);
}

void test_search_2_in_array_of_two_element(){
	int twoInteger[2] = {1,2};
	int _2 = 2;
	int*result = (int*)binarySearch(&_2,twoInteger,2,sizeof(int),compareInteger);
	ASSERT(_2 == *result);
}

void test_search_3_in_array_of_three_element(){
	int threeInteger[3] = {1,2,3};
	int _3 = 3;
	int* result = (int*)binarySearch(&_3,threeInteger,3,sizeof(int),compareInteger);
	ASSERT(_3 == *result);
}

void test_search_30_in_array_of_four_element(){
	int fourInteger[4] = {3,23,30,45};
	int _30 = 30;
	int* result = (int*)binarySearch(&_30,fourInteger,4,sizeof(int),compareInteger);
	ASSERT(_30 == *result);
}

void test_search_56_in_array_of_five_element(){
	int fiveInteger[5] = {3,23,30,45,56};
	int _56 = 56;
	int* result = (int*)binarySearch(&_56,fiveInteger,5,sizeof(int),compareInteger);
	ASSERT(_56 == *result);
}

void test_search_3_in_array_of_eight_element(){
	int _8_Integer[8] = {3,23,30,45,56,78,80,89};
	int _3 = 3;
	int* result = (int*)binarySearch(&_3,_8_Integer,8,sizeof(int),compareInteger);
	ASSERT(_3 == *result);
}

void test_search_3p0_in_array_of_one_element(){
	double oneDouble[1] = {4.0};
	double _3p0 = 3.0;
	void* result = binarySearch(&_3p0,oneDouble,1,sizeof(double),compareDouble);
	ASSERT(NULL == result);
}

void test_search_2p0_in_array_of_two_element(){
	double twoDouble[2] = {1.0,2.0};
	double _2p0 = 2.0;
	double*result = (double*)binarySearch(&_2p0,twoDouble,2,sizeof(double),compareDouble);
	ASSERT(_2p0 == *result);
}

void test_search_3p0_in_array_of_three_element(){
	double threeDouble[3] = {1.0,2.0,3.0};
	double _3p0 = 3.0;
	double* result = (double*)binarySearch(&_3p0,threeDouble,3,sizeof(double),compareDouble);
	ASSERT(_3p0 == *result);
}

void test_search_3p00_in_array_of_four_element(){
	double fourDouble[4] = {3.0,23.0,30.0,45.0};
	double _30p0 = 30.0;
	double* result = (double*)binarySearch(&_30p0,fourDouble,4,sizeof(double),compareDouble);
	ASSERT(_30p0 == *result);
}

void test_search_56p0_in_array_of_five_element(){
	double fiveDouble[5] = {3.0,23.0,30.0,45.0,56.0};
	double _56p0 = 56.0;
	double* result = (double*)binarySearch(&_56p0,fiveDouble,5,sizeof(double),compareDouble);
	ASSERT(_56p0 == *result);
}

void test_search_3p0_in_array_of_eight_element(){
	double _8_Double[8] = {3.0,23.0,30.0,45.0,56.0,78.0,80.0,89.0};
	double _3p0 = 3.0;
	double* result = (double*)binarySearch(&_3p0,_8_Double,8,sizeof(double),compareDouble);
	ASSERT(_3p0 == *result);
}

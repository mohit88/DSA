#include "testUtils.h"
#include "stack.h"
#include <memory.h>

typedef char String[256];


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack* integerStack;
Stack* doubleStack;
Stack* stringStack;

int areStackEqual(Stack* expected,Stack* actual){
	int  result = expected->elementSize == actual->elementSize
					&& expected->length == actual->length 
					&& expected->top	== actual->top;
	if(!result) return result;
	if(expected->top == -1)return 1;
	return 0 == memcmp(expected->data,actual->data,expected->top*expected->elementSize);
}
void setup(){
	integerStack = createStack(5,sizeof(int));
	doubleStack = createStack(5,sizeof(double));
	stringStack = createStack(5,sizeof(String));
}

void tearDown(){
	dispose(integerStack);
	dispose(doubleStack);
}

void test_creating_stack_initialize_with_zero(){
	Stack* stack = createStack(5, 4);
	int data[5] = {0,0,0,0,0};
	Stack expected = {data,5,4,-1};
	ASSERT(areStackEqual(&expected, stack));
	dispose(stack);
}

void test_pushing_integer_in_null_stack(){
	int data[5] = {8,0,0,0,0};
	int eight = 8,result;
	Stack expected = {data,5,4,0};
	result = push(integerStack, &eight);
	ASSERT( result==1);
	ASSERT(areStackEqual(&expected, integerStack));
}

void test_pushing_integer_in_full_stack(){
	int* intData = (int*)integerStack->data;
	int _3 = 3 , result;
	int data[5] = {8,4,2,4,2};
	Stack expected = {data,5,4,4};
	integerStack->top = 4;
	intData[0] = 8;intData[1] = 4;intData[2] = 2;
	intData[3] = 4;	intData[4] = 2;
	result = push(integerStack, &_3);
	ASSERT( result==0);
	ASSERT(areStackEqual(&expected, integerStack));
}



void test_pushing_double_in_null_stack(){
	double data[5] = {8.0,0,0,0,0};
	double _8p0 = 8.0, result;
	Stack expected = {data,5,8,0};
	result = push(doubleStack, &_8p0);
	ASSERT( result==1);
	ASSERT(areStackEqual(&expected, doubleStack));
}

void test_pushing_double_in_full_stack(){
	double* doubleData = (double*)doubleStack->data;
	double _3p0 = 3.0, result;
	double data[5] = {8.0,4.0,2.0,4.0,2.0};	
	Stack expected = {data,5,8,4};
	doubleStack->top = 4;
	doubleData[0] = 8.0;doubleData[1] = 4.0;doubleData[2] = 2.0;
	doubleData[3] = 4.0;	doubleData[4] = 2.0;
	result = push(doubleStack, &_3p0);
	ASSERT(areStackEqual(&expected, doubleStack));
	ASSERT( result==0);
}

void test_pushing_string_in_null_stack(){
	String data[5] = {"hi!",0,0,0,0};
	String hi = "hi!";
	Stack expected = {data,5,256,0};
	ASSERT(push(stringStack, &hi));
	ASSERT(areStackEqual(&expected,stringStack));
}


void test_poping_integer_from_null_stack(){
	ASSERT(NULL==pop(integerStack));
}


void test_poping_integer_from_full_stack(){
	int* intData = (int*)integerStack->data;
	integerStack->top = 4;
	intData[0] = 8;intData[1] = 4;intData[2] = 2;
	intData[3] = 4;	intData[4] = 2;
	ASSERT(2 == *(int*)pop(integerStack));
}


void test_poping_double_from_null_stack(){
	ASSERT(NULL==pop(doubleStack));
}

void test_poping_double_from_full_stack(){
	double* doubleData = (double*)doubleStack->data;
	doubleStack->top = 4;
	doubleData[0] = 8.0;doubleData[1] = 4.0;doubleData[2] = 2.0;
	doubleData[3] = 4.0;	doubleData[4] = 2.0;
	ASSERT(2.0 == *(double*)pop(doubleStack));
}

void test_poping_string_from_null_stack(){
	ASSERT(NULL==pop(stringStack));
}

void test_poping_string_from_string_stack(){
	String hi = "hi";
	push(stringStack, &hi);
	ASSERT(0 == strcmp(hi,*(String*)pop(stringStack)));
}

void test_retrive_top_element_from_null_stack(){
	ASSERT(NULL == top(integerStack));
}

void test_retrive_top_element_from_stack(){
	int* intData = (int*)integerStack->data;
	integerStack->top = 2;
	intData[0] = 8;intData[1] = 4;intData[2] = 2;
	ASSERT(2 == *(int*)top(integerStack));
}

void test_stack_is_empty(){
	ASSERT(1 == isEmpty(integerStack));
}
void test_stack_is_not_empty(){
	integerStack->top = 3;
	ASSERT(0 == isEmpty(integerStack));
}
void test_stack_is_full(){
	integerStack->top = 4;
	ASSERT(1 == isFull(integerStack));
}
void test_stack_is_not_full(){
	integerStack->top = 2;
	ASSERT(0 == isFull(integerStack));
} 

#include "testUtils.h"
#include "stackWithoutMem.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_creating_stack_of_length_3(){
	int _3 = 3;
	Stack* stack = createStack(_3);
	ASSERT(_3 == stack->length);
	ASSERT(-1 == stack->top);
	dispose(stack);
}

void test_pushing_element_in_stack(){
	int _5 = 5;
	Stack* integerStack = createStack(3);
	ASSERT(push(integerStack,&_5));
	dispose(integerStack);
}

void test_cant_push_element_in_full_stack(){
	int _5 = 5;
	Stack* integerStack = createStack(0);
	ASSERT(0 == push(integerStack,&_5));
	dispose(integerStack);
}

void test_pop_element_from_stack(){
	int _5 = 5,_6 = 6;
	Stack* integerStack = createStack(3);
	ASSERT(push(integerStack,&_5));
	ASSERT(push(integerStack, &_6));
	ASSERT(_6 == *(int*)pop(integerStack));
	// dispose(integerStack);
}


void test_poping_element_from_an_empty_stack(){
	Stack* integerStack = createStack(3);
	ASSERT(NULL == pop(integerStack));
	dispose(integerStack);
}

void test_retriving_top_element_of_stack(){
	int _5 = 5,_6 = 6;
	Stack* integerStack = createStack(3);
	ASSERT(push(integerStack,&_5));
	ASSERT(push(integerStack, &_6));
	ASSERT(_6 == *(int*)top(integerStack));
	// dispose(integerStack);
}

void test_cant_retrive_top_element_from_an_empty_stack(){
	Stack* integerStack = createStack(3);
	ASSERT(NULL == top(integerStack));
	dispose(integerStack);
}
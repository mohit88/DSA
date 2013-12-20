#include "testUtils.h"
#include "stackUsingLinkedList.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_stack(){
	Stack * stack = createStack();
	ASSERT(stack->length == 0);	
	disposeStack(stack);
}

void test_push_element_into_stack(){
	int _8 = 8;
	Stack* integerStack = createStack();
	ASSERT(push(integerStack, &_8));
	disposeStack(integerStack);
}

void test_pop_element_from_stack(){
	int _8 = 8 ,_16 = 16;
	Stack* integerStack = createStack();
	ASSERT(push(integerStack, &_8));
	ASSERT(push(integerStack, &_16));
	ASSERT(_16 == *(int*)pop(integerStack));
	disposeStack(integerStack);
}

void test_pop_element_from_stack_without_having_element(){
	int _8 = 8 ,_16 = 16;
	Stack* integerStack = createStack();
	ASSERT(NULL == pop(integerStack));
	disposeStack(integerStack);
}

void test_retriving_top_element_from_stack(){
	int _8 = 8 ,_16 = 16;
	Stack* integerStack = createStack();
	ASSERT(push(integerStack, &_8));
	ASSERT(push(integerStack, &_16));
	ASSERT(_16 == *(int*)top(integerStack));
	disposeStack(integerStack);
}

void test_retriving_top_element_from_empty_stack(){
	Stack* integerStack = createStack();
	ASSERT(NULL == top(integerStack));
	disposeStack(integerStack);
}
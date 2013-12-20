#include <stdio.h>
#include "stack.h"
#include <memory.h>
#include <stdlib.h>

Stack* createStack(int length,int elementSize){
	Stack* stack = (Stack*)calloc(1,sizeof(Stack));
	stack->data = calloc(length, elementSize);
	stack->elementSize = elementSize;
	stack->length = length;
	stack->top = -1;
	return stack;
};

int push(Stack* stack,void* element){
	void* topPtr;
	if(isFull(stack)) return 0;
	stack->top += 1;
	topPtr = (stack->data)+((stack->top)*(stack->elementSize));
	memcpy(topPtr,element,stack->elementSize);
	return 1;
};

void* pop (Stack* stack){
	void* topPtr;
	if(isEmpty(stack)){
		return NULL;
	}
	topPtr = (stack->data)+((stack->top)*(stack->elementSize));
	stack->top -= 1;
	return topPtr;
};

void* top(Stack *stack){
	if(-1 == stack->top) return NULL;
	return (stack->data)+((stack->top)*(stack->elementSize));
}

int isEmpty(Stack* stack){
	if(-1 == stack->top) return 1;
	return 0;
}

int isFull (Stack* stack){
	if((stack->top) >= (stack->length-1)) return 1;
	return 0;
}

void dispose(Stack* stack){
	free(stack->data);
	free(stack);
}
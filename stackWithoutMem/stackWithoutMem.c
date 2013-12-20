#include "stackWithoutMem.h"
#include <stdlib.h>

Stack* createStack(int length){
	Stack* stack = calloc(1, sizeof(Stack));
	stack->data = calloc(length, sizeof(void*));
	stack->length = length;
	stack->top = -1;
	return stack;
}

int push(Stack* stack,void* data){
	void ** newTop;
	if(stack->top == stack->length-1) return 0;
	stack->top += 1;
	newTop = (stack->data + (stack->top * sizeof(void*)));
	*newTop = data;
	return 1;
}

void* pop(Stack *stack){
	void* data;
	if(stack->top == -1) return NULL;
	data = *(stack->data + (stack->top * sizeof(void*)));
	stack->top -= 1;
	return data;
}

void* top(Stack *stack){
	void* data;
	if(stack->top == -1) return NULL;
	data = *(stack->data + (stack->top * sizeof(void*)));
	return data;
}

void dispose(Stack* stack){
	free(stack->data);
	free(stack);
}
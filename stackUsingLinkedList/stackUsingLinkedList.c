#include "stackUsingLinkedList.h"
#include <stdlib.h>
Stack* createStack(){
	return createList();
}

int push(Stack * stack ,void* data){
	return insert(stack, 0, data);
}

void * pop(Stack *stack){
	void* data;
	if(stack->length==0) return NULL;
	data = getElement(stack, 0);
	if(!data) deleteNode(stack, 0);
	return data;
}

void* top(Stack *stack){
	void* data;
	if(stack->length==0) return NULL;
	data = getElement(stack, 0);
	return data;	
}

void disposeStack(Stack* stack){
	disposeList(stack);
}
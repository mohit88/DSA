#include "../linkedList/linkedList.h"

typedef List Stack;
Stack* createStack();
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);
void disposeStack(Stack* stack);
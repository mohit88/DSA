typedef struct{
	void** data;
	int length;
	int top;
}Stack;

Stack* createStack(int length);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack); 
void dispose(Stack* stack);

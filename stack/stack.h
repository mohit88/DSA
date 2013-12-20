typedef struct{
	void* data;
	int length;
	int elementSize;
	int top;
}Stack;

Stack* createStack(int length,int elementSize);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack); 
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void dispose(Stack* stack);


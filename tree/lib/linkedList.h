typedef struct type{
	struct type *previous;
	void *data;
	struct type * next;
} Node;
typedef struct{
	int length;
	Node* head;
	Node* tail;
}List;

List* createList();

void* getElement(List* list,int index);
int insert(List* list,int index, void* data);
void* deleteNode(List* list,int index);
void disposeList(List* list);
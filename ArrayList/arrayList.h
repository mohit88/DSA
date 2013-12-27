typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef struct ArrayIterator{
	ArrayList* list;
	int position;
	void* (*next)(struct ArrayIterator *it);
	int (*hasNext)(struct ArrayIterator *it);
} ArrayIterator;


typedef int CompareFunc(void* first,void* second);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
int add(ArrayList* list,void* data);

void* get(ArrayList *list, int index);

void* removeElement(ArrayList *list,int index);

int search(ArrayList* list,void* data,CompareFunc* compare);

ArrayIterator getIterator(ArrayList* list);

void dispose(ArrayList *list);
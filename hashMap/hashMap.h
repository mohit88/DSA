#include "./lib/linkedList.h"
typedef int CompareFunc(void* first, void* second);
typedef int HashCodeGeneratorFunc(void* key);

typedef struct{
	void* key;
	void* value;
} MapNode;

typedef struct {
	List** buckets;
	int capacity;
 	HashCodeGeneratorFunc* hashCodeGenerator;
	CompareFunc* comparator;
} HashMap;


HashMap* createHashMap(HashCodeGeneratorFunc* hashCodeGenerator, CompareFunc* comparator);
int putMapNode(HashMap *map, void *key, void *value);
void* getValue(HashMap *map, void *key);
int removeMapNode(HashMap *map, void *key);

void disposeHashMap(HashMap* map);

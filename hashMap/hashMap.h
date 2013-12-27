typedef int CompareFunc(void* first, void* second);
typedef int HashCodeGeneraterFunc(void* key);

typedef struct {
	void* buckets;
	int capacity;
 	HashCodeGeneraterFunc* hashCodeGenerator;
	CompareFunc* compare;
} HashMap;


HashMap* createHashMap(HashCodeGeneraterFunc* hashCodeGenerator, CompareFunc* compare);
int put(HashMap *map, void *key, void *value);
void* get(HashMap *map, void *key);
int remove(HashMap *map, void *key);
void disposeHashMap(HashMap* hashMap);
#include <stdlib.h>

typedef int CompareFunc(const void*,const void*);

void* binarySearch(void* key,void* base,
					size_t cntObjects,size_t sizeObject,
					CompareFunc* compare);

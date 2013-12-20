#include <stdlib.h>

typedef int CompareFunc(void* first, void* second);

void isort(void* base, size_t numberOfElements, size_t elementSize,
	CompareFunc* comp);

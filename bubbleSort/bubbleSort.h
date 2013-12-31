#include <stdlib.h>
typedef int CompareFunc(void* first,void* second);

void bubbleSort(void **base, size_t items, CompareFunc* compare);
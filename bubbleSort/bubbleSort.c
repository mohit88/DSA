#include "bubbleSort.h"

void bubbleSort(void *base, size_t items, size_t size, CompareFunc* compare){
	void* temp = malloc(size);
	int i ,j;
	for(i = items-1;i>=0;i--)
		for (j = 0; j < i; j++)
			if(0 < compare(base+(j*size),base+(j+1)*size)){
				memcpy(temp,base+(j*size),size);
				memcpy(base+j*size,base+(j+1)*size,size);
				memcpy(base+(j+1)*size,temp,size);
			}
	free(temp);
}

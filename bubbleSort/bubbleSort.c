#include "bubbleSort.h"

void bubbleSort(void **base, size_t items, CompareFunc* compare){
	void* temp;
	int index ,inner;
	for(index = items-1;index>=0;index--)
		for (inner = 0; inner < index; inner++)
			if(0 < compare(base[inner],base[inner+1])){
				temp = base[inner];
				base[inner] = base[inner+1];
				base[inner+1] = temp;
			}
}

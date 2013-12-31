#include "mergeSort.h"

void mergeSort(void **base, size_t noOfItems, CompareFunc *compare){
	int mid = noOfItems/2,
	leftLength = mid,
	rightLength = noOfItems - mid,
	leftIndex,rightIndex,baseIndex,comparisonResult;
	void ** leftItems = calloc(leftLength, sizeof(void*));
	void ** rightItems = calloc(rightLength, sizeof(void*));
	for(leftIndex = 0;leftIndex < leftLength;leftIndex++){
		leftItems[leftIndex] = base[leftIndex];
	}
	for(rightIndex = leftLength;rightIndex < noOfItems;rightIndex++){
		rightItems[rightIndex] = base[rightIndex];
	}
	leftIndex = 0;
	rightIndex = leftLength;
	baseIndex = 0;
	while(leftIndex < leftLength && rightIndex < noOfItems){
		comparisonResult = compare(leftItems[leftIndex],rightItems[rightIndex]);
		if(0 > comparisonResult)
			base[baseIndex++] = leftItems[leftIndex++];
		else base[baseIndex++] = rightItems[rightIndex++];
	}
	while(leftIndex < leftLength)
		base[baseIndex++] = leftItems[leftIndex++];
	while(rightIndex < noOfItems)
		base[baseIndex++] = rightItems[rightIndex++];
}
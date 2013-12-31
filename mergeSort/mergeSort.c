#include "mergeSort.h"

void merge(void** base,void** leftItems,int leftLen,void** rightItems,int rightLen,CompareFunc* compare){
	int leftIndex = 0,
	rightIndex = 0,
	baseIndex = 0,
	comparisonResult;	
	while(leftIndex < leftLen && rightIndex < rightLen){
		comparisonResult = compare(leftItems[leftIndex],rightItems[rightIndex]);
		if(0 > comparisonResult)
			base[baseIndex++] = leftItems[leftIndex++];
		else base[baseIndex++] = rightItems[rightIndex++];
	}
	while(leftIndex < leftLen)
		base[baseIndex++] = leftItems[leftIndex++];
	while(rightIndex < rightLen)
		base[baseIndex++] = rightItems[rightIndex++];	
}

void mergeSort(void **base, size_t noOfItems, CompareFunc *compare){
	int mid = noOfItems/2,
	leftLen = mid,
	rightLen = noOfItems - mid,
	leftIndex,rightIndex,baseIndex,comparisonResult;
	void ** leftItems;
	void ** rightItems;
	if(2 > noOfItems) return;
	leftItems = calloc(leftLen, sizeof(void*));
	rightItems = calloc(rightLen, sizeof(void*));
	for(leftIndex = 0; leftIndex < leftLen; leftIndex++){
		leftItems[leftIndex] = base[leftIndex];
	}
	for(rightIndex = leftLen;rightIndex < noOfItems;rightIndex++){
		rightItems[rightIndex-leftLen] = base[rightIndex];
	}
	mergeSort(leftItems, leftLen, compare);
	mergeSort(rightItems, rightLen, compare);
	merge(base, leftItems, leftLen, rightItems, rightLen, compare);
	free(leftItems);
	free(rightItems);
}
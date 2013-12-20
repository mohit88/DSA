#include "binarySearch.h"

void* binarySearch(void *key,void *base, size_t cntObject, size_t sizeObject, CompareFunc* compare){
	int	middle = (cntObject/2),
	comparisonResult = compare(key,base+(middle*sizeObject));
	if(0 == comparisonResult) return base+(middle*sizeObject);
	if(0 == middle)return NULL;
	if(0 < comparisonResult)
		return binarySearch(key,base+((middle+1)*sizeObject),middle,sizeObject,compare);
	if(0 > comparisonResult)
		return binarySearch(key,base,middle,sizeObject,compare);
}

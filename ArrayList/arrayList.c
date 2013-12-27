#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsRightIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	increaseCapacity(list);
	shiftElementsRightIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}

int add(ArrayList* list,void* data){
	return insert(list, list->length, data);
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}

void shiftElementsLeftIfNeeded(ArrayList *list, int index){
	int i;
	if (index < list->length-1) {
		for (i = index+1; i < list->length; i++) {
			list->base[i-1] = list->base[i];
		}
	}
}

void* removeElement(ArrayList *list,int index){
	void* data;
	if (index < 0 || index >= list->length) return NULL;
	data = get(list,index);
	shiftElementsLeftIfNeeded(list, index);
	list->length--;
	return data;
};

int search(ArrayList *list,void* data, CompareFunc* compare){
	int index;
	if (list == NULL) return -1;
	for (index = 0; index < list->length; index++)		
		if(compare(data,list->base[index]))
			return index;
	return -1;
};

int hasNext(ArrayIterator* it){
	ArrayList *list = it->list;
	if(list->length <= it->position) return 0;
	return 1;
}

void* getNext(ArrayIterator* it){
	ArrayList* list = it->list;
	if(!hasNext(it)) return NULL;
	return list->base[it->position++];
}
ArrayIterator getIterator(ArrayList* list){
	ArrayIterator it;
	it.list = list;
	it.position = 0;
	it.hasNext = &hasNext;
	it.next = &getNext;
	return it;
}

void dispose(ArrayList *list) {
	free(list->base);
}
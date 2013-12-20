#include "linkedList.h"
#include <stdlib.h>

Node* getNode(List* list,int index){
	int i;
	Node* nextNode = list->head;
	for (i = 0; i < index; ++i){
		nextNode = nextNode->next;
	}
	return nextNode;
}

List* createList(){
	List* list = calloc(1,sizeof(List));
	list->length = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

int insertNodeAtHead(List* list,Node* newNode){
	Node* nextNode;
	newNode->previous = NULL;
	nextNode = list->head;
	newNode->next = list->head;
	list->head = newNode;
	if(list->length == 0)list->tail = newNode;
	else nextNode->previous = newNode;
	list->length += 1;
	return 1;
}

int insertNodeAtTail(List* list,Node* newNode){
	newNode->next = NULL;
	list->tail->next = newNode;
	newNode->previous = list->tail;
	list->tail = newNode;
	list->length += 1;
	return 1;	
}

int insertNodeInBetween(List*list,int index,Node* newNode){
	Node* nextNode = getNode(list,index);
	newNode->next = nextNode;
	newNode->previous = nextNode->previous;
	nextNode->previous = newNode;
	newNode->previous->next = newNode;
	list->length += 1;
	return 1;	
}

int insert(List* list,int index, void* data){
	Node* newNode = (Node*)calloc(1,sizeof(Node));
	if(0 > index && index > list->length) return 0;
	newNode->data = data;
	if(index == 0)
		return insertNodeAtHead(list,newNode);
	if(index == list->length)
		return insertNodeAtTail(list, newNode);
	if(0 < index && index < list->length)
		return insertNodeInBetween(list, index, newNode);
	return 0;
}

void* deleteNodeFromHead(List* list){
	Node* nextNode = list->head->next;
	void* data = list->head->data;
	list->length -= 1;
	free(list->head);
	list->head = nextNode;
	if(list->length == 0) list->tail = NULL;
	else nextNode->previous = NULL;
	return data;
}

void* deleteNodeFromTail(List *list){
	Node* previousNode = list->tail->previous;
	void* data = list->tail->data;
	free(list->tail);
	previousNode->next = NULL;
	list->tail = previousNode;
	list->length -= 1;
	return data;
}

void* deleteNodeInBetween(List *list,int index){
	Node* currentNode = getNode(list, index);
	void* data = currentNode->data;
	Node* nextNode = currentNode->next;
	Node* previousNode = currentNode->previous;
	nextNode->previous = previousNode;
	previousNode->next = nextNode;
	list->length -= 1;
	free(currentNode);
	return data;
}

void* deleteNode(List *list, int index){
	if(index == 0)
		return deleteNodeFromHead(list);
	if(index == list->length-1)
		return deleteNodeFromTail(list);
	if(0 < index && index < list->length)
		return deleteNodeInBetween(list,index);
	return NULL;
}

void * getElement(List *list, int index){
	Node* node;
	if(index > list->length) return NULL;
	node = getNode(list, index);
	return node->data;
	return NULL;
}

void disposeList(List* list){
	Node* currentNode = list->head,*nextNode;
	while(currentNode!=NULL){
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
	free(list);
}

#include "testUtils.h"
#include "priorityQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areElementsEqual(Element* expected,Element* actual){
	int result = *(int*)(expected->data) == *(int*)(actual->data) 
				&& expected->priority == actual->priority;
	return result;
}

int compareAscend(void* priority1,void* priority2){
	return *(int*)priority1 - *(int*)priority2;
}


int compareDecend(void* priority1,void* priority2){
	return *(int*)priority2 - *(int*)priority1;
}



void test_create_priority_queue(){
	PriorityQueue* priorityQ = createPriorityQ();
	ASSERT(priorityQ->length == 0);
	disposePriorityQ(priorityQ);
}

void test_insert_data_with_priority_into_priority_queue(){
	int _34 = 34;
	PriorityQueue* priorityQ = createPriorityQ();
	Element data = {&_34,10};
	ASSERT(enqueue(priorityQ,&data,compareAscend));
	disposePriorityQ(priorityQ);
}

void test_insert_data_with_priority_into_priority_queue_having_more_than_1_elements(){
	int _34 = 34,_55=55;
	PriorityQueue* priorityQ = createPriorityQ();
	Element data[3] = {{&_34,10},{&_55,11},{&_34,9}};
	ASSERT(enqueue(priorityQ,&data[0],compareAscend));
	ASSERT(enqueue(priorityQ,&data[1],compareAscend));
	ASSERT(enqueue(priorityQ,&data[2],compareAscend));
	disposePriorityQ(priorityQ);
}

void test_delete_from_priority_Queue(){
	int _34 = 34,_55=55;
	PriorityQueue* priorityQ = createPriorityQ();
	Element data[3] = {{&_34,10},{&_55,11},{&_34,9}};
	ASSERT(enqueue(priorityQ,&data[0],compareAscend));
	ASSERT(enqueue(priorityQ,&data[1],compareAscend));
	ASSERT(enqueue(priorityQ,&data[2],compareAscend));
	ASSERT(areElementsEqual(&(data[2]),dequeue(priorityQ)));
	disposePriorityQ(priorityQ);
}

void test_delete_from_priority_Queue_having_two_elements(){
	int _34 = 34,_55=55;
	PriorityQueue* priorityQ = createPriorityQ();
	Element data[3] = {{&_34,10},{&_55,11}};
	ASSERT(enqueue(priorityQ,&data[0],compareAscend));
	ASSERT(enqueue(priorityQ,&data[1],compareAscend));
	ASSERT(areElementsEqual(&(data[0]),dequeue(priorityQ)));
	disposePriorityQ(priorityQ);
}


void test_insert_data_with_priority__in_Decend_into_priority_queue_having_more_than_1_elements(){
	int _34 = 34,_55=55;
	PriorityQueue* priorityQ = createPriorityQ();
	Element data[3] = {{&_34,10},{&_55,11},{&_34,9}};
	ASSERT(enqueue(priorityQ,&data[0],compareDecend));
	ASSERT(enqueue(priorityQ,&data[1],compareDecend));
	ASSERT(enqueue(priorityQ,&data[2],compareDecend));
	ASSERT(areElementsEqual(&(data[1]),dequeue(priorityQ)));
	disposePriorityQ(priorityQ);
}


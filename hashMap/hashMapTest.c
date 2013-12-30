#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compare(void* first,void* second){
	return *(int*)first - *(int*)second;
}

int hashCodeGenerator(void* key){
	return *(int*)key;
}
HashMap* map;

void setup(){
	map = createHashMap(hashCodeGenerator, compare);
}

void tearDown(){
	disposeHashMap(map);
}

void test_put_key_and_value_in_hash_map(){
	int key = 1;
	int value = 10;
	ASSERT(putMapNode(map, &key,&value));
	ASSERT(&value == getValue(map, &key));
}

void test_put_value_which_has_already_present_key_in_hash_map(){
	int key = 1;
	int _10 = 10,_20 = 20;
	ASSERT(putMapNode(map, &key,&_10));
	ASSERT(putMapNode(map, &key,&_20));
	ASSERT(&_20 == getValue(map, &key));
}

void test_get_value_which_is_not_present_key_in_hash_map(){
	int key = 1;
	ASSERT(NULL == getValue(map, &key));
}

void test_removing_specific_key_and_value_from_hash_map(){
	int key = 1;
	int value = 10;
	ASSERT(putMapNode(map, &key,&value));
	ASSERT(removeMapNode(map, &key));
	ASSERT(NULL == getValue(map, &key));
}

void test_removing_key_and_value_which_is_not_present_in_hash_map(){
	int key = 1;
	ASSERT(0 == removeMapNode(map, &key));
}

void test_getting_all_the_keys_in_hash_map(){
	int key = 1;
	int value = 10;
	MapIterator mapIt;
	ASSERT(putMapNode(map, &key,&value));
	mapIt = mapKeys(map);
	ASSERT(&key == nextKey(&mapIt));
	ASSERT(NULL == nextKey(&mapIt));
}

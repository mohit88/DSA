#include "testUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compare(void* first,void* second){
	return *(int*)first - *(int*)second;
}

int hashCodeGenerator(void* key){
	return *(int*)key;
}

void test_put_key_and_value_in_hash_map(){
	HashMap* map = createHashMap(hashCodeGenerator, compare);
	int key = 1;
	int value = 10;
	ASSERT(putMapNode(map, &key,&value));
	ASSERT(&value == getValue(map, &key));
}

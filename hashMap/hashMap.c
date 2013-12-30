#include "hashMap.h"
#include <stdlib.h>

HashMap* createHashMap(HashCodeGeneratorFunc* hashCodeGenerator, CompareFunc* comparator){
	int index;
	HashMap* map = (HashMap*)calloc(1,sizeof(HashMap));
	map->capacity = 10;
	map->buckets = (List**)calloc(map->capacity, sizeof(List*));
	map->hashCodeGenerator = hashCodeGenerator;
	map->comparator = comparator;
	for (index = 0; index < map->capacity; ++index){
		map->buckets[index] = createList();
	}
	return map;
}

MapNode* getMapNode(HashMap* map,int bucket,void* key){
	int index;
	MapNode* mapNode;
	List* currentBucket = map->buckets[bucket];
	for (index = 0; index < currentBucket->length; ++index){
		mapNode = getElement(currentBucket, index);
		if(0 == map->comparator(key,mapNode->key))
			return mapNode;
	}
	return NULL;
}

MapNode* createMapNode(void* key,void* value){
	MapNode* mapNode = calloc(1, sizeof(MapNode));
	mapNode->key = key;
	mapNode->value = value;
	return mapNode;
}

int putMapNode(HashMap *map, void *key, void *value){
	int hashCode = map->hashCodeGenerator(key);
	int bucket = hashCode % map->capacity;
	List* currentBucket = map->buckets[bucket];
	MapNode* mapNode = getMapNode(map, bucket, key);
	if(mapNode == NULL){
		mapNode = createMapNode(key, value);	
		return insert(currentBucket,currentBucket->length,mapNode);
	}
	mapNode->value = value;
	return 1;
}

void* getValue(HashMap *map, void *key){
	int hashCode = map->hashCodeGenerator(key);
	int bucket = hashCode % map->capacity;
	MapNode* mapNode = getMapNode(map, bucket, key);
	return mapNode->value;
}

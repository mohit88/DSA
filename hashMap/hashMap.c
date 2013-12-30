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
	if (mapNode == NULL) return mapNode;
	return mapNode->value;
}

int getPosition(List* list,MapNode* mapNode){
	int index;
	for (index = 0; index < list->length; ++index){
		if(mapNode == getElement(list, index))
			return index;
	}
	return -1;
}

int removeMapNode(HashMap *map, void *key){
	int position;
	int hashCode = map->hashCodeGenerator(key);
	int bucket = hashCode % map->capacity;
	List* currentBucket = map->buckets[bucket];
	MapNode* mapNode = getMapNode(map, bucket, key);
	if(mapNode == NULL) return 0;
	position = getPosition(currentBucket,mapNode);
	deleteNode(currentBucket, position);
	free(mapNode);
	return 1;
}

int hasNextKey(MapIterator* it){
	if(it->currentPos == it->list->length) return 0;
	return 1;
}

void* nextKey(MapIterator* it){
	void* key;
	if(!hasNextKey(it)) return NULL;
	key = getElement(it->list, it->currentPos);
	it->currentPos += 1;
	return key;
}


void addKeysToIterator(List* destList,HashMap* map){
	int index,inner;
	List* currentBucket;
	MapNode* currentMapNode;
	for (index = 0; index < map->capacity; ++index){
		currentBucket = map->buckets[index];
		for(inner = 0;inner < currentBucket->length;inner++){
			currentMapNode = getElement(currentBucket, inner);
			insert(destList, destList->length, currentMapNode->key);
		}
	}
}

MapIterator mapKeys(HashMap* map){
	MapIterator mapIt;
	mapIt.list = createList();
	mapIt.currentPos = 0;
	addKeysToIterator(mapIt.list,map);
	return mapIt;
}


void disposeHashMap(HashMap* map){
	int index;
	for (index = 0; index < map->capacity; ++index){
		disposeList(map->buckets[index]);
	}
	free(map->buckets);
	free(map);
}


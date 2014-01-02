#include "testUtils.h"
#include "BSTree.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void * second){
	return *(int *)first - *(int*)second;
}

void test_create_and_insert_in_BSTree(){
	int _10 = 10;
	BSTree* tree = createBSTree(compareInteger);
	ASSERT(insertBSTreeNode(tree, &_10));
}

void test_insert_two_integers_in_BSTree(){
	int _10 = 10,_20 = 20;
	BSTree* tree = createBSTree(compareInteger);
	ASSERT(insertBSTreeNode(tree, &_10));
	ASSERT(insertBSTreeNode(tree, &_20));
}

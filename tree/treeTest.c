#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

Tree* tree;

void setup(){
	tree = createTree(compareInteger);
}

void test_insert_child_node_to_root_in_tree(){
	Iterator it;
	int _10 = 10,_20 = 20;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	it = getChildren(tree,&_10);
	ASSERT(&_20 == next(&it));
	ASSERT(NULL == next(&it));
}

void test_insert_two_child_node_to_root_in_tree(){
	Iterator it;
	int _10 = 10,_20 = 20,_30 = 30;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	ASSERT(insertTreeNode(tree, &_30, &_10));
	it = getChildren(tree,&_10);
	ASSERT(&_20 == next(&it));
	ASSERT(&_30 == next(&it));
	ASSERT(NULL == next(&it));
}

void test_insert_child_node_to_random_parent_in_tree(){
	Iterator _10sChildren,_20sChildren;
	int _10 = 10,_20 = 20,_30 = 30,_40 = 40;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	ASSERT(insertTreeNode(tree, &_30, &_10));
	ASSERT(insertTreeNode(tree, &_40, &_20));	
	_10sChildren = getChildren(tree,&_10);
	_20sChildren = getChildren(tree,&_20);
	ASSERT(&_20 == next(&_10sChildren));
	ASSERT(&_30 == next(&_10sChildren));
	ASSERT(NULL == next(&_10sChildren));
	ASSERT(&_40 == next(&_20sChildren));
	ASSERT(NULL == next(&_20sChildren));	
}

void test_insert_root_node_in_tree_having_root_node_already(){
	Iterator it;
	int _10 = 10,_20 = 20;
	ASSERT(insertTreeNode(tree, &_20,NULL));
	ASSERT(insertTreeNode(tree, &_10,NULL));
	it = getChildren(tree,&_10);
	ASSERT(&_20 == next(&it));
	ASSERT(NULL == next(&it));
}

void test_delete_child_node_of_root_from_tree(){
	Iterator it;
	int _10 = 10,_20 = 20,_30 = 30;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	ASSERT(insertTreeNode(tree, &_30, &_10));
	ASSERT(deleteTreeNode(tree,&_30));
	it = getChildren(tree,&_10);
	ASSERT(&_20 == next(&it));
	ASSERT(NULL == next(&it));
}

void test_should_not_delete_node_having_children(){
	int _10 = 10,_20 = 20;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(insertTreeNode(tree, &_20, &_10));
	ASSERT(0 == deleteTreeNode(tree,&_10));
}

void test_should_not_delete_node_which_is_not_present(){
	int _10 = 10,_20 = 20;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(0 == deleteTreeNode(tree,&_20));
}

void test_search_node_in_tree(){
	int _10 = 10;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(searchTreeNode(tree,&_10));
}

void test_searching_tree_node_which_is_not_present_in_tree(){
	int _10 = 10,_20 = 20;
	ASSERT(insertTreeNode(tree, &_10,NULL));
	ASSERT(0 == searchTreeNode(tree,&_20));
}


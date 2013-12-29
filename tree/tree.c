#include "tree.h"
#include <stdlib.h>

Tree* createTree(CompareFunc* compare){
	Tree* tree = calloc(1,sizeof(Tree));
	tree->root = NULL;
	tree->compare = compare;
	return tree;
}

void addChildrenToList(List* destList,TreeNode* parentNode){
	List* srcList = parentNode->children;
	int index;
	for (index = 0; index < srcList->length; index++){
		insert(destList, destList->length, getElement(srcList,index));
	}
}

TreeNode* getParentNode(Tree* tree,void* parentData){	
	TreeNode* parentNode = tree->root;
	List* elements = createList();
	int index;
	if(tree->root == NULL) return NULL;
	insert(elements, 0, parentNode);
	for (index = 0; index < elements->length; index++){
		parentNode = getElement(elements, index);
		if(0 == tree->compare(parentData,parentNode->data)) return parentNode;
		addChildrenToList(elements, parentNode);
	}
	disposeList(elements);
	return NULL;
}

int insertTreeNode(Tree *tree, void *data, void *parentData){
	TreeNode* parentNode;
	TreeNode* childNode = calloc(1, sizeof(TreeNode));
	childNode->data = data;
	childNode->children = createList();
	if(parentData == NULL){
		childNode->parentNode = NULL;
		tree->root = childNode;
		return 1;
	}
	parentNode = getParentNode(tree,parentData);
	childNode->parentNode = parentNode;
	return insert(parentNode->children,parentNode->children->length,childNode);
}

int hasNext(Iterator* it){
	if(it->currentPos == it->list->length) return 0;
	return 1;
}

void* next(Iterator* it){
	TreeNode* treeNode;
	if(!hasNext(it)) return NULL;
	treeNode = (TreeNode*)getElement(it->list, it->currentPos);
	it->currentPos += 1;
	return treeNode->data;
}

Iterator getChildren(Tree *tree,void* parentData){
	Iterator child;
	TreeNode* parentNode = getParentNode(tree, parentData);
	child.list = parentNode->children;
	child.currentPos = 0;
	return child;
}
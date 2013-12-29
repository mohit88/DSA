#include "tree.h"
#include <stdlib.h>

Tree* createTree(CompareFunc* compare){
	Tree* tree = calloc(1,sizeof(Tree));
	tree->root = NULL;
	tree->compare = compare;
	return tree;
}

TreeNode* getParentNode(Tree* tree,void* parentData){
	return tree->root;		
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
	if(!it->hasNext(it)) return NULL;
	treeNode = (TreeNode*)getElement(it->list, it->currentPos);
	it->currentPos += 1;
	return treeNode->data;
}

void addChildrenToList(List* destList,TreeNode* parentData){
	List* srcList = parentData->children;
	int index;
	for (index = 0; index < srcList->length; index++){
		insert(destList, destList->length, getElement(srcList,index));
	}
}

Iterator getIterator(Tree *tree){
	Iterator it;
	it.hasNext = hasNext;
	it.next = next;
	it.list = createList();
	it.currentPos = 0;
	insert(it.list, it.list->length, tree->root);
	addChildrenToList(it.list, tree->root);
	return it;
}
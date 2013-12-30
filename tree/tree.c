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
		if(NULL != tree->root)
			insert(childNode->children, 0, tree->root);
		tree->root = childNode;
		return 1;
	}
	parentNode = getParentNode(tree,parentData);
	childNode->parentNode = parentNode;
	return insert(parentNode->children,parentNode->children->length,childNode);
}

int deleteFromParent(List* children,TreeNode* child){
	int index;
	for (index = 0; index < children->length; ++index){
		if(child == getElement(children, index)){
			deleteNode(children, index);
			return 1;
		}	
	}
	return 0;
}

int deleteTreeNode(Tree *tree, void *data){
	int result;
	TreeNode* parentNode;
	TreeNode* treeNode = getParentNode(tree, data);
	if(treeNode == NULL) return 0;
	if(treeNode->children->length > 0) return 0;
	parentNode = treeNode->parentNode;
	result = deleteFromParent(parentNode->children,treeNode);
	free(treeNode);
	return result;
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

int searchTreeNode(Tree *tree, void *data){
	TreeNode* treeNode = getParentNode(tree, data);
	if(treeNode != NULL) return 1;
	return 0;
}

// void disposeTree(Tree* tree,TreeNode* treeNode){
// 	TreeNode* children
// 	Iterator it = getChildren(tree, treeNode->data);
// 	while(hasNext(&it)){
// 		treeNode = getParentNode(tree,next(&it));
// 		if(0 == treeNode->children->length){
// 			disposeTree(tree,next(&it));
// 		}
// 		disposeList(treeNode->children);
// 	}
// }

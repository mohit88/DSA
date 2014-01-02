#include "BSTree.h"
#include <stdlib.h>


BSTree* createBSTree(CompareFunc *compare){
	BSTree* tree = calloc(1,sizeof(BSTree));
	tree->compare = compare;
	tree->root = NULL;
	return tree;
}

int insertInEmptyTree(BSTree* tree,BSTreeNode*treeNode){
	treeNode->parent = NULL;
	treeNode->leftChild = NULL;
	treeNode->rightChild = NULL;
	tree->root = treeNode;
	return 1;
}

int insertBSTreeNode(BSTree *tree, void *data){
	BSTreeNode* treeNode = calloc(1, sizeof(BSTreeNode));
	treeNode->data = data;
	if(tree->root == NULL)
		return insertInEmptyTree(tree, treeNode);
	return 0;
}
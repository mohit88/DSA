#include "./lib/linkedList.h"

typedef struct treeNode{
	void * data;
	struct treeNode* parentNode;
	List* children;
} TreeNode;

typedef struct Iterator{
	List* list;
	int currentPos;
	void* (*next)(struct Iterator *it);
	int (*hasNext)(struct Iterator *it);
} Iterator;


typedef int CompareFunc(void* first,void* second);

typedef struct{
	TreeNode* root;
	CompareFunc* compare;
} Tree;

Tree* createTree(CompareFunc* compare);

int insertTreeNode(Tree* tree,void* data,void* parentData);

Iterator getIterator(Tree* tree);

void disposeTree(Tree* tree);
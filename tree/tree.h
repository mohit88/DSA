#include "./lib/linkedList.h"

typedef struct treeNode{
	void * data;
	struct treeNode* parentNode;
	List* children;
} TreeNode;

typedef struct{
	List* list;
	int currentPos;
} Iterator;
void* next(Iterator *it);
int hasNext(Iterator *it);


typedef int CompareFunc(void* first,void* second);

typedef struct{
	TreeNode* root;
	CompareFunc* compare;
} Tree;

Tree* createTree(CompareFunc* compare);

int insertTreeNode(Tree* tree,void* data,void* parentData);

int deleteTreeNode(Tree* tree,void* data);

int searchTreeNode(Tree* tree, void* data);

Iterator getChildren(Tree* tree,void* parentData);

void disposeIterator(Iterator* it);

void disposeTree(Tree* tree,TreeNode* rootNode);
typedef int CompareFunc(void *a , void *b);
typedef struct BSTreeNode{
	void* data;
	struct BSTreeNode* parent;
	struct BSTreeNode* leftChild;
	struct BSTreeNode* rightChild;
} BSTreeNode;

typedef struct {
	CompareFunc *compare;
	BSTreeNode *root;
} BSTree;

BSTree* createBSTree(CompareFunc *compare);
int insertBSTreeNode(BSTree* tree , void *data);
int searchBSTreeNode(BSTree* tree, void *data);

void disposeBSTree(BSTree* tree);
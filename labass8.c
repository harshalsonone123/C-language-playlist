/**
 * CSL 102 Lab 8
 * Submission deadline Wednesday July 7 @ 6am
 * 
 * Compilation error = ZERO
 * Submission filename not having your roll no = ZERO
 * Pleading for marks despite compilation error = NEGATIVE FOUR
 * Pleading for marks without running evalution tool = NEGATIVE FOUR
 * Copying code from each other = NEGATIVE FOUR
 * Keeping main function in the submission code = NEGATIVE FOUR
 * Keep the file extension in lower case c
 * 
 * * 
 * Suggestion:
 * * Implement the main function in a separate c file and not in the submission c file
 * */
#define EMPTYNODE 0

struct node
{
	short data;
	struct node *left;
	struct node *right;
};

typedef struct node nodeQ_t;

/**
 * Method to create a node by passing a value. 
 * Create a node on the heap memory and return the address
 **/
nodeQ_t *createNode(short value)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->left = EMPTYNODE;
	newNode->right = EMPTYNODE;

	return newNode;
};

/**
 * In this function you will convert a regular binary tree to a binary search tree
 * The input binTree is a regular binary tree
 * The return value is the root node for the new BST
 * You can choose to create a whole new tree or reuse the nodes (memory) from input binTreeRoot
 * The exact ordering of the BST might differ as per implementation
 * The validity of returned BST will be tested using Preorder traversal.
 * Input will not be EMPTYNODE
 **/
nodeQ_t *convertBinaryTree2BST(nodeQ_t *binTreeRoot)
{
	int treeSize = calculateSize(binTreeRoot);

	convertBTtoArray(binTreeRoot);

	int compare(const void *p, const void *q)
	{
		return (*(int *)p - *(int *)q);
	}
	qsort(treeArray, treeSize, sizeof(int), compare);

	struct node *e = createBST(0, treeSize - 1);
	return e;
};

/**
 * In this function you will flip a binary search tree
 * That is, in the flipped tree, nodes in the right subtree will be LESSER than left subtree
 * The return value is the root node for the new BST
 * You can choose to create a whole new tree or reuse the nodes (memory) from input bstRoot
 * The exact ordering of the BST might differ as per implementation
 * The validity of returned BST will be tested using Preorder traversal.
 * Input will not be EMPTYNODE
 **/
nodeQ_t *flipBST(nodeQ_t *bstRoot)
{
	if (bstRoot == EMPTYNODE)
		return;
	else
	{
		struct Node *temp;

		mirror(bstRoot->left);
		mirror(bstRoot->right);

		temp = bstRoot->left;
		bstRoot->left = bstRoot->right;
		bstRoot->right = temp;
	}
};

/**
 * In this function, you will merge two binary search trees (bst1Root and bst2Root)
 * The root of the merged BST will be returned by the function
 * The merged BST must not have any duplicates
 * The exact ordering of the BST might differ as per implementation
 * The validity of returned BST will be tested using Preorder traversal.
 * Input will not be EMPTYNODE
 **/
nodeQ_t *mergeTwoBSTs(nodeQ_t *bst1Root, nodeQ_t *bst2Root, int m, int n)
{
	int new;
	int *arr1 = new int[m];
	int i = 0;
	storeInorder(bst1Root, arr1, &i);

	int *arr2 = new int[n];
	int j = 0;
	storeInorder(bst2Root, arr2, &j);

	int *mergedArr = merge(arr1, arr2, m, n);

	return sortedArrayToBST(mergedArr, 0, m + n - 1);
};
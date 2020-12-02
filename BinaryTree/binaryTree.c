#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode
{
	double key;
	struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

int getLevel()
{
	return 0;
}
// Give a value, test whether it is BST.
// Case 1: If the given key is NULL, return false.
// Case 2: If the given key is key in the root node, return true.
// Case 3: Whether it is in the left tree, do the recursive call, and return true.
// Case 4: Whether it is in the right tree, do the recursive call, and return true.
// Case 5: If the given key is different, then return false.
int isInBST(TreeNodePtr root, double key)
{
	if (root == NULL)
	{ // Case 1
		return 0;
	}
	else if (root->key == key)
	{ // Case 2
		return 1;
	}
	else if (isInBST(root->left, key))
	{ // Case 3
		return 1;
	}
	else if (isInBST(root->right, key))
	{ // Case 4
		return 1;
	}
	else
	{ // Case 5
		return 0;
	}

	// Single Line Expression (based on logic boolean calculation)
	// return
	// root != NULL
	// && (root->key == key)
	// || isInBST(root->left, key)
	// || isInBST(root->right, key);
}

void printRoot(TreeNodePtr T)
{
	if(T==NULL) return;
	else printf("%lf::", T->key);
	printRoot(T->left);
	printRoot(T->right);
}
TreeNodePtr getMin(TreeNodePtr T){
	TreeNodePtr tmp = T;
	while(tmp && tmp->left != NULL) tmp = tmp->left;
	return tmp;
}
TreeNodePtr deleteRoot(TreeNodePtr T, double key)
{
	if (T==NULL) return T;
	TreeNodePtr tmp;
	tmp = T;
	
	if(key < T->key) tmp->left = deleteRoot(tmp->left, key);
	else if(key > T->key) tmp->right = deleteRoot(tmp->right, key);

	else{
		if(T->left == NULL){
			tmp = T->right;
			free(T);
			return tmp;
		}else if(T->right == NULL) {
			tmp = T->left;
			free(T);
			return tmp;
		}
		tmp = getMin(T->right);
		tmp->key = tmp->key;
		tmp->right = deleteRoot(T->right, tmp->key);
	}
	return tmp;
}

// Allow a null pointer here.
// Case 1: When root node is null.
// Case 2: When the root node has value, same as key, do nothing, return itself.
// Case 3: When the root node has value, larger than key, add to the left, do the recursive call.
// Case 4: When the root node has value, less than key, add to the right, do the recursive call.
TreeNodePtr addToBST(TreeNodePtr root, double key)
{
	if (root == NULL)
	{ // Case 1
		TreeNodePtr n = (TreeNodePtr)malloc(sizeof(TreeNode));
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	if (root->key == key)
	{ // Case 2
		return root;
	}
	if (key < root->key)
	{ // Case 3
		root->left = addToBST(root->left, key);
		return root;
	}
	else
	{ // Case 4
		root->right = addToBST(root->right, key);
		return root;
	}
	return root;
}

int main(int argc, char **argv)
{
	int i;
	double k;
	TreeNodePtr root = NULL;
	if (argc > 1)
	{

		for (i = 1; i < argc; i++)
		{
			double d;
			sscanf(argv[i], "%lf", &d);
			root = addToBST(root, d);
		}
	}

	printf("Test value: ");
	scanf("%lf", &k);

	if (isInBST(root, k))
	{
		printf("Found \n");

	}
	else
	{
		printf("Not Found \n");
	}
	
	printf("Before:\n");
	printRoot(root);
	printf("\n");
	printf("removing %lf...\n", k);
	printRoot(deleteRoot(root, k));
	printf("\n");
	return 0;
}

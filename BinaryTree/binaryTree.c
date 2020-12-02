#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode
{
	double key;
	struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

int getLevel()
{
}
TreeNodePtr deleteRoot(TreeNodePtr T, double key)
{
	TreeNodePtr tmp;
	// case 0
	if (isInBST(T, key))
		return T;
	else
	{
		tmp = T;
		// case 1
		// Remove the leaf node
		while (tmp->left != NULL && tmp->right != NULL)
		{
			// Right Leaf case 1
			if (tmp->right->key == key && tmp->right->left == NULL && tmp->right->right == NULL)
			{
				tmp->right = NULL;
				break;
			}
			// Left leaf case 1
			else if (tmp->left->key == key && tmp->left->left == NULL && tmp->left->right == NULL)
			{
				tmp->left = NULL;
				break;
			}
			// Case 2.1 With single subtree
			// Right single subtree
			else if (tmp->left->key == key)
			{
				if (tmp->left->left != NULL && tmp->left->right == NULL)
				{
					tmp->left = tmp->left->left;
				}
				else if (tmp->left->left == NULL && tmp->left->right != NULL)
				{
					tmp->left = tmp->left->right;
				}
				else
				{
					// Case 3 With both subtrees
					tmp = tmp->left;
					tmp->left->key = tmp->left->right->key;
					
				}
				break;
			}
			// 2.2 Left subtree
			else if (tmp->right->key == key)
			{
				if (tmp->right->left != NULL && tmp->right->right == NULL)
				{
					tmp->right = tmp->right->left;
				}
				else if (tmp->right->left == NULL && tmp->right->right != NULL)
				{
					tmp->right = tmp->right->right;
				}
				else
				{
					// Case 3 With both subtrees
				}
				break;
			}

			tmp->left = tmp->left->left;
			tmp->right = tmp->right->right;
		}
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
	return 0;
}

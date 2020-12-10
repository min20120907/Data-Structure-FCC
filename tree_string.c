#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _intTreeNode
{
	int value;
	struct _intTreeNode *left, *right;
} intTreeNode, *intTreeNodePtr;
void printInorder(intTreeNodePtr node)
{
	if (node == NULL)
		return;
	/* first recur on left child */
	printInorder(node->left);
	/* then print the data of node */
	printf("%d ", node->value);
	/* now recur on right child */
	printInorder(node->right);
}
intTreeNodePtr buildTree(char **a, int len)
{

		intTreeNodePtr root = (intTreeNodePtr)malloc(sizeof(intTreeNode));

		root->value = atoi(a[0]);
		for (int i = 0; i < len; i++)
		{
			a[i] = a[i + 1];
		}
		root->left = buildTree(a, len - 1);
		for (int j = 0; j < len; j++)
		{
			a[j] = a[j + 1];
		}
		root->right = buildTree(a, len - 1);
		for (int j = 0; j < len; j++)
		{
			a[j] = a[j + 1];
		}

		return root;
	
}

intTreeNodePtr buildTreeFromString(char *ss)
{
	char tmp[2] = {'\0', '\0'};
	if (!strcmp(ss, ""))
	{
		return NULL;
	}
	else
	{
		char **a = (char**) malloc(sizeof(char)*strlen(ss));

		int x, y = 0;
		char s[101];
		strcpy(s, ss);
		for (x = 0; x < strlen(ss); x++)
		{

			if (s[x] == ' ')
			{
				y++;
			}
			else
			{
				if (s[x] != '@')
				{
					tmp[0] = s[x];
					strcat(a[y],tmp);
					//printf("%c",s[x]);
				}
				else
				{
					//a[y] = "";
				}
			}
		}
		//printf("%s is first number\n", a[1]);
		//return buildTree(a,y);
		//return NULL;
	}
	return NULL;
}
int main()
{
	printInorder(buildTreeFromString("20 @ @"));
	printf("\n");
	printInorder(buildTreeFromString("20 10 @ @ @"));
	printf("\n");
	printInorder(buildTreeFromString("20 @ 30 @ @"));
	printf("\n");
	printInorder(buildTreeFromString("20 10 @ @ 30 @ @"));
	printf("\n");
	printInorder(buildTreeFromString("20 @ 10 @ 30 @ 60 @ @"));
	printf("\n");
	printInorder(buildTreeFromString("20 10 30 60 @ @ @ 70 @ 80 @ @ @"));
	printf("\n");
	//printInorder(buildTreeFromString(""));
	//printf("\n");
	return 0;
}

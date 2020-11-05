#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _TreeNode {
	char word[101];
	struct _TreeNode *left, *right;
}TreeNode, *TreeNodePtr;

TreeNodePtr buildTree (FILE *in) {
	char word[101];
	fscanf(in, "%s", word);
	if(strcmp(word, "@") == 0) return NULL;
	else {
		TreeNodePtr root = (TreeNodePtr) malloc(sizeof(TreeNode));
		strcpy(root->word, word);
		root -> left = buildTree(in);
		root->right = buildTree(in);
		return root;
	}
}

typedef void (*visit_func) (TreeNodePtr node);

void preOrder(TreeNodePtr root, visit_func v){
	if(root == NULL)return;
	/* visit code*/
	v(root);
	/* traversing */
	preOrder(root->left, v);
	preOrder(root->right, v);

}

void print_node(TreeNodePtr node) {
	 printf("%s ", node->word);	
}

void print_node_v2(TreeNodePtr node) {
	 printf("%s::", node->word);	
}

int build_tree(TreeNodePtr root, FILE *in) {
	TreeNodePtr left_root, right_root;
	/* read node value */
	fscanf(in, "%s", root->word);
	if(strcmp(root->word, "@") == 0){
		return 0;
	}
	/* build left */
	left_root = (TreeNodePtr) malloc(sizeof(TreeNode));
	if(build_tree(left_root, in)){
		root->left = left_root;
	} else {
		root-> left =NULL;
		free(left_root);
	}
	/* build right */
	right_root = (TreeNodePtr) malloc(sizeof(TreeNode));
	if(build_tree(right_root, in)){
		root->right = right_root;
	} else {
		root->right =NULL;
		free(right_root);
	}
	return 1;
}

/*int buildTree(FILE *in){
	TreeNodePtr = (TreeNodePtr) malloc (sizeof(TreeNode));
	if(build_tree(root, in)){
		return root;
	} else{
		free(root);
		return NULL;
	}
	return 1;
}*/

int main(int argc, char **argv) {
	FILE *in;
	TreeNodePtr root;
	
	in = fopen("tree.in", "r");
	root = buildTree(in);
	fclose(in);
	preOrder(root,print_node);
	printf("\n");

	preOrder(root,print_node_v2);
	printf("\n");
	return 0;
}

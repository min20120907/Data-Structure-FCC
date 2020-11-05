#ifndef _LinkList_h
#define _LinkList_h

typedef struct Node{
	double data;
	struct Node *next;
}node, *node_p;

node_p append_node();
node_p add_head_node();
int count_list();
node_p find_tail_node();
node_p add_tail_node();
void print_list();
void concat_nodes();
node_p find_first();
node_p getNode();
node_p insert_at(node_p head, int idx, node_p node3);

#endif

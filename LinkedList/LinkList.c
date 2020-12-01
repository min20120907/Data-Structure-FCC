#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//append node function
node_p append_node(double member)
{
	node_p tmp = (node_p)malloc(sizeof(node));
	tmp->data = member;
	tmp->next = NULL;
	return tmp;
}

//add head node
node_p add_head_node(node_p head, node_p node_ptr)
{
	node_p new_head;
	new_head = head;

	if (node_ptr != NULL)
	{
		node_ptr->next = head;
		new_head = node_ptr;
	}

	return new_head;
}

//get the length
int count_list(node_p head)
{
	node_p cur = head;
	//if nothing inside
	if (cur == NULL)
	{
		return 0;
	}
	else if (cur->next == NULL)
	{
		return 1;
	}
	else
	{
		while (cur != NULL && cur->next != NULL)
		{
			int counter = 1;
			counter++;
			cur = cur->next;
			return counter;
		}
	}
	return 1;
}

//find tail node
node_p find_tail_node(node_p head)
{
	node_p cur = head;

	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

//add Tail node
node_p add_tail_node(node_p head, node_p node_ptr)
{
	node_p tail_ptr;
	tail_ptr = find_tail_node(head);
	if (tail_ptr != NULL)
		tail_ptr->next = node_ptr;
	if (head == NULL)
		return node_ptr;
	else
		return head;
}

//print function
void print_list(node_p head)
{
	node_p cur = head;
	while (cur != NULL)
	{
		printf("%lf \n", cur->data);
		cur = cur->next;
	}
}

//concatenate the nodes
void concat_nodes(node_p a, node_p b)
{
	a->next = b;
	b->next = NULL;
}

//get node index by a specific value
node_p find_first(node_p head, double value)
{
	node_p cur;
	if (head == NULL)
	{
		return NULL;
	}
	cur = head;
	while (cur != NULL && cur->data != value)
	{
		cur = cur->next;
	}
	return cur;
}

//Get node by index
node_p getNode(node_p head, int idx)
{
	node_p cur;
	if (head == NULL || idx < 0)
		return NULL;
	cur = head;
	for (int i = 0; i < idx; i++)
	{
		if (cur->next == NULL)
			cur = cur->next;
		else
			return NULL;
	}
	return cur;
}

node_p removeNode(node_p head, double udata)
{
	node_p cur;
	cur = head;
	// if the list is empty, then return itself.
	if (cur->next == NULL)
		return cur;
	// or if the head is the found node, then return next
	else if (cur->data == udata)
		return cur->next;
	// if this is in the between, then the next is the next to the next.
	else if (cur->next->data == udata)
	{
		cur->next = cur->next->next;
	}
	else
	{
		// otherwise find it again
		removeNode(cur->next, udata);
	}
	return cur;
}

node_p removeNodeByIndex(node_p head, int idx)
{
	node_p cur = head;
	if (idx == 0)
	{
		cur = cur->next;
		return cur;
	}
	// if nothing next to the linkedlist, then return itself
	else if (cur->next == NULL)
		return cur;
	// if list is empty, return null
	else if (cur == NULL)
		return NULL;
	// if oversize return it self.
	else if (idx > count_list(head))
		return cur;
	// otherwise
	else
	{
		// create a temporary variable to indicate the node, which is scanned currently.
		node_p tmp = malloc(sizeof(node));
		tmp = head;
		for (int i = 0; i < idx; i++)
		{
			// iterate to the next node.
			tmp = tmp->next;
		}
		// find the target node "tmp".
		cur = removeNode(head, tmp->data);
		// deallocate the tmp memory address
		free(tmp);
		return cur;
	}
	return NULL;
}

//insert between nodes
//node_p insert_at(node_p, idx, node_p node3){
//	return ;
//}

//remove node

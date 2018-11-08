#include<stdio.h>
#include<malloc.h>
#include"tree.h"
#include"link.h"

tree *create_tree()
{
	tree *temp = (tree *)malloc(sizeof(tree));
	temp->child_amount = 0;
	temp->distance = 0;
	temp->data = 0;
	temp->l = NULL;
	return temp;
}

void add_tree(tree *out, tree *in)
{
	t_link *temp = (t_link *)malloc(sizeof(t_link));
	temp->next = NULL;
	temp->t = in;

	t_add((t_link **)&out->l, temp);
	out->child_amount++;
}

void search_in_tree(tree *in, tree **out, int value)
{
	if (*out != NULL)
	{
		return;
	}

	if (in->data == value)
	{
		*out = in;
	}
	else
	{
		int length = in->child_amount;
		t_link *head = in->l;
		for (int i = 0; i < length; i++)
		{
			tree *child = head->t;
			search_in_tree(child, out, value);
			head = head->next;
		}
	}
}
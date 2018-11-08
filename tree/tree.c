#include"tree.h"
#include<stdio.h>
#include<malloc.h>

void free_queue(queue **head)
{
	queue *temp;
	while (*head!=NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void q_add(queue **head, int data)
{
	if (*head == NULL)
	{
		*head = (queue *)malloc(sizeof(queue));
		(*head)->next = NULL;
		(*head)->data = data;
	}
	else
	{
		queue *temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = (queue *)malloc(sizeof(queue));
		temp = temp->next;
		temp->next = NULL;
		temp->data = data;
	}
}

void q_del(queue **head)
{
	queue *temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

void postorder_traversal(b_tree *in)
{
	if (in->lchild != NULL)
	{
		postorder_traversal(in->lchild);
	}

	if (in->rchild != NULL)
	{
		postorder_traversal(in->rchild);
	}

	printf("%c", in->data);
}

void preorder_traversal(b_tree *in)
{
	printf("%c", in->data);

	if (in->lchild != NULL)
	{
		postorder_traversal(in->lchild);
	}

	if (in->rchild != NULL)
	{
		postorder_traversal(in->rchild);
	}
}

void inorder_traversal(b_tree *in)
{
	if (in->lchild != NULL)
	{
		inorder_traversal(in->lchild);
	}

	printf("%c", in->data);

	if (in->rchild != NULL)
	{
		inorder_traversal(in->rchild);
	}
}

void sequence_traversal(b_tree *in, queue **q)
{
	if (*q != NULL)
	{
		q_del(q);
	}
	if (in->lchild != NULL)
	{
		q_add(q, &in->lchild);
	}
	if (in->rchild != NULL)
	{
		q_add(q, &in->rchild);
	}
	printf("%c", in->data);
	if (*q != NULL)
	{
		sequence_traversal((b_tree *)((*q)->data), q);
	}
}
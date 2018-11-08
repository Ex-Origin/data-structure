#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include"tree.h"
void sequence_assign(queue **q,int num)
{
	t_tree *temp;
	for (int i = 0; i < num; i++)
	{
		temp =*(t_tree **)((*q)->data) = (t_tree *)malloc(sizeof(t_tree));
		temp->lchild = NULL;
		temp->rchild = NULL;
		temp->ltag = 0;
		temp->rtag = 0;
		q_del(q);
	}
	free_queue(q);
}

void full(t_tree **head, queue **q, int level)
{
	if (level == 0)
	{
		*head = NULL;
		q_add(q, (int)head);
	}
	else
	{
		(*head) = (t_tree *)malloc(sizeof(t_tree));
		(*head)->ltag = 0;
		(*head)->rtag = 0;
		full(&(*head)->lchild, q, level-1);
		full(&(*head)->rchild, q, level-1);
	}
}

void sequence_set(t_tree *head, queue **q, t_element *str)
{
	if (head != NULL)
	{
		q_add(q, (int)head);
	}
	

	while (*q != NULL)
	{
		t_tree *temp = (t_tree *)(*q)->data;
		q_del(q);
		temp->data = *str++;
		if (temp->lchild != NULL)
		{
			q_add(q, (int)temp->lchild);
		}

		if (temp->rchild != NULL)
		{
			q_add(q, (int)temp->rchild);
		}
	}
}

void sequence_initial(t_tree **head, queue **q, t_element *str, int length)
{
	int level = (int)(log(length + 1) / log(2));
	full(head, q, level);

	int num = (int)(length - (pow(2, level)-1));
	sequence_assign(q,num); 
	
	sequence_set(*head, q, str);
}

void threaded(t_tree **head,t_tree **pre )
{
	if (*head != NULL)
	{
		if ((*head)->lchild != NULL)
		{
			threaded(&(*head)->lchild, pre);
		}
		else
		{
			(*head)->lchild = *pre;
			(*head)->ltag = 1;
		}

		if (*pre != NULL && (*pre)->rchild == NULL)
		{
			(*pre)->rchild = *head;
			(*pre)->rtag = 1;
		}
		*pre = *head;

		threaded(&(*head)->rchild, pre);
		
		
	}
}

void threaded_inorder_traversal(t_tree *in)
{
	while (in != NULL)
	{
		while (in->ltag == 0)
		{
			in = in->lchild;
		}
		printf("%c", in->data);
		while (in->rtag == 1)
		{
			in = in->rchild;
			printf("%c", in->data);
		}

		in = in->rchild;
	}
}

void t_tree_main()
{
	t_tree *head=NULL;
	queue *q = NULL;
	char str[] = "ABCDEFGHIJKLMN";
	int length = sizeof(str) - 1;
	sequence_initial(&head, &q, str, length);

	inorder_traversal((b_tree *)head);
	puts("");

	t_tree *pre = NULL;
	threaded(&head, &pre);

	threaded_inorder_traversal(head);
}
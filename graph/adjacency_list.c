#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include"adjacency_list.h"

list *create_list(int amount)
{
	list *p = (list *)malloc(sizeof(list)*amount);
	memset(p, 0, sizeof(list)*amount);
	return p;
}

void set_node(list *out, int *in, int in_length)
{
	node *pre = (node *)malloc(sizeof(node));
	if (in_length > 0)
	{
		pre->data = in[0];
		pre->next = NULL;
		out->out = pre;
		
		for (int i = 1; i < in_length; i++)
		{
			node *late = (node *)malloc(sizeof(node));
			late->data = in[i];
			late->next = NULL;
			pre->next = late;
			pre = late;
		}
	}
	
}

void del_node(list *out,int value)
{
	node *temp = NULL;
	temp = out->out;
	if (temp->data == value)
	{
		out->out = temp->next;
		free(temp);
		return;
	}

	node *pre = NULL;

	do
	{
		pre = temp;
		temp = temp->next;
		if (temp == NULL)
		{
			fprintf(stderr, "Error, there isn't that node\n");
			return;
		}
	} while (temp->data != value);

	pre = temp->next;
	free(temp);
}

int is_depend(list *in, int in_amount, int value)
{
	for (int i = 0; i < in_amount; i++)
	{
		if (in[i].node == 0x7FFFFFFF)
		{
			continue;
		}

		node *temp = in[i].out;
		while (temp != NULL)
		{
			if (temp->data == value)
			{
				return 1;
			}

			temp = temp->next;
		}
	}

	return 0;
}

void topological_sorting(list *in, int in_amount)
{
	list *news = (list *)malloc(sizeof(list)*in_amount);
	memcpy(news, in, sizeof(list)*in_amount);

	for (int i = 0; i < in_amount; i++)
	{
		int key = 1;
		for (int ii = 0; ii < in_amount; ii++)
		{
			if (news[ii].node == 0x7FFFFFFF)
			{
				continue;
			}

			int value = news[ii].node;
			if (!is_depend(news, in_amount, value))
			{
				printf("-> %d ", value);
				news[ii].node = 0x7FFFFFFF;
				key = 0;
				break;
			}
		}
		if (key)
		{
			fprintf(stderr, "Error: there is a loop in the list\n");
			break;
		}
	}

	free(news);
}
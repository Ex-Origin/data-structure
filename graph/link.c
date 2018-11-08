#include<stdio.h>
#include<malloc.h>
#include"link.h"
#include"tree.h"

void add(link **out, link *in)
{
	if (*out == NULL)
	{
		*out = in;
	}
	else
	{
		link *temp = *out;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = in;
	}
}

void t_add(t_link **out, t_link *in)
{
	if (*out == NULL)
	{
		*out = in;
	}
	else
	{
		t_link *temp = *out;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = in;
	}
}

void free_link(link **out)
{
	link *head = *out;
	while (head != NULL)
	{
		link *temp = head;
		head = head->next;
		free(temp);
	}
	*out = head;
}

int is_have(link *in, int seek)
{
	while (in != NULL)
	{
		if (in->data == seek)
		{
			return 1;
		}
		else
		{
			in = in->next;
		}
	}

	return 0;
}


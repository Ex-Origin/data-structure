#ifndef LINK
#define LINK
#include"tree.h"

typedef struct tree_link
{
	struct  tree *t;//for tree
	struct tree_link *next;
}t_link;

typedef struct link
{
	int data;
	struct link *next;
}link;

void t_add(t_link **out, t_link *in);

void add(link **out, link *in);

void free_link(link **out);

int is_have(link *in, int seek);

#endif // !LINK

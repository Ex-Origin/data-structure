#ifndef TREE
#define TREE
#include"link.h"

typedef struct  tree
{
	char data;
	int distance;
	int child_amount;
	struct tree_link *l;//for tree link
}tree;

tree *create_tree();

void search_in_tree(tree *in, tree **out, int value);

void add_tree(tree *out, tree *in);

#endif // !TREE

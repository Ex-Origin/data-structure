#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct adjacency_list
{
	int node;
	struct node *out;
}list;

list *create_list(int amount);

void set_node(list *out, int *in, int in_length);

void del_node(list *out, int value);

void topological_sorting(list *in, int in_amount);

#endif // !ADJACENCY_LIST

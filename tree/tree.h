
typedef struct queue
{
	unsigned int data;
	struct queue *next;
}queue;
void q_add(queue **head, int data);
void q_del(queue **head);
void free_queue(queue **head);

typedef char b_element;
typedef struct binary_tree
{
	b_element data;
	struct binary_tree *lchild;
	struct binary_tree *rchild;
}b_tree;
void postorder_traversal(b_tree *in);
void preorder_traversal(b_tree *in);
void inorder_traversal(b_tree *in);
void sequence_traversal(b_tree *in, queue **q);


typedef char t_element;
typedef struct threaded_binary_tree
{
	t_element data;
	struct threaded_binary_tree *lchild, *rchild;
	int ltag, rtag;
}t_tree;



#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"tree.h"

b_tree *create_tree()
{
	b_tree *temp = (b_tree *)malloc(sizeof(b_tree));
	memset(temp, 0, sizeof(b_tree));
	return temp;
}

void insert_tree(b_tree **out,int value)
{
	b_tree *in = create_tree();
	in->data = value;


}

b_tree *avl_tree_create(int *array,int length)
{
	b_tree *root = NULL;
	for (int i = 0; i < length; i++)
	{
		insert_tree(root, array[i]);
	}
	return root;
}

void avl_tree_main()
{

}

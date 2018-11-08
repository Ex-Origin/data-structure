#include<stdio.h>
#include<malloc.h>
#include"adjacent_matrix.h"
#include"tree.h"

//for adjacent matrix
void _depth_first_traversal(int matrix[SIZE][SIZE],char *table,int size,int start)
{
	printf("-> %c ", table[start]);
	for (int i=0; i < size; i++)
	{
		matrix[i][start] += 2;
	}

	for (int i=0; i < size; i++)
	{
		if (matrix[start][i] == 1)
		{
			_depth_first_traversal(matrix, table, size, i);
		}
	}
}

void depth_first_traversal(int matrix[SIZE][SIZE], char *table, int size)
{
	_depth_first_traversal(matrix, table, size, 0);

	for (int i = 0; i < size; i++)
	{
		for (int ii = 0; ii < size; ii++)
		{
			if (matrix[i][ii] == 2 || matrix[i][ii] == 3)
			{
				matrix[i][ii] -= 2;
			}
		}
	}
}

void breadth_first_traversal(int matrix[SIZE][SIZE],char *table)
{
	queue *head = NULL;
	head = (queue *)malloc(sizeof(queue));
	head->data = 0;
	head->next = NULL;

	int temp = head->data;
	for (int i = 0; i < SIZE; i++)
	{
		matrix[i][temp] += 2;
	}
	while (head != NULL)
	{
		temp = head->data;
		printf("-> %c ", table[temp]);
		q_del(&head);
		for (int i = 0; i < SIZE; i++)
		{
			if (matrix[temp][i] == 1)
			{
				for (int ii = 0; ii < SIZE; ii++)
				{
					matrix[ii][i] += 2;
				}
				queue *q = (queue *)malloc(sizeof(queue));
				q->data = i;
				q->next = NULL;
				q_add(&head, q);
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int ii = 0; ii < SIZE; ii++)
		{
			if (matrix[i][ii] == 2 || matrix[i][ii] == 3)
			{
				matrix[i][ii] -= 2;
			}
		}
	}
}

void q_add(queue **out,queue *in)
{
	if (*out == NULL)
	{
		*out = in;
	}
	else
	{
		queue *temp = *out;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = in;
	}
}

void q_del(queue **out)
{
	queue *temp = *out;
	if (temp == NULL)
	{
		fprintf(stderr, "There is no queue to delete\n");
	}
	else if (temp->next == NULL)
	{
		*out = NULL;
		free(temp);
	}
	else
	{
		*out = temp->next;
		free(temp);
	}
}

tree *create_prim_tree(int matrix[SIZE][SIZE],char *table,int start)
{
	tree *root = create_tree();
	link *v = (link *)malloc(sizeof(link));
	v->next = NULL;

	root->data = start;
	v->data = start;

	int v_length = 1;
	for (int i = 0; i < SIZE ; i++)
	{
		if (i == start)
		{
			continue;
		}

		edge e;
		e.length = 0x7FFFFFFF;
		e.des = -1;
		e.src = -1;
		link *t = v;
		for (int j = 0; j < v_length;j++ )
		{
			int ed = t->data;
			for (int ii = 0; ii < SIZE; ii++)
			{
				int temp = matrix[ed][ii];
				if (temp != 0 && e.length>temp)
				{
					if (!is_have(v, ii))
					{
						e.length = matrix[ed][ii];
						e.src = ed;
						e.des = ii;
					}
				}
			}
			t = t->next;
		}
		
		if (e.length != 0x7FFFFFFF)
		{
			t = (link *)malloc(sizeof(link));
			t->next = NULL;
			t->data = e.des;
			add(&v, t);
			v_length++;

			tree *destination = NULL;
			search_in_tree(root, &destination, e.src);
			tree *temp2 = create_tree();
			temp2->data = e.des;
			temp2->distance = e.length;

			add_tree(destination, temp2);
		}
		
	}

	return root;
}

void Dijkstra(int matrix[SIZE][SIZE],int path[SIZE][SIZE],int min_length[SIZE],int start_node)
{
	for (int i = 0; i < SIZE; i++)//initial path
	{
		min_length[i] = matrix[start_node][i];

		for (int ii = 0; ii < SIZE; ii++)
		{
			if (matrix[i][ii] < MAX&&matrix[i][ii]>0)
			{
				path[i][ii] = ii;
			}
			else
			{
				path[i][ii] = -1;
			}
		}
	}

	int finished[SIZE] = { 0 };//The statement was not searched

	finished[start_node] = 1;


	for (int i = 0; i < SIZE; i++)
	{
		int min = MAX;
		for (int ii = 0; ii < SIZE; ii++)
		{
			int node_min = -1;
			for (int j = 0; j < SIZE; j++)
			{
				if (finished[j]==0 && min_length[j] < min)
				{
					min = min_length[j];
					node_min = j;
				}
			}
			
			if (node_min != -1)
			{
				finished[node_min] = 1;//Join the spot where the search has been completed

				for (int j = 0; j < SIZE; j++)
				{
					if (finished[j] == 0 && (unsigned int)(min + matrix[node_min][j]) < (unsigned int)min_length[j])
					{
						min_length[j] = min + matrix[node_min][j];
						
						int node = start_node;//copy the path
						while (path[node][node_min] != -1)
						{
							path[node][j] = path[node][node_min];
							node = path[node][node_min];
						}
					}
				}
			}
			
		}
	}

}

void Floyd(int matrix[SIZE][SIZE], int path[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)//initial path
	{
		for (int ii = 0; ii < SIZE; ii++)
		{
			if (matrix[i][ii] < MAX&&matrix[i][ii]>0)
			{
				path[i][ii] = ii;
			}
			else
			{
				path[i][ii] = -1;
			}
		}
	}

	for (int i = 0; i < SIZE; i++)//optimize node i with i of the past
	{
		for (int ii = 0; ii < SIZE; ii++)//optimize ii->iii
		{
			for (int iii = 0; iii < SIZE; iii++)
			{
				if (ii != iii)
				{
					unsigned int temp_add = (unsigned int)
						(matrix[ii][i] + matrix[i][iii]);
					unsigned int temp = (unsigned int)matrix[ii][iii];
					if (temp_add < temp)
					{
						matrix[ii][iii] = (int)temp_add;
						path[ii][iii] = path[ii][i];
						//the path go from iii to ii
					}
				}
			}
		}
	}
}
#include<stdio.h>
#include<string.h>
#include"adjacent_matrix.h"
#include"adjacency_list.h"
#include"tree.h"

extern void crucial_path();
int main()
{
	/*
	int vect[SIZE][SIZE] = {
	{ 2147483647, 7, 2147483647, 7, 2147483647, 9, 2147483647, 2147483647, 4 },
	{ 7, 2147483647, 2147483647, 2147483647, 4, 6, 2147483647, 2147483647, 2147483647 },
	{ 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 6, 7, 2147483647, 2 },
	{ 7, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 9, 4, 2147483647 },
	{ 2147483647, 4, 2147483647, 2147483647, 2147483647, 1, 3, 1, 4 },
	{ 9, 6, 6, 2147483647, 1, 2147483647, 2147483647, 2147483647, 4 },
	{ 2147483647, 2147483647, 7, 9, 3, 2147483647, 2147483647, 7, 5 },
	{ 2147483647, 2147483647, 2147483647, 4, 1, 2147483647, 7, 2147483647, 6 },
	{ 4, 2147483647, 2, 2147483647, 4, 4, 5, 6, 2147483647 }
	};

	for (int i = 0; i < SIZE; i++)
	{
		for (int ii = 0; ii < SIZE; ii++)
		{
			if (vect[i][ii] != 0x7FFFFFFF)
			{
				printf("%d\t", vect[i][ii]);
			}
			else
			{
				printf("\\\t");
			}
		}
		puts("\n");
	}

	char table[SIZE] = { '1','2','3','4','5','6','7','8','9' };
	//depth_first_traversal(vect, table, SIZE);
	//breadth_first_traversal(vect, table);
	//tree *root=create_prim_tree(vect, table, 0);
	int path[SIZE][SIZE];

	//int min_length[SIZE];
	//Dijkstra(vect, path, min_length, 0);

	int result[SIZE][SIZE];
	memcpy(result, vect, sizeof(vect));
	Floyd(result, path);
	*/

	/*
	list table[5];
	memset(table, 0, sizeof(list) * 5);

	for (int i = 0; i < 5; i++)
	{
		table[i].node = i;
	}

	int array[10];
	array[0] = 1;
	array[1] = 2;
	set_node(table, array, 2);

	array[0] = 3;
	set_node(table + 1, array, 1);

	array[0] = 1;
	array[1] = 3;
	array[2] = 4;
	set_node(table + 2, array, 3);

	topological_sorting(table, 5);
	*/

	crucial_path();
}
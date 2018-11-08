#include<stdio.h>
#include<string.h>
#define SIZE 6
#define M -1

void crucial_path()
{
	int  matrix[SIZE][SIZE] = {
		{ M, 3, 4, M, M, M },
		{ M, M, M, 7, M, M },
		{ M, M, M, 2, 5, M },
		{ M, M, M, M, M, 6 },
		{ M, M, M, M, M, 1 },
		{ M, M, M, M, M, M }
	};

	int max_length[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		max_length[i] = matrix[0][i];
	}
	int finished_node[SIZE] = { 0 };
	int path[SIZE][SIZE];
	memset(path, -1, sizeof(path));
	for (int i = 0; i < SIZE; i++)
	{
		for (int ii = 0; ii < SIZE; ii++)
		{
			if (matrix[i][ii] > M)
			{
				path[i][ii] = ii;
			}
		}
	}

	finished_node[0] = 1;

	for (int i = 0; i < SIZE ; i++)
	{
		int max = -1;
		int max_node = -1;
		for (int ii = 0; ii < SIZE; ii++)
		{
			if (!finished_node[ii] && finished_node[ii] > max)
			{
				max = max_length[ii];
				max_node = ii;
			}
		}

		if (max_node != -1)
		{
			finished_node[max_node] = 1;

			for (int ii = 0; ii < SIZE; ii++)
			{
				if (!finished_node[ii] && max + matrix[max_node][ii] > max_length[ii])
				{
					max_length[ii] = max + matrix[max_node][ii];
					int point = 0;
					while (point != max_node)
					{
						path[point][ii] = path[point][max_node];
						point = path[point][max_node];
					}
				}
			}
		}
		


	}
	return;
}
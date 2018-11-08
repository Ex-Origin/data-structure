#ifndef ADJACENT_MATRIX
#define ADJACENT_MATRIX

#include"tree.h"
#define SIZE 9
#define MAX 0x7FFFFFFF
typedef struct queue
{
	int data;
	struct queue *next;
}queue;

void q_add(queue **out, queue *in);

void q_del(queue **out);

typedef struct edge
{
	int src;
	int des;
	int length;
}edge;

void depth_first_traversal(int matrix[SIZE][SIZE], char *table, int size);

void breadth_first_traversal(int matrix[SIZE][SIZE], char *table);

tree *create_prim_tree(int matrix[SIZE][SIZE], char *table, int start);

void Dijkstra(int matrix[SIZE][SIZE], int path[SIZE][SIZE], int min_length[SIZE], int start_node);

void Floyd(int matrix[SIZE][SIZE], int path[SIZE][SIZE]);

#endif // !ADJACENT_MATRIX



//import random
//
//matrix=[]
//
//print('{')
//
//
//x=9
//
//for i in range(x):
//	matrix+=[[]]
//	for ii in range(x):
//		matrix[i]+=[random.randint(0,1)]
//		
//for i in range(x):
//	for ii in range(i+1):
//		if(i==ii):
//			matrix[i][ii]=0
//		else:
//			matrix[i][ii]=matrix[ii][i]
//
//
//for i in range(x):
//	string='{'
//	for ii in range(x-1):
//		string+=str(matrix[i][ii])+','
//		
//	if (i==x-1):
//		string+=str(matrix[i][8])+'}'
//	else:
//		string+=str(matrix[i][8])+'},'
//	print(string)
//	
//print('};')
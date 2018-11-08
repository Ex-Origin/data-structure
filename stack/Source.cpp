#include<stdio.h>
#include"Stack.h"

struct S
{
	int *base;
	int *top;

	int StackSize;
};

int main()
{
	S *s = NULL;
	s = CreateStack(s, 1);
}


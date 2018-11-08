/*
	Content:此头文件主要用于栈的操作
	Author:Ex
	Created time:2018-01-27
	The last modifered time:2018-01-27
*/


#pragma once
#include<stdio.h>
#include<malloc.h>

#define SUCCEED true
#define FAILED false

//栈模板
//struct S
//{
//	int *base;
//	int *top;
//
//	int StackSize;
//};

//创建一个新的栈
//model为需要创建的栈的模板；_model为要创建的栈的储存类型的模板；size为所需空间个数，默认100个
//返回该栈的指针
template<class T,class K>
T *CreateStack(T *model,K _model,int size=100)
{
	T *newStack = new T;

	newStack->StackSize = size;
	newStack->base = (K *)malloc(sizeof(K)*size);
	newStack->top = NULL;

	return newStack;
}

//把数据推入栈中
//s为要推入的栈；d为要推入的数据
//返回是否执行成功
template<class Stack, class Type>
bool push(Stack *s, Type d)
{
	//空栈
	if ((s->StackSize) <= 0)
	{
		return FAILED;
	}
	else if ((s->top) == NULL)//栈内没有任何元素
	{
		s->top = s->base;
		*(s->top) = d;

		return SUCCEED;
	}

	int used = abs((s->base) - (s->top));

	//爆栈
	if ((used + 1) > (s->StackSize))
	{
		return FAILED;
	}
	else
	{
		*(++(s->top)) = d;
		return SUCCEED;
	}
}

//判断是否能推栈
//s为要判断的栈
//返回是否可以
template<class Stack>
bool CanPop(Stack *s)
{
	if ((s->top) == NULL)
	{
		return FAILED;
	}
	else
	{
		return SUCCEED;
	}

}

//推出栈中的元素
//s为要推出的栈；model为要推出的数据的模板
//返回推出的数据
template<class Stack,class Type>
Type pop(Stack *s,Type model)
{
	if ((s->top) == (s->base))
	{
		Type temp = *(s->top);

		s->top = NULL;

		return temp;
	}
	else
	{
		Type temp = *(s->top);
		(s->top)--;

		return temp;
	}
}

//打印出推入栈错误
inline void PushError()
{
	{
		puts("--------------------------------------------");
		puts("推入栈失败");
		puts("--------------------------------------------");
	}
}

//打印出推出栈错误
inline void PopError()
{
	{
		puts("--------------------------------------------");
		puts("推出栈失败");
		puts("--------------------------------------------");
	}
}


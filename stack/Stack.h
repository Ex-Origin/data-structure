/*
	Content:��ͷ�ļ���Ҫ����ջ�Ĳ���
	Author:Ex
	Created time:2018-01-27
	The last modifered time:2018-01-27
*/


#pragma once
#include<stdio.h>
#include<malloc.h>

#define SUCCEED true
#define FAILED false

//ջģ��
//struct S
//{
//	int *base;
//	int *top;
//
//	int StackSize;
//};

//����һ���µ�ջ
//modelΪ��Ҫ������ջ��ģ�壻_modelΪҪ������ջ�Ĵ������͵�ģ�壻sizeΪ����ռ������Ĭ��100��
//���ظ�ջ��ָ��
template<class T,class K>
T *CreateStack(T *model,K _model,int size=100)
{
	T *newStack = new T;

	newStack->StackSize = size;
	newStack->base = (K *)malloc(sizeof(K)*size);
	newStack->top = NULL;

	return newStack;
}

//����������ջ��
//sΪҪ�����ջ��dΪҪ���������
//�����Ƿ�ִ�гɹ�
template<class Stack, class Type>
bool push(Stack *s, Type d)
{
	//��ջ
	if ((s->StackSize) <= 0)
	{
		return FAILED;
	}
	else if ((s->top) == NULL)//ջ��û���κ�Ԫ��
	{
		s->top = s->base;
		*(s->top) = d;

		return SUCCEED;
	}

	int used = abs((s->base) - (s->top));

	//��ջ
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

//�ж��Ƿ�����ջ
//sΪҪ�жϵ�ջ
//�����Ƿ����
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

//�Ƴ�ջ�е�Ԫ��
//sΪҪ�Ƴ���ջ��modelΪҪ�Ƴ������ݵ�ģ��
//�����Ƴ�������
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

//��ӡ������ջ����
inline void PushError()
{
	{
		puts("--------------------------------------------");
		puts("����ջʧ��");
		puts("--------------------------------------------");
	}
}

//��ӡ���Ƴ�ջ����
inline void PopError()
{
	{
		puts("--------------------------------------------");
		puts("�Ƴ�ջʧ��");
		puts("--------------------------------------------");
	}
}


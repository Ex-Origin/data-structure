#pragma once
#include<stdio.h>
#include"LinkedList.h"
#define VERTICAL false
#define HORIZON true

struct Num
{
	int num;

	Num *prior;
	Num *next;
};


//依次打印出链表中的num的值，默认以垂直方式打印
//head为传入的头指针，n为需要的打印方式
void print(Num *head,bool pattren=VERTICAL)
{
	Num *temp = head;

	if (pattren)
	{
		if (IsHaveCircle(head))//判断是否为循环链表
		{
			while (temp->next != head)
			{
				printf("%d\t", temp->num);
				temp = temp->next;
			}

			puts("");
		}
		else
		{
			while (temp != NULL)
			{
				printf("%d\t", temp->num);
				temp = temp->next;
			}

			puts("");
		}
	}
	else
	{
		if (IsHaveCircle(head))//判断是否为循环链表
		{
			while (temp->next != head)
			{
				printf("%d\n", temp->num);
				temp = temp->next;
			}
		}
		else
		{
			while (temp != NULL)
			{
				printf("%d\n", temp->num);
				temp = temp->next;
			}
		}
	}

}


//创建链表，已初始化的
//n为创建个数
//返回头指针
Num *CreatNum(int n)
{
	Num *head = NULL;
	head = CreatLinkedList(head, n);

	Num *temp = head;

	for (int i = 0; i < n; i++)
	{
		temp->num = i + 1;
		temp = temp->next;
	}

	return head;
}
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


//���δ�ӡ�������е�num��ֵ��Ĭ���Դ�ֱ��ʽ��ӡ
//headΪ�����ͷָ�룬nΪ��Ҫ�Ĵ�ӡ��ʽ
void print(Num *head,bool pattren=VERTICAL)
{
	Num *temp = head;

	if (pattren)
	{
		if (IsHaveCircle(head))//�ж��Ƿ�Ϊѭ������
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
		if (IsHaveCircle(head))//�ж��Ƿ�Ϊѭ������
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


//���������ѳ�ʼ����
//nΪ��������
//����ͷָ��
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
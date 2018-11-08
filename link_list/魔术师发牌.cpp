#include<stdio.h>

#if 0



#include"Num.h"

//模拟魔术师发牌
//传入链表表头
//返回魔术师发牌后的牌的结果序列，以数组形式表现
int *MigicianDeal(Num *head);

int main_magician()
{
	Num *head = CreatNum(13);

	Num *result = NULL;
	result = CreatLinkedList(result, 13);//未初始化

	int *list = MigicianDeal(head);

	for (int i = 0; i < 13; i++)
	{
		Num *temp = result;
		//找到要插入的链表位置
		for (int ii = 0; ii < list[i]-1; ii++)
		{
			temp = temp->next;
		}

		temp->num = i + 1;
	}

	puts("牌的摆放序列为：");
	print(result);

	list = MigicianDeal(result);

	return 0;
}

int *MigicianDeal(Num *head)
{
	//如果传入的不是循环链表，那就把该表变成循环链表
	if (!IsHaveCircle(head))
	{
		head=ConnectList(head);
	}

	//声明数组，专门用来储存牌的结果顺序
	int *array = new int[13];

	for (int i = 0; i < 13; i++)
	{
		//模拟向下翻牌的过程
		for (int ii = 0; ii < i; ii++)
		{
			head = head->next;
		}

		array[i] = head->num;
		//删除该元素
		head=DeleteOfCircle(head);
	}

	return  array;
}

#endif // 0

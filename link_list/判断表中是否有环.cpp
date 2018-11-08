#include<stdio.h>

#if 0
#include"Num.h"


//利用快慢指针的算法，速度更快，效率更高
void JudgeHaveCircle2(Num *head)
{
	//p为慢指针，q为快指针
	Num *p, *q;
	p = q = head;

	while (q->next != NULL && q->next->next != NULL)
	{
		p = p->next;
		q = q->next->next;

		if (q == p)
		{
			puts("该链表含有环");
			return;
		}
	}

	puts("该链表没有环");
}

int main_Circle()
{
	Num *head = NULL;
	head = CreatLinkedList(head, 3);

	Num *later = NULL;
	later = CreatLinkedList(later, 4);

	//让链表中产生环
	later = ConnectList(later);
	head = ConnectList(head, later);

	JudgeHaveCircle(head);

	return 0;
}

int main_Circle2()
{
	Num *head = NULL;
	head = CreatLinkedList(head, 3);

	Num *later = NULL;
	later = CreatLinkedList(later, 4);

	//让链表中产生环
	later = ConnectList(later);
	head = ConnectList(head, later);

	JudgeHaveCircle2(head);

	return 0;
}

//判断表中是否有环
void JudgeHaveCircle(Num *head)
{
	Num *temp = head;

	while (temp->next!=NULL)
	{
		Num *_temp = head;

		//判断表尾是否指向了前面的元素
		while (true)
		{
			if (temp->next == _temp)
			{
				puts("该链表含有环");

				return;//结束程序
			}
			else if (_temp==temp)//当本次循环指到节点时，节点向后退一位
			{
				break;
			}
			else
			{
				_temp = _temp->next;
			}
		}
		
		temp = temp->next;
	}

	puts("该链表没有环");
}

#endif // 0
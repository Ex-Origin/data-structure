#include<stdio.h>

#if 0
#include"Num.h"


//���ÿ���ָ����㷨���ٶȸ��죬Ч�ʸ���
void JudgeHaveCircle2(Num *head)
{
	//pΪ��ָ�룬qΪ��ָ��
	Num *p, *q;
	p = q = head;

	while (q->next != NULL && q->next->next != NULL)
	{
		p = p->next;
		q = q->next->next;

		if (q == p)
		{
			puts("�������л�");
			return;
		}
	}

	puts("������û�л�");
}

int main_Circle()
{
	Num *head = NULL;
	head = CreatLinkedList(head, 3);

	Num *later = NULL;
	later = CreatLinkedList(later, 4);

	//�������в�����
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

	//�������в�����
	later = ConnectList(later);
	head = ConnectList(head, later);

	JudgeHaveCircle2(head);

	return 0;
}

//�жϱ����Ƿ��л�
void JudgeHaveCircle(Num *head)
{
	Num *temp = head;

	while (temp->next!=NULL)
	{
		Num *_temp = head;

		//�жϱ�β�Ƿ�ָ����ǰ���Ԫ��
		while (true)
		{
			if (temp->next == _temp)
			{
				puts("�������л�");

				return;//��������
			}
			else if (_temp==temp)//������ѭ��ָ���ڵ�ʱ���ڵ������һλ
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

	puts("������û�л�");
}

#endif // 0
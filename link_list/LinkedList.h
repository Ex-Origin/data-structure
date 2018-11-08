/**
Content:��ͷ�ļ���Ҫ�����������
Author:Ex
Created time:2018-01-27
The last modifered time:2018-01-27
*/

//ģ������ǲ�����.h�ļ���.cpp�ļ���ͨ������ֻ��������һ��.h�ļ���
//ע����Դ���벢û�б�д�Ŵ���
#pragma once
#include<malloc.h>
#define LENGTH sizeof(T)
#define NEXT next
#define PRIOR prior

//Ԫ��ģ��
//struct Num
//{
//	int num;
//
//	Num *prior;
//	Num *next;
//};

/**********************************ģ�庯������***********************************************/
//headΪȷ��ģ������ʹ�ã�nΪ��Ҫ�����ı�����,Ĭ�ϴ���1��
//headΪ�����ͷָ�룻nΪҪ����Ԫ�ص�����
//����ͷָ��
template<class T>
T *CreatLinkedList(T *head, int n = 1)
{
	head = (T *)malloc(LENGTH);
	T *temp = head;

	//����һ����
	if (n != 1)
	{
		for (int i = 1; i < n; i++)
		{
			temp->NEXT = (T *)malloc(LENGTH);
			temp = temp->NEXT;
		}
	}

	temp->NEXT = NULL;

	return head;
}

//ֱ�Ӵ���ͷָ�룬T�൱��������,��n������ӵ�λ�ã�Ĭ���ڱ�β��ӣ������µ�ͷָ���ַ
//headΪ�����ͷָ�룬nΪλ��-1��ʾ��β
//����ͷָ��
template<class T>
T *AddLinkedList(T *head, int n = -1)
{
	T *temp = head;

	if (n == -1)//�ڱ�β���
	{
		T *temp = SeekTail(head);

		////�ҵ���β��λ��
		//while (temp->NEXT != NULL)
		//{
		//	temp = temp->NEXT;
		//}

		//�����µı�
		T *_temp = (T *)malloc(LENGTH);//���ﲻ�ܺϲ������򱨴�Υ��д��Ȩ�ޣ�
		temp->NEXT = _temp;
		_temp->NEXT = NULL;

		return head;
	}
	else if (n == 0)//����ڱ�ͷ
	{
#if 1//����ķ����Ǵ���ģ����ص���ԭ����ͷָ��
		T *temp = (T *)malloc(LENGTH);

		temp->NEXT = head;
		return temp;
#else
		return ((T *)malloc(LENGTH)->NEXT = head);
#endif 
	}
	else
	{


		int i;//�ҵ����λ��
		for (i = 0; i < n - 1; i++)
		{
			temp = temp->NEXT;
		}

		T *_temp = temp->NEXT;

		temp->NEXT = (T *)malloc(LENGTH);
		temp = temp->NEXT;

		temp->NEXT = _temp;

		return head;
	}
}

//nΪɾ����λ�ã������ͷָ����˵,�����µ�ͷָ�룬Ĭ��ɾ����β
//headΪ��Ҫ����������ͷָ�룻nΪҪɾ����λ�ã�Ĭ��Ϊ-1
//���ش���õ�ͷָ��
template<class T>
T *DeleteLinkedList(T *head, int n = -1)
{
	//�ж��Ƿ�ֻ��һ��Ԫ��
	if (head->NEXT==NULL)
	{
		free(head);
		return NULL;
	}

	T *temp = head;

	if (n == -1)
	{
		//Ѱ�ҵ���β��ǰһ����
		while (temp->NEXT->NEXT != NULL)
		{
			temp = temp->NEXT;
		}
		//�ͷ���Դ
		free(temp->NEXT);

		temp->NEXT = NULL;

		return head;
	}
	else if (n == 1)//��������ֻ��һ����ʱ���ܻᷢ������
	{
		head = head->NEXT;
		free(temp);

		return head;
	}
	else//��ɾ�����Ǳ�βʱ���ܻᷢ������
	{
		int i;
		for (i = 0; i < n - 2; i++)
		{
			temp = temp->NEXT;
		}
		temp = temp->NEXT;
		head = temp->NEXT;

		free(temp);

		return head;
	}
}

//���ڿ���Ѱ�ұ�β��NULL�������ر�β��ָ��
//headΪ��ҪѰ�ҵ�����ͷָ��
//���ر�βָ��
template<class T>
inline T *SeekTail(T *head)
{
	while (head->NEXT != NULL)//here 
	{
		head = head->NEXT;
	}
	return head;
}

//ɾ��ѭ�������е�Ԫ�أ�������ѭ������Ĭ��ɾ����ͷ
//headΪ��Ҫ����������ͷָ�룻nΪҪɾ����λ��
//���ش���õ�ͷָ��
template<class T>
T *DeleteOfCircle(T *head, int n = 1)
{
	//�ж��Ƿ�ֻ��һ��Ԫ��
	if (head->NEXT == head)
	{
		free(head);
		return NULL;
	}

	T *temp;

	if (n == 1)//ɾ����ͷ
	{
		//Ѱ�ұ�β
		temp = head;
		while (temp->NEXT != head)
		{
			temp = temp->NEXT;
		}

		head = head->NEXT;
		//ɾ����ͷ
		free(temp->NEXT);

		temp->NEXT = head;

		return head;
	}
	else
	{
		return DeleteLinkedList(head, n);//ע��n��ҪΪ-1
	}
}

//�����������������������ֻ��һ�������򽫸ú�����β����
//formerΪҪ���ӵ������ǰ���֣�laterΪҪ���ӵ�����ĺ󲿷֣�Ĭ��ΪNULL����β������
//���ش���õ������ͷָ��
template<class T>
T *ConnectList(T *former, T *later = NULL)
{
	T *temp;

	//��β����
	if (later == NULL)
	{
		temp = SeekTail(former);
		temp->NEXT = former;
	}
	else
	{
		temp = SeekTail(former);
		temp->NEXT = later;
	}

	return former;
}

//���������е�Ԫ�أ�������ѭ������
//headΪ��Ҫ�����������ͷָ��
//����������Ԫ�ص�����
template<class T>
int CountList(T *head)
{
	T *temp = head;

	int i;
	for (i = 1; temp->NEXT != NULL && temp->NEXT != head; i++)
	{
		temp = temp->NEXT;
	}

	return i;
}

//����
//�ж��Ƿ�Ϊѭ������
//template<class T>
//bool IsCircleList(T *head)
//{
//	T *temp = head;
//
//	while (true)
//	{
//		if (temp->NEXT == NULL)
//		{
//			return false;
//		}
//		else if (temp->NEXT == head)
//		{
//			return true;
//		}
//		else
//		{
//			temp = temp->NEXT;
//		}
//	}
//}

//�ж��Ƿ��������л������ÿ���ָ����㷨���ٶȸ��죬Ч�ʸ��ߣ���Դ��С���㣬�ǳ��������㷨
//headΪ��Ҫ�жϵ������ͷָ��
//���ظ��������Ƿ��л�
template<class T>
bool IsHaveCircle(T *head)
{
	//pΪ��ָ�룬qΪ��ָ��
	T *p, *q;
	p = q = head;

	while (q->NEXT != NULL && q->NEXT->NEXT != NULL)
	{
		p = p->NEXT;
		q = q->NEXT->NEXT;

		if (q == p)
		{
			return true;
		}
	}

	return false;
}

//�ж��Ƿ��������л������ͨ��printf��ӡ����
//headΪ��Ҫ�жϵ������ͷָ��
template<class T>
void JudgeHaveCircle(T *head)
{
	if (IsHaveCircle(head))
	{
		puts("�ñ����ѭ���б�");
	}
	else
	{
		puts("�ñ���ѭ���б�");
	}
}
/*******************************************************************************************/

//ֱ�Ӵ���ͷָ�룬T�൱��������,��n������ӵ�λ�ã�Ĭ���ڱ�β��ӣ������µ�ͷָ���ַ
//headΪ�����ͷָ�룬nΪλ��-1��ʾ��β
//����ͷָ��
template<class T>
T *AddDualList(T *head, int position = -1)
{
	T *newList = (T *)malloc(LENGTH);

	if (position == -1)
	{
		T *tail = SeekTail(head);

		tail->NEXT = newList;
		newList->PRIOR = tail;

		newList->NEXT = NULL;
	}
	else if (position == 0)
	{
		newList->PRIOR = NULL;

		newList->NEXT = head;
		head->PRIOR = newList;

		head = newList;
	}
	else
	{
		for (int i = 0; i < position-1; i++)
		{
			head = head->NEXT;
		}

		T *former = head;
		T *later = head->NEXT;

		former->NEXT = newList;
		newList->NEXT = later;

		later->PRIOR = newList;
		newList->PRIOR = former;
	}

	return head;
}

//headΪȷ��˫�������ģ������ʹ�ã�nΪ��Ҫ�����ı�����,Ĭ�ϴ���1��
//headΪ�����ͷָ�룻nΪҪ����Ԫ�ص�����
//����ͷָ��
template<class T>
T *CreateDualList(T *head, int n = 1)
{
	if (n==1)
	{
		head = (T *)malloc(LENGTH);

		head->NEXT = NULL;
		head->PRIOR = NULL;
	}
	else
	{
		//����һ������
		head = CreateDualList(head);

		for (int i = 0; i < n-1; i++)
		{
			head = AddDualList(head);
		}
	}

	return head;
}

/**
Content:此头文件主要用于链表操作
Author:Ex
Created time:2018-01-27
The last modifered time:2018-01-27
*/

//模板好像是不能在.h文件与.cpp文件互通，所以只能声明在一个.h文件中
//注：本源代码并没有编写排错部分
#pragma once
#include<malloc.h>
#define LENGTH sizeof(T)
#define NEXT next
#define PRIOR prior

//元素模板
//struct Num
//{
//	int num;
//
//	Num *prior;
//	Num *next;
//};

/**********************************模板函数定义***********************************************/
//head为确定模板类型使用，n为需要创建的表数量,默认创建1个
//head为传入的头指针；n为要创建元素的数量
//返回头指针
template<class T>
T *CreatLinkedList(T *head, int n = 1)
{
	head = (T *)malloc(LENGTH);
	T *temp = head;

	//创建一个表
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

//直接传入头指针，T相当于数据名,由n决定添加的位置，默认在表尾添加，返回新的头指针地址
//head为传入的头指针，n为位置-1表示表尾
//返回头指针
template<class T>
T *AddLinkedList(T *head, int n = -1)
{
	T *temp = head;

	if (n == -1)//在表尾添加
	{
		T *temp = SeekTail(head);

		////找到表尾的位置
		//while (temp->NEXT != NULL)
		//{
		//	temp = temp->NEXT;
		//}

		//连上新的表
		T *_temp = (T *)malloc(LENGTH);//这里不能合并，否则报错（违反写入权限）
		temp->NEXT = _temp;
		_temp->NEXT = NULL;

		return head;
	}
	else if (n == 0)//添加在表头
	{
#if 1//后面的方法是错误的，返回的是原来的头指针
		T *temp = (T *)malloc(LENGTH);

		temp->NEXT = head;
		return temp;
#else
		return ((T *)malloc(LENGTH)->NEXT = head);
#endif 
	}
	else
	{


		int i;//找到表的位置
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

//n为删除的位置，相对于头指针来说,返回新的头指针，默认删除表尾
//head为需要操作的链表头指针；n为要删除的位置，默认为-1
//返回处理好的头指针
template<class T>
T *DeleteLinkedList(T *head, int n = -1)
{
	//判断是否只有一个元素
	if (head->NEXT==NULL)
	{
		free(head);
		return NULL;
	}

	T *temp = head;

	if (n == -1)
	{
		//寻找到表尾的前一个表
		while (temp->NEXT->NEXT != NULL)
		{
			temp = temp->NEXT;
		}
		//释放资源
		free(temp->NEXT);

		temp->NEXT = NULL;

		return head;
	}
	else if (n == 1)//当链表当中只有一个表时可能会发生错误
	{
		head = head->NEXT;
		free(temp);

		return head;
	}
	else//当删除的是表尾时可能会发生错误
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

//用于快速寻找表尾（NULL），返回表尾的指针
//head为需要寻找的链表头指针
//返回表尾指针
template<class T>
inline T *SeekTail(T *head)
{
	while (head->NEXT != NULL)//here 
	{
		head = head->NEXT;
	}
	return head;
}

//删除循环链表中的元素，仅用于循环链表，默认删除表头
//head为需要处理的链表的头指针；n为要删除的位置
//返回处理好的头指针
template<class T>
T *DeleteOfCircle(T *head, int n = 1)
{
	//判断是否只有一个元素
	if (head->NEXT == head)
	{
		free(head);
		return NULL;
	}

	T *temp;

	if (n == 1)//删除表头
	{
		//寻找表尾
		temp = head;
		while (temp->NEXT != head)
		{
			temp = temp->NEXT;
		}

		head = head->NEXT;
		//删除表头
		free(temp->NEXT);

		temp->NEXT = head;

		return head;
	}
	else
	{
		return DeleteLinkedList(head, n);//注意n不要为-1
	}
}

//将两端链表连接起来，如果只有一个参数则将该函数首尾相连
//former为要连接的链表的前部分；later为要连接的链表的后部分，默认为NULL（首尾相连）
//返回处理好的链表的头指针
template<class T>
T *ConnectList(T *former, T *later = NULL)
{
	T *temp;

	//首尾相连
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

//计算链表中的元素，可用于循环链表
//head为需要计数的链表的头指针
//返回链表内元素的数量
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

//作废
//判断是否为循环链表
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

//判断是否链表中有环，利用快慢指针的算法，速度更快，效率更高；来源于小甲鱼，非常厉害的算法
//head为需要判断的链表的头指针
//返回该链表中是否有环
template<class T>
bool IsHaveCircle(T *head)
{
	//p为慢指针，q为快指针
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

//判断是否链表中有环，结果通过printf打印出来
//head为需要判断的链表的头指针
template<class T>
void JudgeHaveCircle(T *head)
{
	if (IsHaveCircle(head))
	{
		puts("该表就是循环列表");
	}
	else
	{
		puts("该表不是循环列表");
	}
}
/*******************************************************************************************/

//直接传入头指针，T相当于数据名,由n决定添加的位置，默认在表尾添加，返回新的头指针地址
//head为传入的头指针，n为位置-1表示表尾
//返回头指针
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

//head为确定双向链表的模板类型使用，n为需要创建的表数量,默认创建1个
//head为传入的头指针；n为要创建元素的数量
//返回头指针
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
		//创建一个链表
		head = CreateDualList(head);

		for (int i = 0; i < n-1; i++)
		{
			head = AddDualList(head);
		}
	}

	return head;
}

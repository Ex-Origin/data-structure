//ָ��ֻ�������޸ĸ�ָ���ڴ��ֵ�ģ����ı�����һ�����������һ����һ����������
//�ͻ��ͷŵ������Ժ�������ָ�룬ֻ���޸�ָ��ָ���ڴ��ֵ�������޸ĸ�ָ���ָ��
//�����õ�������
#include<stdio.h>
#include<malloc.h>

#if 0



#include"Num.h"


int Joseph()
{
	Num *head=NULL;
	head = CreatLinkedList(head);

	head->num = 41;

	int i;
	for ( i = 40; i >0; i--)
	{
		head=AddLinkedList(head,0);
		head->num = i;
	}

	Num *temp = SeekTail(head);
	temp->next = head;

	for (int i = 0; i < 41; i++)
	{
		for (int n = 0; n < 2; n++)
		{
			head = head->next;
		}



		printf("��\t%2d\t����ɱ\n", head->num);

		head = DeleteOfCircle(head);


	}

	puts("\n");
/*
	printf("��\t%2d\t���Ҵ�\n", head->num);
	printf("��\t%2d\t���Ҵ�\n", head->next->num);*/

	return 0;
}


#endif // 0

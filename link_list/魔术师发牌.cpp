#include<stdio.h>

#if 0



#include"Num.h"

//ģ��ħ��ʦ����
//���������ͷ
//����ħ��ʦ���ƺ���ƵĽ�����У���������ʽ����
int *MigicianDeal(Num *head);

int main_magician()
{
	Num *head = CreatNum(13);

	Num *result = NULL;
	result = CreatLinkedList(result, 13);//δ��ʼ��

	int *list = MigicianDeal(head);

	for (int i = 0; i < 13; i++)
	{
		Num *temp = result;
		//�ҵ�Ҫ���������λ��
		for (int ii = 0; ii < list[i]-1; ii++)
		{
			temp = temp->next;
		}

		temp->num = i + 1;
	}

	puts("�Ƶİڷ�����Ϊ��");
	print(result);

	list = MigicianDeal(result);

	return 0;
}

int *MigicianDeal(Num *head)
{
	//�������Ĳ���ѭ�������ǾͰѸñ���ѭ������
	if (!IsHaveCircle(head))
	{
		head=ConnectList(head);
	}

	//�������飬ר�����������ƵĽ��˳��
	int *array = new int[13];

	for (int i = 0; i < 13; i++)
	{
		//ģ�����·��ƵĹ���
		for (int ii = 0; ii < i; ii++)
		{
			head = head->next;
		}

		array[i] = head->num;
		//ɾ����Ԫ��
		head=DeleteOfCircle(head);
	}

	return  array;
}

#endif // 0

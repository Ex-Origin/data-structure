//指针只是用来修改该指针内存的值的，它的本质与一般的数据类型一样，一旦函数结束
//就会释放掉，所以函数传入指针，只能修改指针指向内存的值，不能修改该指针的指向
//除非用的是引用
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



		printf("第\t%2d\t号自杀\n", head->num);

		head = DeleteOfCircle(head);


	}

	puts("\n");
/*
	printf("第\t%2d\t号幸存\n", head->num);
	printf("第\t%2d\t号幸存\n", head->next->num);*/

	return 0;
}


#endif // 0

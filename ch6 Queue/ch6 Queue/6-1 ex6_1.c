// 6-1 ���� �ڷᱸ���� �̿��� ���� ť �����ϱ�
#if 0
#include <stdio.h>
#include "6-1 queueS.h"	

int main(void)
{
	QueueType* Q1 = createQueue();	// ť ����
	element data;
	printf("\n ***** ���� ť ���� ***** \n");

	// ����
	printf("\n ���� A>>");
	enQueue(Q1, 'A');
	printQ(Q1);
	printf("\n ���� B>>");
	enQueue(Q1, 'B');
	printQ(Q1);
	printf("\n ���� C>>");
	enQueue(Q1, 'C');
	printQ(Q1);

	// �˻�
	data = peekQ(Q1);
	printf(" peek item : %c \n", data);

	// ����
	printf("\n ���� >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t���� ������ : %c", data);

	// ����
	printf("\n ���� D>>");
	enQueue(Q1, 'D');
	printQ(Q1);
	printf("\n ���� E>>");
	enQueue(Q1, 'E');
	printQ(Q1);

	printf("\n\n");

	QueueType* Q2 = createQueue();	// ť ����
	//element data;
	printf("\n ***** ���� ť ���� ***** \n");

	// ����
	printf("\n ���� 1>>");
	enQueue(Q2, '1');
	printQ(Q2);
	printf("\n ���� 2>>");
	enQueue(Q2, '2');
	printQ(Q2);
	printf("\n ���� 3>>");
	enQueue(Q2, '3');
	printQ(Q2);

	// �˻�
	data = peekQ(Q2);
	printf(" peek item : %c \n", data);

	// ����
	printf("\n ���� >>");
	data = deQueue(Q2);
	printQ(Q2);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>");
	data = deQueue(Q2);
	printQ(Q2);
	printf("\t���� ������ : %c", data);
	printf("\n ���� >>");
	data = deQueue(Q2);
	printQ(Q2);
	printf("\t���� ������ : %c", data);

	// ����
	printf("\n ���� 4>>");
	enQueue(Q2, '4');
	printQ(Q2);
	printf("\n ���� 5>>");
	enQueue(Q2, '5');
	printQ(Q2);
	getchar();
	return 0;
}

#endif	
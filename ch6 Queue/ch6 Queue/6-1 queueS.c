#if 0
#include <stdio.h>	
#include <stdlib.h>
#include "6-1 queueS.h"

// ���� ���� ť�� �����ϴ� ����
QueueType* createQueue(void)
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;	// front �ʱ�ȭ(-1�� �����Ͽ� ť�� ��������� ��Ÿ��)
	Q->rear = -1;	// rear �ʱ�ȭ(-1�� �����Ͽ� ť�� ��������� ��Ÿ��)
	return Q;
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isQueueEmpty(QueueType* Q)
{
	if (Q->front == Q->rear)		// front�� rear�� ������ ť�� ����ִ� ����
	{
		printf(" Queue is empty! \n\t ");
		return 1;					// ��� ������ 1�� ��ȯ
	}

	else
		return 0;					// ��� ���� ������ 0�� ��ȯ
}

// ���� �� ��ȭ �������� �˻��ϴ� ����
int isQueueFull(QueueType* Q)
{
	if (Q->rear == Q_SIZE - 1)	// rear�� ���� �ִ� ũ�⺸�� ũ�� �� ��ȭ ����
	{
		printf(" Queue is full! \n\t ");
		return 1;
	}
	else
		return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType* Q, element item)
{
	if (isQueueFull(Q))		// ��ȭ �����̸�, ���� ���� �ߴ�
		return;				// �Լ� ����
	else
	{
		Q->rear++;			// rear�� 1 �������� ���ο� ��ġ�� �̵�
		Q->queue[Q->rear] = item;	// ť�� rear ��ġ�� ���� ����
	}
}

// ���� ť�� front���� ���Ҹ� �����ϴ� ����
element deQueue(QueueType* Q)
{
	if (isQueueEmpty(Q))	// ���� �����̸�, ���� ���� �ߴ�
		return;				// �Լ� ����
	else
	{
		Q->front++;			// front�� 1 �������� ������ ������ ��ġ�� �̵�
		return Q->queue[Q->front];	
	}
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peekQ(QueueType* Q)
{
	if (isQueueEmpty(Q))		// ť�� ���� �����̸�
		return;					// �Լ� ����
	else
		return Q->queue[Q->front + 1];	// ���� �տ� �ִ� ���Ҹ� ��ȯ
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printQ(QueueType* Q)
{
	int i;
	printf(" Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)	// front �������� rear���� �ݺ�
		printf("%3c", Q->queue[i]);				// �� ���Ҹ� ���
	printf(" ]");
}
#endif
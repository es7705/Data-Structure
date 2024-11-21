#if 0
#include <stdio.h>
#include <stdlib.h>
#include "6-2 cQueueS.h"

// ���� ť�� �����ϴ� ����
QueueType* createQueue(void)
{
	QueueType* cQ;		// ť Ÿ���� ������ cQ�� ����
	cQ = (QueueType*)malloc(sizeof(QueueType));	// ť�� ���� �޸� �Ҵ�
	cQ->front = 0;	// front�� 0���� �ʱ�ȭ (ť�� �� ��ġ)
	cQ->rear = 0;	// rear�� 0���� �ʱ�ȭ (ť�� �� ��ġ)
	return cQ;		// ������ ť ������ ��ȯ
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isCQueuEmpty(QueueType* cQ)
{
	if (cQ->front == cQ->rear)		// front�� reqr�� ������ ť�� �������
	{
		printf("Circular Queue is empty! ");
		return 1;
	}
	else 
		return 0;
}

// ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isCQueueFull(QueueType* cQ)
{
	// rear�� ���� ��ġ�� front�� ������ ť�� ��ȭ ����
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front)
	{
		printf("  Circular Queue is full! ");
		return 1;
	}
	else
		return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enCQueue(QueueType* cQ, element item)
{
	if (isCQueueFull(cQ))	// ť�� ��ȭ �����̸�, ���� ���� �ߴ�
		return;				// �Լ� ����
	else
	{
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;	// rear�� 1 ������Ű�� ���� ť�� �°� ����
		cQ->queue[cQ->rear] = item;				// ť�� rear ��ġ�� ���� ����
	}
}

// ���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deCQueue(QueueType* cQ)
{
	if (isCQueuEmpty(cQ))		// ť�� ���� �����̸�, ���� ���� �ߴ�
		return;					// �Լ� ����
	else
	{
		cQ->front = (cQ->front + 1) % cQ_SIZE;	// front�� 1 ������Ű�� ���� ť�� �°� ����
		return cQ->queue[cQ->front];			// ������ ���Ҹ� ��ȯ
	}
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peekCQ(QueueType* cQ)
{			
	if (isCQueuEmpty(cQ))		// ť�� ���� �����̸�, ���� ���� �ߴ�
		return;					// �Լ� ����
	else
		return cQ->queue[(cQ->front + 1) % cQ_SIZE];	// fornt ���� ��ġ�� ���Ҹ� ��ȯ
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printCQ(QueueType* cQ)
{
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;	// ����� ù ��° ������ �ε��� ���
	last = (cQ->rear + 1) % cQ_SIZE;	// ����� ������ ������ �ε��� ���
	printf(" Circular Queue : [");
	i = first;							// ù ��° ���Һ��� ����
	while (i != last)					// first�� last�� ���� ���� ���� �ݺ�
	{
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;			// ���� ������ �ε����� �̵�
	}
	printf(" ] ");
}


#endif
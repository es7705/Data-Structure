#if 0
#include <stdio.h>
#include <stdlib.h>	
#include "6-3 LinkedQueue.h"

// ���� ���� ť�� �����ϴ� ����
LQueueType* createLinkedQueue(void)
{
	LQueueType* LQ;		// ���� ť ������ ����
	LQ = (LQueueType*)malloc(sizeof(LQueueType));	// ���� ť�� ���� �޸� �Ҵ�
	LQ->front = NULL;	// ť�� �� �� ��带 ����Ű�� front�� NULL�� �ʱ�ȭ (�������)
	LQ->rear = NULL;	// ť�� �� �� ��带 ����Ű�� rear�� NULL�� �ʱ�ȭ (�������)
	return LQ;			// ������ ť�� ��ȯ
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isLQEmpty(LQueueType* LQ)
{	
	if (LQ->front == NULL)	// ť�� front�� NULL�̸� ���� ť
	{
		printf(" Linked Queue is empty! ");
		return 1;			// ť�� ��������� 1�� ��ȯ
	}
	else
		return 0;			// ť�� ������� ������ 0�� ��ȯ
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enLQueue(LQueueType* LQ, element item)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));	// �� ��� �޸� �Ҵ�
	newNode->data = item;	// �� ������ �����Ϳ� ������ ���� ����
	newNode->link = NULL;	// �� ����� ��ũ�� NULL�� �ʱ�ȭ (�� ������ ��带 �ǹ�)

	if (LQ->front == NULL)	// ���� ���� ť�� ���� ������ ���, �� ��尡 ù ����� ���
	{		
		LQ->front = newNode;// front�� �� ��带 ����Ŵ				
		LQ->rear = newNode; // rear�� �� ��带 ����Ŵ
	}

	else					// ���� ���� ť�� ���� ���°� �ƴ� ���
	{
		LQ->rear->link = newNode;	// ���� rear�� ����Ű�� ����� ��ũ�� �� ����� �ּҸ� ����	
		LQ->rear = newNode;			// ������ ��带 ����Ű�� rear�� �� ���� ������Ʈ
	}
}

// ���� ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deLQueue(LQueueType* LQ)
{
	QNode* old = LQ->front;	// ������ ��带 �� �� ���� ����
	element item;			// ������ ����� ���Ҹ� ������ ����

	if(isLQEmpty(LQ))		// ���� ���� ť�� ���� ������ ���
		return;				// �Լ� ����
	else
	{
		item = old->data;	// ������ ����� �����͸� item�� ����
		LQ->front = LQ->front->link;	// �� �� ��带 ���� ���� ������Ʈ
		if (LQ->front == NULL)			// ���� ���� ��尡 ���ٸ�
			LQ->rear = NULL;			// rear�� NULL�� ���� (ť�� ��������� �ǹ�)
		free(old);			// old ��� �޸� ����
		return item;		// ������ ����� ���Ҹ� ��ȯ
	}
}

// ���� ť���� ���Ҹ� �˻��ϴ� ����
element peekLQ(LQueueType* LQ)
{
	element item;				// �˻��� ����� ���Ҹ� ������ ����
	if (isLQEmpty(LQ))			// ���� ���� ť�� ���� ������ ���
		return;					// �Լ� ����
	else
	{
		item = LQ->front->data;	// �� �� ����� �����͸� item�� ����
		return item;			// �˻��� ����� �����͸� ��ȯ
	}
}

// ���� ť�� ���Ҹ� ����ϴ� ����
void printLQ(LQueueType* LQ)	
{
	QNode* temp = LQ->front;	// front���� �����ϴ� �ӽ� ������
	printf(" Linked Queue : [");
	while (temp != NULL)		// ť�� ��� ���Ҹ� ���
	{
		printf("%3c", temp->data);
		temp = temp->link;		// ���� ���� �̵�
	}
	printf(" ] ");
}
#endif
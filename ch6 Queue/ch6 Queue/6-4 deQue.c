#if 0
#include <stdio.h>
#include <stdlib.h>
#include "6-4 deQue.h"

// ���� ��ũ�� �����ϴ� ����
DQueType* createDQue(void)
{
	DQueType* DQ;	// ��Ʈ ������ ����
	DQ = (DQueType*)malloc(sizeof(DQueType));	
	DQ->front = NULL;	// front ������ �ʱ�ȭ (��ũ�� ����)
	DQ->rear = NULL;	// rear ������ �ʱ�ȭ (��ũ�� ����)
	return DQ;			// ������ ��ũ ������ ��ȯ
}

// ��ũ�� ���� �������� �˻��ϴ� ����
int isDeQEmpty(DQueType* DQ)
{
	if (DQ->front == NULL)	// front�� NULL�̸� ��ũ�� �������
		return 1;			// ��������� 1�� ��ȯ
	else
		return 0;			// ������� ������ 0�� ��ȯ
}

// ��ũ�� front ������ ���Ҹ� �����ϴ� ����
void insertFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));	// ���ο� ��带 ���� �޸� �Ҵ�
	newNode->data = item;		// ����� ������ �ʵ忡 item ����
	if (isDeQEmpty(DQ))			// ��ũ�� ����ִ� ���
	{
		DQ->front = newNode;	// front�� rear ��� newNode�� ����Ŵ
		DQ->rear = newNode;
		newNode->llink = NULL;	// ���� ���� �ϳ��� ����̹Ƿ� ����, ������ ��ũ �ʵ� ��� NULL
		newNode->rlink = NULL;
	}
	else
	{
		DQ->front->llink = newNode;	// ���� front�� ���� ��ũ�� �� ���� ����
		newNode->rlink = DQ->front;	// �� ����� ������ ��ũ�� ���� front�� ����
		newNode->llink = NULL;		// �� ����� ���ʿ��� ��尡 �����Ƿ� NULL�� ����
		DQ->front = newNode;		// front�� �� �뵵�� ����Ŵ
	}
}

// ��ũ�� rear �ڷ� ���Ҹ� �����ϴ� ����
void insertRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));	// �� ��带 ���� �޸� �Ҵ�
	newNode->data = item;		// ����� ������ �ʵ忡 item ����
	if (isDeQEmpty(DQ))			// ��ũ�� ���� ������ ���
	{
		DQ->front = newNode;	// front�� rear ��� newNode�� ����
		DQ->rear = newNode;
		newNode->llink = NULL;	// �� ����� ����, �����ʿ��� ��尡 �����Ƿ� NULL�� ����
		newNode->rlink = NULL;
	}
	else
	{
		DQ->rear->rlink = newNode;	// ���� rear�� ������ ��ũ�� �� ���� ����
		newNode->llink = DQ->rear;	// �� ����� ���� ��ũ�� ���� rear�� ����
		newNode->rlink = NULL;		// �� ����� �����ʿ��� ��尡 �����Ƿ� NULL�� ����
		DQ->rear = newNode;			// rear�� �� ��带 ����Ŵ
	}
}

// ��ũ�� front ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteFront(DQueType* DQ)
{
	DQNode* old = DQ->front;	// ������ ��带 old�� ����
	element item;				// ��ȯ�� �����͸� ������ ����	
	if (isDeQEmpty(DQ))			// ��ũ�� ����ִ� ���
	{
		printf("\n Linked deQue is empty! \n");		
		return;
	}
	else
	{
		item = old->data;		// ������ ����� �����͸� item�� ����
			
		if (DQ->front->rlink == NULL)	// ��ũ�� ��尡 �ϳ��� �ִ� ���
		{
			DQ->front = NULL;			// ��带 �����ϰ� ���� �� ��ũ�� �ǹǷ�
			DQ->rear = NULL;			// front�� rear�� ��� NULL�� ����
		}
		else					// ���� ���� ��尡 �ִ� ���
		{
			DQ->front = DQ->front->rlink;	// front�� ���� ���� ������Ʈ
			DQ->front->llink = NULL;		// ���� ������ ��尡 �ǹǷ� ���� ��ũ�� NULL�� ����
		}
		free(old);		// ������ ��� �޸� ����
		return item;	// ������ ����� ������ ��ȯ
	}
}

// ��ũ�� rear ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteRear(DQueType* DQ)
{
	DQNode* old = DQ->rear;	// ������ ��带 old�� ����
	element item;			// ��ȯ�� �����͸� ������ ����
	if (isDeQEmpty(DQ))		// ��ũ�� ����ִ� ���
	{
		printf("\n Linked deQue is empty! \n");
		return;
	}
	else
	{
		item = old->data;		// ������ ����� �����͸� item�� ����
		
		if (DQ->rear->llink == NULL)	// ��ũ�� ��尡 �ϳ��� �ִ� ���
		{
			DQ->front = NULL;			// ��ũ�� ����ֹǷ�
			DQ->rear = NULL;			// front�� rear�� ����ų ��尡 ����
		}
		else					// ���� ������ ��尡 �ִ� ���
		{
			DQ->rear = DQ->rear->llink;	// rear�� ���� ���� ������Ʈ
			DQ->rear->rlink = NULL;		// rear�� ����Ű�� ���� ������ ����̹Ƿ� ������ ��ũ�� NULL�� ����
		}
		free(old);				// ������ ��� �޸� ����
		return item;			// ������ ����� ������ ��ȯ
	}
}

// ��ũ�� front ����� ������ �ʵ带 ��ȯ�ϴ� ����
element peekFront(DQueType* DQ)
{
	element item;				// ��ȯ�� �����͸� ������ ����
	if (isDeQEmpty(DQ))			// ��ũ�� ����ִ� ���
	{
		printf("\n Linked deQue is empty! \n");
		return;
	}
	else
	{
		item = DQ->front->data;		// front ����� �����͸� item�� ����
		return item;				// item ��ȯ
	}
}

// ��ũ�� rear ����� ������ �ʵ带 ��ȯ�ϴ� ����
element peekRear(DQueType* DQ)
{
	element item;		// ��ȯ�� �����͸� ������ ����
	if (isDeQEmpty(DQ))		// ��ũ�� ����ִ� ���
	{
		printf("\n Linked deQue is empty! \n");
		return;
	}
	else
	{
		item = DQ->rear->data;	// rear ����� �����͸� item�� ����
		return item;			// item ��ȯ
	}
}

// ��ũ�� front ������ rear ������ ����ϴ� ����
void printDQ(DQueType* DQ)
{
	DQNode* temp = DQ->front;	// �ӽ� �����Ϳ� front�� ����
	printf("DeQue : [");		// ��ũ ��� ����
	while (temp)				// ��ũ�� ��� ��带 ��ȸ�Ͽ� ������ ���
	{
		printf("%3c", temp->data);	// ���� ����� ������ ���
		temp = temp->rlink;			// ���� ���� �̵�
	}
	printf(" ] ");
}
#endif
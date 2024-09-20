#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include "4-3CircularlinkedList.h"	

// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void)
{
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	//CL->head = NULL;
	return CL;
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* CL)
{
	listNode* p;
	printf(" CL = (");
	p = CL->head;

	if (p == NULL)			// �� ����Ʈ�� ���
	{
		printf(") \n");
		return;
	}

	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

// ù ��° ��� ���� ����
void insertFisrtNode(linkedList_h* CL, char* x)
{
	listNode* newNode, * temp;	// temp : �ӽ� ��ȸ ������
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL)		// ���� ���� ����Ʈ�� ������ ���
	{
		CL->head = newNode;		// �� ��带 ����Ʈ�� ���� ���� ����
		newNode->link = newNode;// �� �뵵�� ��ũ�� �ڱ� �ڽ��� ����		
	}
	else						// ���� ���� ����Ʈ�� ������ �ƴ� ���
	{	
		temp = CL->head;		// �ӽ� ��ȸ �����Ϳ� head�� ����
		while (temp->link != CL->head)
		{
			temp = temp->link;	// ��ȸ �����͸� ��ũ�� ���� ������ ������ �̵�
		}
		newNode->link = temp->link;	// ������ ����� ��ũ ���� �� ����� ��ũ �ʵ忡 ����, �� ���� ù ��° ���� ����
		temp->link = newNode;		// ������ ��带 ù ��° ����� �� ���� ���� ����
		CL->head = newNode;			// �� ����� �ּҸ� ����Ʈ ���� ������ CL�� �����Ͽ� �� ��带 ����Ʈ�� ù ��° ��尡 �ǵ��� ����
	}
}

// pre �ڿ� ��带 �����ϴ� ����
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL)		// ���� ���� ����Ʈ�� ������ ���
	{
		CL->head = newNode;		// ����Ʈ�� ������ �� ��带 ����
		newNode->link = newNode;// �� ����� ��ũ�� �ڱ� �ڽ����� ����
	}
	else
	{
		newNode->link = pre->link;	// ���� ����� ���� ��� �ּҸ� �� ����� ��ũ �ʵ忡 �����Ͽ� ����
		pre->link = newNode;		// �� ����� �ּҸ� ���� ����� ��ũ �ʵ忡 �����Ͽ� ���� ����
	}
}

// ���� ���� ����Ʈ�� pre �ڿ� �ִ� ��� old�� �����ϴ� ����
void deleteNode(linkedList_h* CL, listNode* old)
{
	listNode* pre;					// ������ ������ ������ ��带 ��Ÿ���� ������
	if (CL->head == NULL) return;	// ���� ����Ʈ�� ��� ���� ���� �ߴ�
	if (CL->head->link == CL->head)	// ����Ʈ�� ��尡 �� ���� �ִ� ���
	{
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (old == NULL) return;	// ������ ��尡 ���� ��� ���� ���� �ߴ�
	else
	{
		pre = CL->head;				// ������ pre�� ����Ʈ�� ���� ��忡 ����
		while (pre->link != old)
		{
			pre = pre->link;		// ���� ��带 ������ pre�� �̿��� ã��
		}
		pre->link = old->link;		// ������ ����� ���� ��� �ּҸ� ���� ��� ��ũ �ʵ忡 ����
		if (old == CL->head)		// ������ ��尡 ù ��° ������� Ȯ��
		{
			CL->head = old->link;	// �� ��° ��尡 ù ��° ��尡 �ǵ��� ����
		}
		free(old);					// ���� ����� �޸𸮸� ����
	}
}

// ���� ���� ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* CL, char* x)
{
	listNode* temp;				// x�� ã�� ���� �ӽ� ��ȸ ������
	temp = CL->head;
	if (temp == NULL) return NULL;	// ���� ����Ʈ�� ���
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;	// ���� ���� �̵�
	} while (temp != CL->head);	
	return NULL;
}
#endif
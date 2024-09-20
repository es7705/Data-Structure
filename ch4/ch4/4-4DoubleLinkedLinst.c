#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>	
#include "4-4DoubleLinkedLinst.h"	

// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void)
{
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// ���� ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* DL)
{
	listNode* p;						// ���� ��带 ī��Ű�� ������
	printf("DL = (");

	p = DL->head;						// ���� ��带 ù ��° ���� �ʱ�ȭ
	while (p != NULL)					// ���� ��尡 NULL�� �ƴ� ������ �ݺ�, ������ ������ �ݺ�
	{
		printf("%s", p->data);			// ���� ����� ������ ���
		p = p->rlink;					// ���� ���� �̵�
		if (p != NULL)	printf(", ");	// ���� ��尡 NULL�� �ƴ� ��� ������ ���
	}
	printf(") \n");
}

// pre �ڿ� ��带 �����ϴ� ����
void insertNode(linkedList_h* DL, listNode* pre, char* x)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL)		// ���� ����Ʈ�� ���
	{
		newNode->rlink = NULL;	// ����, ������ ��ũ �ʵ� NULL
		newNode->llink = NULL;
		DL->head = newNode;		// ����Ʈ�� ���� ��带 �� ���� ����
	}
	else // ����Ʈ�� ������� ���� ���
	{
		newNode->rlink = pre->rlink; // ���ο� ����� ������ ��ũ�� �������� ������ ��ũ�� ����
		pre->rlink = newNode;		 // pre�� ������ ��ũ�� ���ο� ���� ����
		newNode->llink = pre;		 // ���ο� ����� ���� ��ũ�� ������ �ּҷ� ����

		if (newNode->rlink != NULL)  // �� ����� �����ʿ� ��尡 ������
		{
			newNode->rlink->llink = newNode; // ������ ����� ���� ��ũ�� ���ο� ���� ����
		}
	}
}

// ���� ���� ����Ʈ���� old ��带 �����ϴ� ����
void deleteNode(linkedList_h* DL, listNode* old)
{
	if (DL->head == NULL)	return;		// ���� ����Ʈ�� ��� ���� ���� �ߴ�
	else if (old == NULL) return;		// ������ ��尡 ���� ��� ���� ���� �ߴ�
	else
	{
		old->llink->rlink = old->rlink;	
		old->rlink->llink = old->llink;
		free(old);						// ���� ����� �޸� ����
	}
}

// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* DL, char* x)
{
	listNode* temp;										// �ӽ� ��ȸ ��� ������
	temp = DL->head;									// ù ��° ������ ��ȸ
	while (temp != NULL)								// ���� ����Ʈ�� �ƴϸ�
	{
		if (strcmp(temp->data, x) == 0) return temp;	// ã��
		else temp = temp->rlink;						// �� ã��
	}
	return temp;
}
#endif
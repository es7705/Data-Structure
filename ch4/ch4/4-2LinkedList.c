#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include "4-2LinkedList.h"

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void)
{
	linkedList_h* L;	// ���� ����Ʈ�� head �����͸� �����ϴ� ����ü�� ����Ű�� ������
	L = (linkedList_h*)malloc(sizeof(linkedList_h));	// linkedList_h ����ü ũ�⸸ŭ �޸𸮸� �Ҵ��ϰ� ������ L�� ����
	if (L == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	L->head = NULL;										// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;											// ������ ���� ����Ʈ�� ������ ��ȯ
}

void freeLinkedList_h(linkedList_h* L)
{
	listNode* p;										// ���� ��带 ����ų ������ p
	while (L->head != NULL)								// ���� ����Ʈ�� ������� �ʴ� ���� �ݺ�
	{
		p = L->head;									// ù ��° ����� �ּҸ� p�� ����
		L->head = L->head->link;						// head�� ���� ����� �ּҷ� ������Ʈ
		free(p);										// ���� ����� ���� �޸� ����
		p = NULL;										// p�� NULL�� �ʱ�ȭ (������ �޸� ������ ����)
	}
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L)
{
	listNode* p;										// ���� ��带 ����ų ������ p
	printf("L = (");
	p = L->head;										// ù ��° ����� �ּҸ� p�� ����
	while (p != NULL)									// ��尡 �ִ� ���� �ݺ�
	{
		printf("%s", p->data);							// ���� ����� ������ ���
		p = p->link;									// p�� ���� ��带 ����Ŵ
		if (p != NULL)									// ������ ��� ������ ', ' ���
			printf(", ");
	}
	printf(")\n");										// ����Ʈ ��� �� �ٹٲ�
}

// ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h* L, char* x)
{
	listNode* newNode;									// �� ��带 ����ų ������
	newNode = (listNode*)malloc(sizeof(listNode));		// ������ �� ��� �Ҵ�
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	strcpy(newNode->data, x);							// �� ����� ������ �ʵ忡 x ����
	newNode->link = L->head;							// ���� ù ��° ����� �ּҸ� �� ����� link �ʵ忡 ����
	L->head = newNode;									// �� ��尡 ���� ����Ʈ�� ù ��° ��尡 ��
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x)
{
	listNode* newNode;									// �� ��带 ����ų ������
	newNode = (listNode*)malloc(sizeof(listNode));		// ������ �� ��� �Ҵ�
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	strcpy(newNode->data, x);							// �� ����� ������ �ʵ忡 x ����
	if (L->head == NULL)								// ���� ����Ʈ�� ���
	{
		newNode->link = NULL;							// �� ����� link�� NULL�� ���� (ù ��° ������� ������ ���)
		L->head = newNode;								// �� ���� ù ��° ��尡 ��
	}
	else if (pre == NULL)								// pre�� NULL�� ��� (����Ʈ�� �� �տ� ����)		
	{	// pre�� NULL�̶�� ���� ������ ��ġ�� ���� ����Ʈ�� ù ��° ��� ���̶�� ���� �ǹ�. ��, ����Ʈ�� �� �տ� �� ��带 �߰��Ϸ��� ��Ȳ
		newNode->link = L->head;						// ������� link �ʵ忡 ���� ����Ʈ�� ù ��° ����� �ּҸ� ����
		L->head = newNode;								// �� ��尡 ù ��° ��尡 ��
	}
	else
	{
		newNode->link = pre->link;						// ������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;							// �� ����� link �ʵ忡 �� ��� �ּ� ����
	}
}

// ������ ���� �����ϴ� ����
void insertLastNode(linkedList_h* L, char* x)
{
	listNode* newNode;
	listNode* temp;									// ����Ʈ�� ������ ��带 ã�� ���� ��ȸ�ϴ� ������
	newNode = (listNode*)malloc(sizeof(listNode));	// �� ����� �޸𸮸� �Ҵ�
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return;
	}
	strcpy(newNode->data, x);						// �� ����� ������ �ʵ忡 x�� ���� ����
	newNode->link = NULL;							// �� ����� link �ʵ带 NULL�� ���� (������ ������� ��Ÿ��)
	if (L->head == NULL)							// ���� ����Ʈ�� ������ ���
	{
		L->head = newNode;							// �� ��带 ����Ʈ�� ù ��° ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;									// temp �����͸� ����Ʈ�� ù ��° ���� �ʱ�ȭ
	while (temp->link != NULL)						// ���� ����Ʈ�� ������ ��带 ã��
	{
		temp = temp->link;							// temp�� ���� ���� �̵�
	}
	temp->link = newNode;							// �� ��带 ������ ���(temp)�� ���� ���� ����
}

// ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(linkedList_h* L, listNode* p)
{
	listNode* pre;									// ������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL)	return;					// ���� ����Ʈ��� ���� ���� �ߴ�
	if (L->head->link == NULL)						// ��尡 �� ���� �ִ� ���
	{
		free(L->head);								// ù ��° ��带 �޸� ����
		L->head = NULL;								// ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (p == NULL) return;						// ������ ��尡 ���ٸ� ���� ���� �ߴ�
	else											// ������ ��� p�� ������ ��带 ������ pre�� �̿��� ã��
	{
		pre = L->head;								
		while (pre->link != p)						// ���� ����� link �ʵ�� ������ ��� p�� ���� ������
		{
			pre = pre->link;						// ���� ���� �̵�
		}
		pre->link = p->link;						// ������ ��� p�� ������ ���� ���� ��带 ����
		free(p);									// ���� ����� �޸� ����
	}
}

// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* L, char* x)
{
	listNode* temp;									// ����Ʈ�� ��带 ��ȸ�ϱ� ���� ������
	temp = L->head;									// ù ������ Ž��
	while (temp != NULL)
	{
		if (strcmp(temp->data, x) == 0) return temp;// ���� temp ����� ������ �ʵ尪�� Ž���� x�� ������, ���� temp���� �����Ͽ� x�� �ִ� ��� �ּҸ� �˷���
		else temp = temp->link;						// ���� temp ����� ������ �ʵ尪�� Ž���� x�� ���� ������ ���� ���� �̵�
	}
	return temp;									// ����Ʈ L�� Ž���� x�� ���ٴ� �ǹ̷� NULL���� ��ȯ
}

// ����Ʈ�� ��� ������ �������� �ٲٴ� ����
void reverse(linkedList_h* L)
{
	listNode* p;		// ���� ��带 ����ų ������
	listNode* q;		// ���� ��带 ����ų ������
	listNode* r;		// ���� ����� ��ũ�� ������ ������

	p = L->head;		// ����Ʈ�� ù ��° ���� �ʱ�ȭ
	q = NULL;			// q�� �ʱ⿡�� NULL�� ���� (ù ��° ����� ���� ��尡 ����)
	r = NULL;			// r�� �ʱ⿡�� NULL�� ����

	// ����Ʈ�� ù ��° ������ �����Ͽ� ��ũ�� ���󰡸鼭 ��� ���� ������ �ٲ�
	while (p != NULL)	// ���� ��尡 NULL�� �ƴ� ������ �ݺ�, ����Ʈ�� ��� ��带 ��ȸ
	{
		r = q;			// r�� ���� q(���� ���)�� ����Ŵ
		q = p;			// q�� ���� p(���� ���)�� ����Ŵ
		p = p->link;	// p�� ���� ���� �̵� (���� ��夤�� ��ũ�� ����)
		q->link = r;	// ���� ���(q)�� ��ũ�� ���� ���(r)�� ���� (��ũ ����)
	}

	L->head = q; // �ݺ��� ���� ��, q�� ���ο� ��尡 �� (����Ʈ�� ������ ��尡 ù ��° ��尡 ��)
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "4-5LinkedPoly.h"	

// ���� ���׽� ����Ʈ�� �����ϴ� ����
ListHead* createLinkedList(void)
{
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}

// ���׽� ����Ʈ�� ������ ��带 �߰��ϴ� ����
void appendTerm(ListHead* L, float coef, int expo)
{
	ListNode* newNode;			// �� ��带 ���� ������
	ListNode* p;				// ���� ��带 Ž���ϱ� ���� ������
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;		// ���
	newNode->expo = expo;		// ����
	newNode->link = NULL;		// ���� ���� NULL�� �ʱ�ȭ

	if (L->head == NULL)		// ���׽� ����Ʈ�� ������ ���
	{
		L->head = newNode;		// �� ��带 ���� ����
		return;
	}
	
	else
	{
		p = L->head;			// Ž���� ������ ����
		while (p->link != NULL) // ������ ��带 ã�� ������ �ݺ�
		{
			p = p->link;		// ���� ���� �̵�
		}
		p->link = newNode;		// �� ��� ����
	}
}

// �� ���׽��� ������ ���ϴ� ����
void addPoly(ListHead* A, ListHead* B, ListHead* C)
{
	ListNode* pA = A->head;						// A ���׽��� ���� ���
	ListNode* pB = B->head;						// B ���׽��� ���� ���
	float sum;									// ����� �ջ��� ����

	// �� ���׽Ŀ� ��尡 �ִ� ���� �ݺ� ����
	while (pA && pB) {
		// ���׽� A�� ������ ���׽� B�� ������ ���� ���
		if (pA->expo == pB->expo) 
		{
			sum = pA->coef + pB->coef;			// ��� �ջ�
			appendTerm(C, sum, pA->expo);		// ��� ���׽Ŀ� �߰�
			pA = pA->link;						// ���� ���� �̵�
			pB = pB->link;						// ���� ���� �̵�
		}
		// ���׽� A�� ������ ���׽� B�� �������� ū ���
		else if (pA->expo > pB->expo)
		{
			appendTerm(C, pA->coef, pA->expo);	// ��� ���׽Ŀ� �߰�
			pA = pA->link;						// ���׽� A ���� ���� �̵�
		}
		// ���׽� A�� ������ ���׽� B�� �������� ���� ���
		else
		{
			appendTerm(C, pB->coef, pB->expo);	// ��� ���׽Ŀ� �߰�
			pB = pB->link;						// ���׽� B ���� ���� �̵�
		}
	}
	// ���׽� A�� ���� �ִ� ��� ����
	while (pA != NULL) 
	{
		appendTerm(C, pA->coef, pA->expo);		// ��� ���׽Ŀ� �߰�
		pA = pA->link;
	}

	// ���׽� B�� ���� �ִ� ��� ����
	while (pB != NULL) 
	{
		appendTerm(C, pB->coef, pB->expo);		// ��� ���׽Ŀ� �߰�
		pB = pB->link;
	}
}

// ���׽� ����Ʈ�� ����ϴ� ����
void printPoly(ListHead* L)
{
	ListNode* p = L->head;						// ���� ��带 ���� �ʱ�ȭ
	
	if (p == NULL)
	{
		printf("���׽��� ��� �ֽ��ϴ�. \n");	// ����Ʈ�� ��� �ִ� ��� �޽��� ���
		return;
	}

	while (p) 
	{
		printf("%3.0fx^%d", p->coef, p->expo);	// ���� ����� ����� ���� ���
		p = p->link;							// ���� ���� �̵�, ���� ������ �̵�
		if (p != NULL) printf(" +");			// ���� ��尡 ������ '+' ���
	}
}
#endif

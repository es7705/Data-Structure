#if 0
#pragma once
// ���׽� ����Ʈ�� ��� ������ ����ü�� ����
float coef;	// ���
typedef struct ListNode 
{
	float coef;	// ���
	int expo;	// ����
	struct ListNode* link;	// ���� ��
} ListNode;

// ���׽� ����Ʈ�� head ��带 ����ü�� ����
typedef struct ListHead
{
	ListNode* head;
}ListHead;

ListHead* createLinkedList(void);						// ���� ���׽� ����Ʈ�� �����ϴ� ����
void appendTerm(ListHead* L, float coef, int expo);		// ���׽� ����Ʈ�� ������ ��带 �߰��ϴ� ����
void addPoly(ListHead* A, ListHead* B, ListHead* C);	// �� ���׽��� ������ ���ϴ� ����
void printPoly(ListHead* L);							// ���׽� ����Ʈ�� ����ϴ� ����
#endif

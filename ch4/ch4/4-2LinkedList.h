#if 1
#pragma once
// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode
{
	char data[4];								// ���ڿ��� ������ ����
	struct ListNode* link;						// ���� ����� �ּҸ� ������ ������
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct
{
	listNode* head;								// ���� ����Ʈ�� ������ ����Ű�� ������, listNode ����ü Ÿ���� �ּҸ� ������ �� �ִ� ������
}linkedList_h;

linkedList_h* createLinkedList_h(void);			// �����͸� ��ȯ�ϴ� �Լ�, ���� ���� ����Ʈ�� �����ϴ� �Լ�
void freeLinkedList_h(linkedList_h* L);			// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� �Լ�
void printList(linkedList_h* L);				// ���� ����Ʈ�� ������� ����ϴ� �Լ�
void insertFirstNode(linkedList_h* L, char* x);	// ù ��° ���� �����ϴ� �Լ�	
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);	// ��带 pre �ڿ� �����ϴ� �Լ�
void insertLastNode(linkedList_h* L, char* x);	// ������ ���� �����ϴ� �Լ�
void deleteNode(linkedList_h* L, listNode* p);	// ����Ʈ���� ��� p�� �����ϴ� ����
listNode* searchNode(linkedList_h* L, char* x);	// ����Ʈ���� x ��带 Ž���ϴ� ����
void reverse(linkedList_h* L);					// ����Ʈ�� ��� ������ �������� �ٲٴ� ����
#endif
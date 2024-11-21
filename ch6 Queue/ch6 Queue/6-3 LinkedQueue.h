#if 0
#pragma once
typedef char element;		// ���� ť ����(element)�� �ڷ����� char�� ����

typedef struct QNode {		// ���� ť�� ��带 ����ü�� ����
	element data;			// ��尡 ������ ������
	struct QNode* link;		// ���� ��带 ����Ű�� ������
}QNode;

typedef struct {			// ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ����
	QNode* front;			// ť�� �� �� ��带 ����Ű�� ������
	QNode* rear;			// ť�� �� �� ��带 ����Ű�� ������
}LQueueType;

LQueueType* createLinkedQueue(void);
int isLQEmpty(LQueueType* LQ);
void enLQueue(LQueueType* LQ, element item);
element deLQueue(LQueueType* LQ);
element peekLQ(LQueueType* LQ);
void printLQ(LQueueType* LQ);
#endif
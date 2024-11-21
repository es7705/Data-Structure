#if 0
#pragma once
#define Q_SIZE 4
typedef char element;	// ť ����(element)�� �ڷ����� char�� ����

typedef struct {
	element queue[Q_SIZE];	// 1���� �迭 ť ����
	int front, rear;
}QueueType;

QueueType* createQueue(void);				// ���� ���� ť ����
int isQueueEmpty(QueueType* Q);				// ���� ť�� ���� �������� �˻��ϴ� �Լ�
int isQueueFull(QueueType* Q);				// ���� ť�� ��ȭ �������� �˻��ϴ� �Լ�
void enQueue(QueueType* Q, element item);	// ���� ť�� rear�� ���Ҹ� �����ϴ� �Լ�
element deQueue(QueueType* Q);				// ���� ť�� front���� ���Ҹ� �����ϴ� ����
element peekQ(QueueType* Q);				// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� �Լ�
void printQ(QueueType* Q);					// ���� ť�� ���Ҹ� ����ϴ� �Լ�
#endif
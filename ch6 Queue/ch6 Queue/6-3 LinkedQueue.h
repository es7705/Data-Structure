#if 0
#pragma once
typedef char element;		// 연결 큐 원소(element)의 자료형을 char로 정의

typedef struct QNode {		// 연결 큐의 노드를 구조체로 정의
	element data;			// 노드가 저장할 데이터
	struct QNode* link;		// 다음 노드를 가리키는 포인터
}QNode;

typedef struct {			// 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의
	QNode* front;			// 큐의 맨 앞 노드를 가리키는 포인터
	QNode* rear;			// 큐의 맨 뒤 노드를 가리키는 포인터
}LQueueType;

LQueueType* createLinkedQueue(void);
int isLQEmpty(LQueueType* LQ);
void enLQueue(LQueueType* LQ, element item);
element deLQueue(LQueueType* LQ);
element peekLQ(LQueueType* LQ);
void printLQ(LQueueType* LQ);
#endif
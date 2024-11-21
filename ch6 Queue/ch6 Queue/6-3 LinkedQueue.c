#if 0
#include <stdio.h>
#include <stdlib.h>	
#include "6-3 LinkedQueue.h"

// 공배 연결 큐를 생성하는 연산
LQueueType* createLinkedQueue(void)
{
	LQueueType* LQ;		// 연결 큐 포인터 선언
	LQ = (LQueueType*)malloc(sizeof(LQueueType));	// 연결 큐를 위한 메모리 할당
	LQ->front = NULL;	// 큐의 맨 앞 노드를 가리키는 front를 NULL로 초기화 (비어있음)
	LQ->rear = NULL;	// 큐의 맨 뒤 노드를 가리키는 rear를 NULL로 초기화 (비어있음)
	return LQ;			// 생성된 큐를 반환
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType* LQ)
{	
	if (LQ->front == NULL)	// 큐의 front가 NULL이면 공백 큐
	{
		printf(" Linked Queue is empty! ");
		return 1;			// 큐가 비어있으면 1을 반환
	}
	else
		return 0;			// 큐가 비어있지 않으면 0을 반환
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enLQueue(LQueueType* LQ, element item)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));	// 새 노드 메모리 할당
	newNode->data = item;	// 새 도느의 데이터에 삽입할 원소 저장
	newNode->link = NULL;	// 새 노드의 링크를 NULL롤 초기화 (맨 마지막 노드를 의미)

	if (LQ->front == NULL)	// 현재 연결 큐가 공백 상태인 경우, 새 노드가 첫 노드인 경우
	{		
		LQ->front = newNode;// front가 새 노드를 가리킴				
		LQ->rear = newNode; // rear도 새 노드를 가리킴
	}

	else					// 현재 연결 큐가 공백 상태가 아닌 경우
	{
		LQ->rear->link = newNode;	// 기존 rear이 가리키는 노드의 링크에 새 노드의 주소를 저장	
		LQ->rear = newNode;			// 마지막 노드를 가리키는 rear를 새 노드로 업데이트
	}
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
element deLQueue(LQueueType* LQ)
{
	QNode* old = LQ->front;	// 삭제할 노드를 맨 앞 노드로 저장
	element item;			// 삭제할 노드의 원소를 저장할 변수

	if(isLQEmpty(LQ))		// 현재 연결 큐가 공백 상태인 경우
		return;				// 함수 종료
	else
	{
		item = old->data;	// 삭제할 노드의 데이터를 item에 저장
		LQ->front = LQ->front->link;	// 맨 앞 노드를 다음 노드로 업데이트
		if (LQ->front == NULL)			// 만약 다음 노드가 없다면
			LQ->rear = NULL;			// rear도 NULL로 설정 (큐가 비어있음을 의미)
		free(old);			// old 노드 메모리 해제
		return item;		// 삭제한 노드의 원소를 반환
	}
}

// 연결 큐에서 원소를 검색하는 연산
element peekLQ(LQueueType* LQ)
{
	element item;				// 검색할 노드의 원소를 저장할 변수
	if (isLQEmpty(LQ))			// 현재 연결 큐가 공백 상태인 경우
		return;					// 함수 종료
	else
	{
		item = LQ->front->data;	// 맨 앞 노드의 데이터를 item에 저장
		return item;			// 검색한 노드의 데이터를 반환
	}
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType* LQ)	
{
	QNode* temp = LQ->front;	// front에서 시작하는 임시 포인터
	printf(" Linked Queue : [");
	while (temp != NULL)		// 큐의 모든 원소를 출력
	{
		printf("%3c", temp->data);
		temp = temp->link;		// 다음 노드로 이동
	}
	printf(" ] ");
}
#endif
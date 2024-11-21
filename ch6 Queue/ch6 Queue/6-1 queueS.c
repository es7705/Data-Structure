#if 0
#include <stdio.h>	
#include <stdlib.h>
#include "6-1 queueS.h"

// 공백 순차 큐를 생성하는 연산
QueueType* createQueue(void)
{
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;	// front 초기화(-1로 설정하여 큐가 비어있음을 나타냄)
	Q->rear = -1;	// rear 초기화(-1로 설정하여 큐가 비어있음을 나타냄)
	return Q;
}

// 순차 큐가 공백 상태인지 검사하는 연산
int isQueueEmpty(QueueType* Q)
{
	if (Q->front == Q->rear)		// front와 rear가 같으면 큐가 비어있는 상태
	{
		printf(" Queue is empty! \n\t ");
		return 1;					// 비어 있으면 1을 반환
	}

	else
		return 0;					// 비어 있지 않으면 0을 반환
}

// 순차 쿠가 포화 상태인지 검사하는 연산
int isQueueFull(QueueType* Q)
{
	if (Q->rear == Q_SIZE - 1)	// rear가 쿠의 최대 크기보다 크면 쿠가 포화 상태
	{
		printf(" Queue is full! \n\t ");
		return 1;
	}
	else
		return 0;
}

// 순차 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType* Q, element item)
{
	if (isQueueFull(Q))		// 포화 상태이면, 삽입 연산 중단
		return;				// 함수 종료
	else
	{
		Q->rear++;			// rear를 1 증가시켜 새로운 위치로 이동
		Q->queue[Q->rear] = item;	// 큐의 rear 위치에 원소 삽입
	}
}

// 순차 큐의 front에서 원소를 삭제하는 연산
element deQueue(QueueType* Q)
{
	if (isQueueEmpty(Q))	// 공백 상택이면, 삭제 연산 중단
		return;				// 함수 종료
	else
	{
		Q->front++;			// front를 1 증가시켜 삭제할 원소의 위치로 이동
		return Q->queue[Q->front];	
	}
}

// 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peekQ(QueueType* Q)
{
	if (isQueueEmpty(Q))		// 큐가 공백 상태이면
		return;					// 함수 종료
	else
		return Q->queue[Q->front + 1];	// 가장 앞에 있는 원소를 반환
}

// 순차 큐의 원소를 출력하는 연산
void printQ(QueueType* Q)
{
	int i;
	printf(" Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)	// front 다음부터 rear까지 반복
		printf("%3c", Q->queue[i]);				// 각 원소를 출력
	printf(" ]");
}
#endif
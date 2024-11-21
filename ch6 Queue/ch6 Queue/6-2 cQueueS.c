#if 0
#include <stdio.h>
#include <stdlib.h>
#include "6-2 cQueueS.h"

// 공백 큐를 생성하는 연산
QueueType* createQueue(void)
{
	QueueType* cQ;		// 큐 타입의 포인터 cQ를 선언
	cQ = (QueueType*)malloc(sizeof(QueueType));	// 큐를 위한 메모리 할당
	cQ->front = 0;	// front를 0으로 초기화 (큐의 앞 위치)
	cQ->rear = 0;	// rear를 0으로 초기화 (큐의 뒤 위치)
	return cQ;		// 생성된 큐 포인터 반환
}

// 원형 큐가 공백 상태인지 검사하는 연산
int isCQueuEmpty(QueueType* cQ)
{
	if (cQ->front == cQ->rear)		// front와 reqr가 같으면 큐가 비어있음
	{
		printf("Circular Queue is empty! ");
		return 1;
	}
	else 
		return 0;
}

// 원형 큐가 포화 상태인지 검사하는 연산
int isCQueueFull(QueueType* cQ)
{
	// rear의 다음 위치가 front와 같은면 큐가 포화 상태
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front)
	{
		printf("  Circular Queue is full! ");
		return 1;
	}
	else
		return 0;
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enCQueue(QueueType* cQ, element item)
{
	if (isCQueueFull(cQ))	// 큐가 포화 상태이면, 삽입 연산 중단
		return;				// 함수 종료
	else
	{
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;	// rear을 1 증가시키고 원형 큐에 맞게 조정
		cQ->queue[cQ->rear] = item;				// 큐의 rear 위치에 원소 삽입
	}
}

// 원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deCQueue(QueueType* cQ)
{
	if (isCQueuEmpty(cQ))		// 큐가 공백 상태이면, 삭제 연산 중단
		return;					// 함수 종료
	else
	{
		cQ->front = (cQ->front + 1) % cQ_SIZE;	// front를 1 증가시키고 원형 큐에 맞게 조정
		return cQ->queue[cQ->front];			// 삭제된 원소를 반환
	}
}

// 원형 큐의 가장 앞에 있는 원소를 검색하는 연산
element peekCQ(QueueType* cQ)
{			
	if (isCQueuEmpty(cQ))		// 큐가 공백 상태이면, 삭제 연산 중단
		return;					// 함수 종료
	else
		return cQ->queue[(cQ->front + 1) % cQ_SIZE];	// fornt 다음 위치의 원소를 반환
}

// 원형 큐의 원소를 출력하는 연산
void printCQ(QueueType* cQ)
{
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;	// 출력할 첫 번째 원소의 인덱스 계산
	last = (cQ->rear + 1) % cQ_SIZE;	// 출력할 마지막 원소의 인덱스 계산
	printf(" Circular Queue : [");
	i = first;							// 첫 번째 원소부터 시작
	while (i != last)					// first와 last가 같지 않을 동안 반복
	{
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;			// 다음 원소의 인덱스로 이동
	}
	printf(" ] ");
}


#endif
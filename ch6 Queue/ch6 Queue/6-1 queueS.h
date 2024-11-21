#if 0
#pragma once
#define Q_SIZE 4
typedef char element;	// 큐 원소(element)의 자료형을 char로 정의

typedef struct {
	element queue[Q_SIZE];	// 1차원 배열 큐 선언
	int front, rear;
}QueueType;

QueueType* createQueue(void);				// 공백 순차 큐 생성
int isQueueEmpty(QueueType* Q);				// 순차 큐가 공백 상태인지 검사하는 함수
int isQueueFull(QueueType* Q);				// 순차 큐가 포화 상태인지 검사하는 함수
void enQueue(QueueType* Q, element item);	// 순차 큐의 rear에 원소를 삽입하는 함수
element deQueue(QueueType* Q);				// 순차 큐의 front에서 원소를 삭제하는 연산
element peekQ(QueueType* Q);				// 순차 큐의 가장 앞에 있는 원소를 검색하는 함수
void printQ(QueueType* Q);					// 순차 큐의 원소를 출력하는 함수
#endif
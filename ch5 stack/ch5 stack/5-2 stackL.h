#if 0
#pragma once
#ifndef stackL__H_
#define stackL__H_
typedef int element;		// 스택 원소(element)의 자료형을 int로 정의

typedef struct stackNode
{
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;	// 스택의 top 노드를 지정하기 위해 포인터 top 선언

int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

#endif // !stackL__H_
#endif
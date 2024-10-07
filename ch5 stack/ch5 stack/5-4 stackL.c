#if 0
#include <stdio.h>
#include <stdlib.h>
#include "5-4 stackL.h"	

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty(void)
{
	if (top == NULL)		// 비어 있는 경우
		return 1;
	else
		return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item)
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;		// 원소 저장
	temp->link = top;		// 삽입 노드를 top의 위에 연결
	top = temp;				// top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop(void)
{
	element item;			// 삭제할 데이터를 반환할 변수
	stackNode* temp = top;	// top에 있는 삭제할 노드를 저장

	if (isStackEmpty())		// 스택이 공백인 경우
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else					// 스택이 공백 리스트가 아닌 경우
	{
		item = temp->data;
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동	
		free(temp);			// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}

// 스택의 top 원소를 검색하는 연산
element peek(void)
{
	if (isStackEmpty())		// 스택이 공백인 경우
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else					// 스택이 공백 리스트가 아닌 경우
	{
		return(top->data);	// 현재 top의 원소 반환
	}
}

void printStack(void)
{
	stackNode* p = top;			// top부터 출력
	printf("\n STACK [ ");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;			// 밑에 노드로 이동
	}
	printf("] ");
}
#endif

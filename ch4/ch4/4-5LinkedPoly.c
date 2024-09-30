#if 0
#include <stdio.h>
#include <stdlib.h>
#include "4-5LinkedPoly.h"	

// 공백 다항식 리스트를 생성하는 연산
ListHead* createLinkedList(void)
{
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}

// 다항식 리스트에 마지막 노드를 추가하는 연산
void appendTerm(ListHead* L, float coef, int expo)
{
	ListNode* newNode;			// 새 노드를 위한 포인터
	ListNode* p;				// 현재 노드를 탐색하기 위한 포인터
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;		// 계수
	newNode->expo = expo;		// 지수
	newNode->link = NULL;		// 다음 노드는 NULL로 초기화

	if (L->head == NULL)		// 다항식 리스트가 공백인 경우
	{
		L->head = newNode;		// 새 노드를 헤드로 설정
		return;
	}
	
	else
	{
		p = L->head;			// 탐색을 헤드부터 시작
		while (p->link != NULL) // 마지막 노드를 찾을 때까지 반복
		{
			p = p->link;		// 다음 노드로 이동
		}
		p->link = newNode;		// 새 노드 연결
	}
}

// 두 다항식의 덧셈을 구하는 연산
void addPoly(ListHead* A, ListHead* B, ListHead* C)
{
	ListNode* pA = A->head;						// A 다항식의 현재 노드
	ListNode* pB = B->head;						// B 다항식의 현재 노드
	float sum;									// 계수를 합산할 변수

	// 두 다항식에 노드가 있는 동안 반복 수행
	while (pA && pB) {
		// 다항식 A의 지수가 다항식 B의 지수와 같은 경우
		if (pA->expo == pB->expo) 
		{
			sum = pA->coef + pB->coef;			// 계수 합산
			appendTerm(C, sum, pA->expo);		// 결과 다항식에 추가
			pA = pA->link;						// 다음 노드로 이동
			pB = pB->link;						// 다음 노드로 이동
		}
		// 다항식 A의 지수가 다항식 B의 지수보다 큰 경우
		else if (pA->expo > pB->expo)
		{
			appendTerm(C, pA->coef, pA->expo);	// 결과 다항식에 추가
			pA = pA->link;						// 다항식 A 다음 노드로 이동
		}
		// 다항식 A의 지수가 다항식 B의 지수보다 작은 경우
		else
		{
			appendTerm(C, pB->coef, pB->expo);	// 결과 다항식에 추가
			pB = pB->link;						// 다항식 B 다음 노드로 이동
		}
	}
	// 다항식 A에 남아 있는 노드 복사
	while (pA != NULL) 
	{
		appendTerm(C, pA->coef, pA->expo);		// 결과 다항식에 추가
		pA = pA->link;
	}

	// 다항식 B에 남아 있는 노드 복사
	while (pB != NULL) 
	{
		appendTerm(C, pB->coef, pB->expo);		// 결과 다항식에 추가
		pB = pB->link;
	}
}

// 다항식 리스트를 출력하는 연산
void printPoly(ListHead* L)
{
	ListNode* p = L->head;						// 현재 노드를 헤드로 초기화
	
	if (p == NULL)
	{
		printf("다항식이 비어 있습니다. \n");	// 리스트가 비어 있는 경우 메시지 출력
		return;
	}

	while (p) 
	{
		printf("%3.0fx^%d", p->coef, p->expo);	// 현재 노드의 계수와 지수 출력
		p = p->link;							// 다음 노드로 이동, 다음 차수로 이동
		if (p != NULL) printf(" +");			// 다음 노드가 있으면 '+' 출력
	}
}
#endif

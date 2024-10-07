#if 0
#pragma once
// 다항식 리스트의 노드 구조를 구조체로 정의
float coef;	// 계수
typedef struct ListNode 
{
	float coef;	// 계수
	int expo;	// 지수
	struct ListNode* link;	// 다음 항
} ListNode;

// 다항식 리스트의 head 노드를 구조체로 정의
typedef struct ListHead
{
	ListNode* head;
}ListHead;

ListHead* createLinkedList(void);						// 공백 다항식 리스트를 생성하는 연산
void appendTerm(ListHead* L, float coef, int expo);		// 다항식 리스트에 마지막 노드를 추가하는 연산
void addPoly(ListHead* A, ListHead* B, ListHead* C);	// 두 다항식의 덧셈을 구하는 연산
void printPoly(ListHead* L);							// 다항식 리스트를 출력하는 연산
#endif

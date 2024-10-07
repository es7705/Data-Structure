#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>	
#include "4-4DoubleLinkedLinst.h"	

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void)
{
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

// 이중 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* DL)
{
	listNode* p;						// 현재 노드를 카리키는 포인터
	printf("DL = (");

	p = DL->head;						// 현재 노드를 첫 번째 노드로 초기화
	while (p != NULL)					// 현재 노드가 NULL이 아닐 때까지 반복, 마지막 노드까지 반복
	{
		printf("%s", p->data);			// 현재 노드의 데이터 출력
		p = p->rlink;					// 다음 노드로 이동
		if (p != NULL)	printf(", ");	// 다음 노드가 NULL이 아닐 경우 구분자 출력
	}
	printf(") \n");
}

// pre 뒤에 노드를 삽입하는 연산
void insertNode(linkedList_h* DL, listNode* pre, char* x)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL)		// 공백 리스트인 경우
	{
		newNode->rlink = NULL;	// 왼쪽, 오른쪽 링크 필드 NULL
		newNode->llink = NULL;
		DL->head = newNode;		// 리스트의 시작 노드를 새 노드로 지정
	}
	else // 리스트가 비어있지 않은 경우
	{
		newNode->rlink = pre->rlink; // 새로운 노드의 오른쪽 링크를 선행노드의 오른쪽 링크로 설정
		pre->rlink = newNode;		 // pre의 오른쪽 링크를 새로운 노드로 설정
		newNode->llink = pre;		 // 새로운 노드의 왼쪽 링크를 선행노드 주소로 설정

		if (newNode->rlink != NULL)  // 새 노드의 오른쪽에 노드가 있으면
		{
			newNode->rlink->llink = newNode; // 오른쪽 노드의 왼쪽 링크를 새로운 노드로 설정
		}
	}
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(linkedList_h* DL, listNode* old)
{
	if (DL->head == NULL)	return;		// 공백 리스트인 경우 삭제 연산 중단
	else if (old == NULL) return;		// 삭제할 노드가 없는 경우 삭제 연산 중단
	else
	{
		old->llink->rlink = old->rlink;	
		old->rlink->llink = old->llink;
		free(old);						// 삭제 노드의 메모리 해제
	}
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* DL, char* x)
{
	listNode* temp;										// 임시 순회 노드 포인터
	temp = DL->head;									// 첫 번째 노드부터 순회
	while (temp != NULL)								// 공백 리스트가 아니면
	{
		if (strcmp(temp->data, x) == 0) return temp;	// 찾음
		else temp = temp->rlink;						// 못 찾음
	}
	return temp;
}
#endif
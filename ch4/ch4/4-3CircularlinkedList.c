#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include "4-3CircularlinkedList.h"	

// 공백 원형 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void)
{
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	//CL->head = NULL;
	return CL;
}

// 연렬 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* CL)
{
	listNode* p;
	printf(" CL = (");
	p = CL->head;

	if (p == NULL)			// 빈 리스트인 경우
	{
		printf(") \n");
		return;
	}

	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

// 첫 번째 노드 삽입 연산
void insertFisrtNode(linkedList_h* CL, char* x)
{
	listNode* newNode, * temp;	// temp : 임시 순회 포인터
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL)		// 원형 연결 리스트가 공백인 경우
	{
		CL->head = newNode;		// 새 노드를 리스트의 시작 노드로 연결
		newNode->link = newNode;// 새 노도의 링크가 자기 자신을 연결		
	}
	else						// 원형 연결 리스트가 공백이 아닌 경우
	{	
		temp = CL->head;		// 임시 순회 포인터에 head를 저장
		while (temp->link != CL->head)
		{
			temp = temp->link;	// 순회 포인터를 링크에 따라 마지막 노드까지 이동
		}
		newNode->link = temp->link;	// 마지막 노드의 링크 값을 새 노드의 링크 필드에 저장, 새 노드는 첫 번째 노드와 연결
		temp->link = newNode;		// 마지막 노드를 첫 번째 노드인 새 노드와 원형 연결
		CL->head = newNode;			// 새 노드의 주소를 리스트 시작 포인터 CL에 저장하여 새 노드를 리스트의 첫 번째 노드가 되도록 연결
	}
}

// pre 뒤에 노드를 삽입하는 연산
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL)		// 원형 연결 리스트가 공백인 경우
	{
		CL->head = newNode;		// 리스트의 시작을 새 노드를 설정
		newNode->link = newNode;// 새 노드의 링크가 자기 자신으로 연결
	}
	else
	{
		newNode->link = pre->link;	// 선행 노드의 다음 노드 주소를 새 노드의 링크 필드에 저장하여 연결
		pre->link = newNode;		// 새 노드의 주소를 선행 노드의 링크 필드에 저장하여 서로 연결
	}
}

// 원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(linkedList_h* CL, listNode* old)
{
	listNode* pre;					// 삭제할 도으의 선행자 노드를 나타내는 포인터
	if (CL->head == NULL) return;	// 공백 리스트인 경우 삭제 연산 중단
	if (CL->head->link == CL->head)	// 리스트에 노드가 한 개만 있는 경우
	{
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (old == NULL) return;	// 삭제할 노드가 없는 경우 삭제 연산 중단
	else
	{
		pre = CL->head;				// 포인터 pre를 리스트의 시작 노드에 연결
		while (pre->link != old)
		{
			pre = pre->link;		// 선행 노드를 포인터 pre를 이용해 찾음
		}
		pre->link = old->link;		// 삭제할 노드의 다음 노드 주소를 선행 노드 링크 필드에 저장
		if (old == CL->head)		// 삭제할 노드가 첫 번째 노드인지 확인
		{
			CL->head = old->link;	// 두 번째 노드가 첫 번째 노드가 되도록 조정
		}
		free(old);					// 삭제 노드의 메모리를 해제
	}
}

// 원형 연결 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* CL, char* x)
{
	listNode* temp;				// x를 찾기 위한 임시 순회 포인터
	temp = CL->head;
	if (temp == NULL) return NULL;	// 공백 리스트인 경우
	do {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;	// 다음 노드로 이동
	} while (temp != CL->head);	
	return NULL;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "4-2 LinkedList.h"

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void)
{
	linkedList_h* L;	// 연결 리스트의 head 포인터를 포함하는 구조체를 가리키는 포인터
	L = (linkedList_h*)malloc(sizeof(linkedList_h));	// linkedList_h 구조체 크기만큼 메모리를 할당하고 포인터 L에 저장
	if (L == NULL) {
		printf("메모리 할당 실패\n");
		return;
	}
	L->head = NULL;		// 공백 리스트이므로 NULL로 설정
	return L;			// 생성된 연결 리스트의 포인터 반환
}

void freeLinkedList_h(linkedList_h* L)
{
	listNode* p;					// 현재 노드를 가리킬 포인터 p
	while (L->head != NULL)			// 연결 리스트가 비어있지 않는 동안 반복
	{
		p = L->head;				// 첫 번째 노드의 주소를 p에 저장
		L->head = L->head->link;	// head는 다음 노드의 주소로 업데이트
		free(p);					// 현재 노드의 동적 메모리 해제
		p = NULL;					// p를 NULL로 초기화 (안전한 메모리 관리를 위해)
	}
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L)
{
	listNode* p;					// 현재 노드를 가리킬 포인터 p
	printf("L = (");
	p = L->head;					// 첫 번째 노드의 주소를 p에 저장
	while (p != NULL)				// 노드가 있는 동안 반복
	{
		printf("%s", p->data);		// 현재 노드의 데이터 출력
		p = p->link;				// p는 다음 노드를 가리킴
		if (p != NULL)				// 마지막 노드 전까지 ', ' 출력
			printf(", ");
	}
	printf(")\n");					// 리스트 출력 후 줄바꿈
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x)
{
	listNode* newNode;									// 새 노드를 가리킬 포인터
	newNode = (listNode*)malloc(sizeof(listNode));		// 삽입할 새 노드 할당
	if (newNode == NULL) {
		printf("메모리 할당 실패\n");
		return;
	}
	strcpy(newNode->data, x);							// 새 노드의 데이터 필드에 x 복사
	newNode->link = L->head;							// 기존 첫 번째 노드의 주소를 새 노드의 link 필드에 저장
	L->head = newNode;									// 새 노드가 연결 리스트의 첫 번째 노드가 됨
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x)
{
	listNode* newNode;									// 새 노드를 가리킬 포인터
	newNode = (listNode*)malloc(sizeof(listNode));		// 삽입할 새 노드 할당
	if (newNode == NULL) {
		printf("메모리 할당 실패\n");
		return;
	}
	strcpy(newNode->data, x);							// 새 노드의 데이터 필드에 x 복사
	if (L->head == NULL)								// 공백 리스트인 경우
	{
		newNode->link = NULL;							// 새 노드의 link를 NULL로 설정 (첫 번째 노드이자 유일한 노드)
		L->head = newNode;								// 새 노드는 첫 번째 노드가 됨
	}
	else if (pre == NULL)								// pre가 NULL인 경우 (리스트의 맨 앞에 삽입)		
	{	// pre가 NULL이라는 것은 삽입할 위치가 현재 리스트의 첫 번째 노드 앞이라는 것을 의미. 즉, 리스트의 맨 앞에 새 노드를 추가하려는 상황
		newNode->link = L->head;						// 새노드의 link 필드에 현재 리스트의 첫 번째 노드의 주소를 저장
		L->head = newNode;								// 새 노드가 첫 번째 노드가 됨
	}
	else
	{
		newNode->link = pre->link;						// 포인터 pre의 노드 뒤에 새 노드 연결
		pre->link = newNode;							// 앞 노드의 link 필드에 새 노드 주소 저장
	}
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x)
{
	listNode* newNode;
	listNode* temp;									// 리스트의 마지막 노드를 찾기 위해 순회하는 포인터
	newNode = (listNode*)malloc(sizeof(listNode));	// 새 노드의 메모리를 할당
	if (newNode == NULL) {
		printf("메모리 할당 실패\n");
		return;
	}
	strcpy(newNode->data, x);						// 새 노드의 데이터 필드에 x의 값을 복사
	newNode->link = NULL;							// 새 노드의 link 필드를 NULL로 설정 (마지막 노드임을 나타냄)
	if (L->head == NULL)							// 현재 리스트가 공백인 경우
	{
		L->head = newNode;							// 새 노드를 리스트의 첫 번째 노드로 연결
		return;
	}
	// 현재 리스트가 공백이 아닌 경우
	temp = L->head;									// temp 포인터를 리스트의 첫 번째 노드로 초기화
	while (temp->link != NULL)						// 현재 리스트의 마지막 노드를 찾음
	{
		temp = temp->link;							// temp를 다음 노드로 이동
	}
	temp->link = newNode;							// 새 노드를 마지막 노드(temp)의 다음 노드로 연결
}

// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(linkedList_h* L, listNode* p)
{
	listNode* pre;	// 삭제할 노드의 선행자 노드를 나타낼 포인터
	if (L->head == NULL)	// 공백 리스트라면 삭제 연산 중단
		return;
	if (L->head->link == NULL)	// 리스트에 노드가 한 개만 있는 경유
	{
		free(L->head);			// 첫 번째 노드를 메모리에서 해제하고
		L->head = NULL;			// 리스트 시작 포인터를 NULL로 설정
		return;
	}
	else if (p == NULL)			// 삭제할 노드가 없다면 삭제 연산 중단
		return;
	else						// 삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해 찾음
	{
		pre = L->head;			
		while (pre->link != p)
		{
			pre = pre->link;	// 다음 노드로 이동
		}
		pre->link = p->link;	// 삭제할 노드 p의 선행자 노드와 다음 노드를 연결
		free(p);				// 삭제 노드의 메모리 해제
	}
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* L, char* x)
{
	listNode* temp;		// 현재 노드를 가리킬 포인터
	temp = L->head;		// temp를 리스트의 첫 번째 노드로 초기화
	while (temp != NULL)	// 노드가 있는 동안 반복
	{
		if (strcmp(temp->data, x) == 0)	// 현재 노드의 데이터와 x가 동일한지 비교
			return temp;				// 동일한 데이터가 발견되면 해당 노드 포인터 반환
		else
			temp = temp->link;			// 다음 노드로 이동
	}
}

// 리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(linkedList_h* L)
{
	listNode* p;	// 현재 노드를 가리킬 포인터
	listNode* q;	// 이전 노드를 가리킬 포인터
	listNode* r;	// 다음 노드를 가리킬 포인터

	p = L->head;		// 포인터 p를 첫 번째 노드에 설정
	q = NULL;
	r = NULL;

	// 리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서 노드 간의 연결을 바꿈
	while (p != NULL)
	{	
		r = q;			// r은 q의 값을 저장 (현재의 이전 노드를 가리킴)
		q = p;			// q는 현재 노드를 가리킴
		p = p->link;	// p는 다음 노드로 이동
		q->link = r;	// p는 다음 노드로 이동
	}
	L->head = q;		// 마지막에 q는 새로운 head가 됨 (리스트의 마지막 노드)
}
#endif



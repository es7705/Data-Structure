#if 0
#pragma once
// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode
{
	char data[4];								// 문자열을 저장한 변수
	struct ListNode* link;						// 다음 노드의 주소를 저장할 포인터
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct
{
	listNode* head;								// 연결 리스트의 시작을 가리키는 포인터, listNode 구조체 타입의 주소를 저장할 수 있는 포인터
}linkedList_h;

linkedList_h* createLinkedList_h(void);			// 포인터를 반환하는 함수, 공백 연결 리스트를 생성하는 함수
void freeLinkedList_h(linkedList_h* L);			// 연결 리스트의 전체 메모리를 해제하는 함수
void printList(linkedList_h* L);				// 연결 리스트를 순서대로 출력하는 함수
void insertFirstNode(linkedList_h* L, char* x);	// 첫 번째 노드로 삽입하는 함수	
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x);	// 노드를 pre 뒤에 삽입하는 함수
void insertLastNode(linkedList_h* L, char* x);	// 마지막 노드롤 삽입하는 함수
#endif
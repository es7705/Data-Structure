// 4-1 단순 연결 리스트에 노드 삽입하기
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "4-1InsertLinkedList.h"	

int main()
{
	linkedList_h* L;
	L = createLinkedList_h();
	printf("(1) 공백 리스트 생성하기! \n");
	printList(L);

	printf("\n(2) 리스트에 [수] 노드 삽입하기! \n");
	insertFirstNode(L, "수");
	printList(L);

	printf("\n(3) 리스트 마지막에 [금] 노드 삽입하기! \n");
	insertLastNode(L, "금");
	printList(L);

	printf("\n(4) 리스트 첫 번째에 [월] 노드 삽입하기! \n");
	insertFirstNode(L, "월");
	printList(L);

	printf("\n(5) 리스트 첫 번째에 [화] 노드 삽입하기! \n");
	insertMiddleNode(L, L->head, "화");	// head는 "월" 노드 이므로 "월" 노드 뒤에 새 노드를 삽입
	printList(L);

	printf("\n(6) 리스트 첫 번째에 [목] 노드 삽입하기! \n");
	insertMiddleNode(L, L->head->link->link, "목");	// L->head : 월, L->head->link : 화, L->head->link->link : 수, "수" 노드 뒤에 새 노드 삽입
	printList(L);

	printf("\n(7) 리스트 공간을 해제하여 공배 리스트로 만들기! \n");
	freeLinkedList_h(L);
	printList(L);

	getchar();
	return 0;
}

#endif
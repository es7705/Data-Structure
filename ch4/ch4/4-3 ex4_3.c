// 4-3 원형 연결 리스트에서 노드 삽입 삭제 탐색하기
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "4-3CircularlinkedList.h"

int main()
{
	linkedList_h* CL;		// 원형 연결 리스트 생성을 위한 포인터
	listNode* p;			// 선행 노드 포인터

	CL = createLinkedList_h();	// 공백 원형 연결 리스트 생성
	printf("(1) 원형 연결 리스트 생성하기! \n");
	printList(CL);

	printf("\n(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
	insertFirstNode(CL, "월");
	printList(CL);

	printf("\n(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(CL, "월");
	insertMiddleNode(CL, p, "수");
	printList(CL);

	printf("\n(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(CL, "수");
	insertMiddleNode(CL, p, "금");
	printList(CL);

	printf("\n(5) 원형 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(CL, "수");
	deleteNode(CL, p);
	printList(CL);

	getchar();

	return 0;
}
#endif
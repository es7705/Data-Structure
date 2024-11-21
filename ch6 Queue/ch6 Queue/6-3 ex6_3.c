#if 0
// 6-3 연결 자료구조를 이용해 연결 큐 구현하기
#include <stdio.h>
#include "6-3 LinkedQueue.h"

int main(void)
{
	LQueueType* LQ = createLinkedQueue();		// 연결 큐 생성
	element data;		     // 반환된 노드의 데이터를 저장할 변수
	printf("\n ***** 연결 큐 연산 ***** \n");

	// 삽입
	printf("\n 삽입 A>>");
	enLQueue(LQ, 'A');
	printLQ(LQ);
	printf("\n 삽입 B>>");
	enLQueue(LQ, 'B');
	printLQ(LQ);
	printf("\n 삽입 C>>");
	enLQueue(LQ, 'C');
	printLQ(LQ);

	// 검색
	data = peekLQ(LQ);
	printf(" peek item : %c \n", data);

	// 삭제
	printf("\n 삭제 >>");
	data = deLQueue(LQ);
	printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deLQueue(LQ);
	printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deLQueue(LQ);
	printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	
	// 삽입 
	printf("\n 삽입 D>>");
	enLQueue(LQ, 'D');
	printLQ(LQ);
	printf("\n 삽입 E>>");
	enLQueue(LQ, 'E');
	printLQ(LQ);

	getchar();
	return 0;
}
#endif
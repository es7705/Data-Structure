#if 0
// 6-2 순차 자료구조를 이용해 원형 큐 구현하기
#include <stdio.h>	
#include "6-2 cQueueS.h"

int main(void)
{
	QueueType* cQ = createQueue();	// 공백 큐 생성
	element data;

	// 삽입
	printf("\n ***** 원형 큐 연산 ***** \n");
	printf("\n 삽입 A>>");
	enCQueue(cQ, 'A');
	printCQ(cQ);
	printf("\n 삽입 B>>");
	enCQueue(cQ, 'B');
	printCQ(cQ);
	printf("\n 삽입 C>>");
	enCQueue(cQ, 'C');
	printCQ(cQ);

	// 검색
	data = peekCQ(cQ);
	printf(" peek item : %c \n", data);

	// 삭제
	printf("\n 삭제 >>");
	data = deCQueue(cQ);
	printCQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deCQueue(cQ);
	printCQ(cQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deCQueue(cQ);
	printCQ(cQ);
	printf("\t삭제 데이터 : %c", data);

	// 삽입
	printf("\n 삽입 D>>");
	enCQueue(cQ, 'D');
	printCQ(cQ);
	printf("\n 삽입 E>>");
	enCQueue(cQ, 'E');
	printCQ(cQ);

	getchar();
	return 0;
}
#endif
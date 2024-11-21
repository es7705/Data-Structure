// 6-1 순차 자료구조를 이용해 순차 큐 구현하기
#if 0
#include <stdio.h>
#include "6-1 queueS.h"	

int main(void)
{
	QueueType* Q1 = createQueue();	// 큐 생성
	element data;
	printf("\n ***** 순차 큐 연산 ***** \n");

	// 삽입
	printf("\n 삽입 A>>");
	enQueue(Q1, 'A');
	printQ(Q1);
	printf("\n 삽입 B>>");
	enQueue(Q1, 'B');
	printQ(Q1);
	printf("\n 삽입 C>>");
	enQueue(Q1, 'C');
	printQ(Q1);

	// 검색
	data = peekQ(Q1);
	printf(" peek item : %c \n", data);

	// 삭제
	printf("\n 삭제 >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t삭제 데이터 : %c", data);

	// 삽입
	printf("\n 삽입 D>>");
	enQueue(Q1, 'D');
	printQ(Q1);
	printf("\n 삽입 E>>");
	enQueue(Q1, 'E');
	printQ(Q1);

	printf("\n\n");

	QueueType* Q2 = createQueue();	// 큐 생성
	//element data;
	printf("\n ***** 순차 큐 연산 ***** \n");

	// 삽입
	printf("\n 삽입 1>>");
	enQueue(Q2, '1');
	printQ(Q2);
	printf("\n 삽입 2>>");
	enQueue(Q2, '2');
	printQ(Q2);
	printf("\n 삽입 3>>");
	enQueue(Q2, '3');
	printQ(Q2);

	// 검색
	data = peekQ(Q2);
	printf(" peek item : %c \n", data);

	// 삭제
	printf("\n 삭제 >>");
	data = deQueue(Q2);
	printQ(Q2);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deQueue(Q2);
	printQ(Q2);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>");
	data = deQueue(Q2);
	printQ(Q2);
	printf("\t삭제 데이터 : %c", data);

	// 삽입
	printf("\n 삽입 4>>");
	enQueue(Q2, '4');
	printQ(Q2);
	printf("\n 삽입 5>>");
	enQueue(Q2, '5');
	printQ(Q2);
	getchar();
	return 0;
}

#endif	
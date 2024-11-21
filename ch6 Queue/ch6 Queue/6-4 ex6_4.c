// 6-4 이중 연결 리스트를 이용해서 데크 구현하기
#if 0
#include <stdio.h>	
#include "6-4 deQue.h"

int main(void)
{
	DQueType* DQ1 = createDQue();	// 데크 생성
	element data;

	printf("\n ***** 데크 연산 ***** \n");

	// 삽입
	printf("\n front 삽입 A>> ");
	insertFront(DQ1, 'A');
	printDQ(DQ1);
	printf("\n front 삽입 B>> ");
	insertFront(DQ1, 'B');
	printDQ(DQ1);
	printf("\n rear 삽입 C>> ");
	insertRear(DQ1, 'C');
	printDQ(DQ1);

	// 삭제
	printf("\n front 삭제 >> ");
	data = deleteFront(DQ1);
	printDQ(DQ1);
	printf("\t삭제 데이터: %c", data);
	printf("\n rear 삭제 >> ");
	data = deleteRear(DQ1);
	printDQ(DQ1);
	printf("\t\t삭제 데이터: %c", data);

	// 삽입
	printf("\n rear 삽입 D>> ");
	insertRear(DQ1, 'D');
	printDQ(DQ1);
	printf("\n front 삽입 E>> ");
	insertFront(DQ1, 'E');
	printDQ(DQ1);
	printf("\n front 삽입 F>> ");
	insertFront(DQ1, 'F');
	printDQ(DQ1);

	// 검색 
	data = peekFront(DQ1);
	printf("\n peek Front item : %c \n", data);
	data = peekRear(DQ1);
	printf(" peek Rear item : %c \n", data);

	getchar();
	return 0;
}
#endif
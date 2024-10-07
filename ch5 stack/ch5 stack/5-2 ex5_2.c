// 5-2 연결 자료구조를 이용해 연결 스택 구현하기
#if 0
#include <stdio.h>
#include "5-2 stackL.h"

int main(void)
{
	element item;
	top = NULL;		// 초기 top 상태
	printf("\n** 연결 스택 연산 **\n");
	printStack();

	push(1);		// 1 삽입
	printStack();
	push(2);		// 2 삽입
	printStack();
	push(3);		// 3 삽입
	printStack();
			
	item = peek();	// 현재 top의 원소 출력
	printStack();
	printf("peek => %d", item);

	item = pop();	// 삭제
	printStack();
	printf("\t pop  => %d", item);

	item = pop();	// 삭제
	printStack();
	printf("\t pop  => %d", item);

	item = pop();	// 삭제
	printStack();
	printf("\t pop  => %d", item);

	item = pop();	
	printStack();	// 공백인 상태

	getchar();

	return 0;
}
#endif
// 5-2 ���� �ڷᱸ���� �̿��� ���� ���� �����ϱ�
#if 0
#include <stdio.h>
#include "5-2 stackL.h"

int main(void)
{
	element item;
	top = NULL;		// �ʱ� top ����
	printf("\n** ���� ���� ���� **\n");
	printStack();

	push(1);		// 1 ����
	printStack();
	push(2);		// 2 ����
	printStack();
	push(3);		// 3 ����
	printStack();
			
	item = peek();	// ���� top�� ���� ���
	printStack();
	printf("peek => %d", item);

	item = pop();	// ����
	printStack();
	printf("\t pop  => %d", item);

	item = pop();	// ����
	printStack();
	printf("\t pop  => %d", item);

	item = pop();	// ����
	printStack();
	printf("\t pop  => %d", item);

	item = pop();	
	printStack();	// ������ ����

	getchar();

	return 0;
}
#endif
// ���� ���� ����Ʈ���� ��� ����, ����, Ž�� �ϱ�
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "4-4DoubleLinkedLinst.h"

int main()
{
	linkedList_h* DL;
	listNode* p;

	DL = createLinkedList_h();	// ���� ����Ʈ ����
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	printList(DL);
	
	printf("\n(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertNode(DL, NULL, "��");
	printList(DL);

	printf("\n(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(DL, "��");
	insertNode(DL, p, "��");
	printList(DL);

	printf("\n(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(DL, "��");
	insertNode(DL, p, "��");
	printList(DL);

	printf("\n(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(DL, "��");
	deleteNode(DL, p);
	printList(DL);

	getchar();
	return 0;
}
#endif
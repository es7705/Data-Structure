// 3-6 ���� ����Ʈ�� �̿��� ���׽� �����ϱ�
#if 0
#include <stdio.h>
#include "3-6addPoly.h"

int main()
{
	polynomial A = { 3, {4,3,5,0} };		// ���׽� A�� �ʱ�ȭ, {�ְ�����, �� ���� ��� �迭}
	polynomial B = { 4, {3,1,0,2,1} };		// ���׽� B�� �ʱ�ȭ, {�ְ�����, �� ���� ��� �迭}
	polynomial C;							// ���� ����� ������ ���׽� C

	C = addPoly(A, B);						// ���׽� A, B�� ���� ������ �����ϱ� ���� addPoly �Լ� ȣ��

	printf("\n A(x) =");	
	printPoly(A);							// ���׽� A ���

	printf("\n B(x) =");
	printPoly(B);							// ���׽� A ���

	printf("\n C(x) =");
	printPoly(C);							// ���׽� A ���

	getchar();

	return 0;
}

#endif
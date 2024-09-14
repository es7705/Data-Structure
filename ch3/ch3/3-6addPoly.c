#include "3-6addPoly.h"

polynomial addPoly(polynomial A, polynomial B)			// ���׽� �� ���� �Ű� ������ ����
{
	polynomial C;										// ���׽� ������ ��� ���׽��� ������ polynomial ����ü ���� ����

	int A_index = 0, B_index = 0, C_index = 0;			// ��� �ε��� ���� ����
	int A_degree = A.degree, B_degree = B.degree;		// ���� ���� ����
	C.degree = MAX(A.degree, B.degree);					// A�� B�� �ְ������� ���� C ���׽��� �ְ����� ����

	while(A_index <= A.degree && B_index <= B.degree)	// ���� ó�� ���� ���� �ε����� ���׽��� ���� �̳��� ����, 	
	{													// �� �� ���׽Ŀ��� ó���� ���� ���� �ִ� ���� �ݺ� ����
		if (A_degree > B_degree)						// ���׽� A, B���� ���� ó�� ���� ���� ���� �� ���׽� A�� ������ �� ũ��
		{
			C.coef[C_index++] = A.coef[A_index++];		// ���׽� A�� ���� ���� ����� ���׽� C�� ���� ���� ����� ����
			A_degree--;									// ���׽� A�� ���� ����
		}
		else if (A_degree == B_degree)					// ���׽� A, B���� ���� ó�� ���� ���� �� ������ ���� ���
		{
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];	// �� ���� ����� ���Ͽ� ���׽� C�� ���� ���� ����� ����
			A_degree--;									// ���׽� A�� ���� ���� 
			B_degree--;									// ���׽� B�� ���� ����
		}
		else											// ���׽� A, B���� ���� ó�� ���� ���� ���� �� ���׽� B�� ������ �� ũ��
		{
			C.coef[C_index++] = B.coef[B_index++];		// ���׽� A�� ���� ���� ����� ���׽� C�� ���� ���� ����� ����
			B_degree--;									// ���׽� B�� ���� ����
		}
	}
	return C;											// ���׽� ������ ��� ���׽� C�� ��ȭ
}

void printPoly(polynomial P)							
{		
	int i, degree;										// �ε��� ����, ���� ����
	degree = P.degree;									// �Ű� ������ ���� ���׽� P�� �ְ����� ���� ����

	for ( i = 0; i <= P.degree; i++)					// ���׽��� �ְ�������ŭ �ݺ�
	{
		printf("%3.0fx^%d", P.coef[i], degree--);		// ����� ���� ���
		if (i < P.degree)								// �ε��� i�� �������� ���� ���� + ���						
		{
			printf(" +");
		}
	}
	printf("\n");
}
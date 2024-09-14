#pragma once
#define MAX(a, b)	((a > b) ? a : b)	// a�� b �� �� ū ������ MAX, ���׽� C�� �ְ����� ����
#define	MAX_DEGREE 50

typedef struct                  // ����ü polynomial ����
{
	int degree;					// ���׽��� ������ ������ ����
	float coef[MAX_DEGREE];		// ���׽��� �� ���� ����� ������ 1���� ��
}polynomial;

polynomial addPoly(polynomial A, polynomial B);	// polynomial Ÿ���� ���׽� ���� �Լ�
void printPoly(polynomial P);					// ������ ���׽� ����� ����ϴ� �Լ�
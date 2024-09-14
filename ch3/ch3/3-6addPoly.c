#include "3-6addPoly.h"

polynomial addPoly(polynomial A, polynomial B)			// 다항식 두 개를 매개 변수로 받음
{
	polynomial C;										// 다항식 덧셈의 결과 다항식을 저장할 polynomial 구조체 변수 선언

	int A_index = 0, B_index = 0, C_index = 0;			// 계수 인덱스 변수 선언
	int A_degree = A.degree, B_degree = B.degree;		// 차수 변수 선언
	C.degree = MAX(A.degree, B.degree);					// A와 B의 최고차수을 비교해 C 다항식의 최고차수 결정

	while(A_index <= A.degree && B_index <= B.degree)	// 현재 처리 중인 항의 인덱스가 다항식의 차수 이내인 동안, 	
	{													// 즉 두 다항식에서 처리할 항이 남아 있는 동안 반복 수행
		if (A_degree > B_degree)						// 다항식 A, B에서 현재 처리 중인 항의 지수 중 다항식 A의 지수가 더 크면
		{
			C.coef[C_index++] = A.coef[A_index++];		// 다항식 A의 현재 항의 계수를 다항식 C의 현재 항의 계수로 저장
			A_degree--;									// 다항식 A의 다음 차수
		}
		else if (A_degree == B_degree)					// 다항식 A, B에서 현재 처리 중인 항의 두 지수가 같은 경우
		{
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];	// 두 항의 계수를 더하여 다항식 C의 현재 항의 계수로 저장
			A_degree--;									// 다항식 A의 다음 차수 
			B_degree--;									// 다항식 B의 다음 차수
		}
		else											// 다항식 A, B에서 현재 처리 중인 항의 지수 중 다항식 B의 지수가 더 크면
		{
			C.coef[C_index++] = B.coef[B_index++];		// 다항식 A의 현재 항의 계수를 다항식 C의 현재 항의 계수로 저장
			B_degree--;									// 다항식 B의 다음 차수
		}
	}
	return C;											// 다항식 덧셈의 결과 다항식 C를 반화
}

void printPoly(polynomial P)							
{		
	int i, degree;										// 인덱스 변수, 차수 변수
	degree = P.degree;									// 매개 변수로 받은 다항식 P의 최고차수 변수 저장

	for ( i = 0; i <= P.degree; i++)					// 다항식의 최고차수만큼 반복
	{
		printf("%3.0fx^%d", P.coef[i], degree--);		// 계수와 차수 출력
		if (i < P.degree)								// 인덱스 i가 차수보다 작을 때만 + 출력						
		{
			printf(" +");
		}
	}
	printf("\n");
}
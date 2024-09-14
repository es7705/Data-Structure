#pragma once
#define MAX(a, b)	((a > b) ? a : b)	// a와 b 중 더 큰 차수가 MAX, 다항식 C의 최고차항 결정
#define	MAX_DEGREE 50

typedef struct                  // 구조체 polynomial 정의
{
	int degree;					// 다항식의 차수를 저장할 변수
	float coef[MAX_DEGREE];		// 다항식의 각 항의 계수를 저장할 1차원 배
}polynomial;

polynomial addPoly(polynomial A, polynomial B);	// polynomial 타입을 다항식 덧셈 함수
void printPoly(polynomial P);					// 덧셈한 다항식 결과를 출력하는 함수
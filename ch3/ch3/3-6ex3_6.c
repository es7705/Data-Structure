// 3-6 순차 리스트를 이용해 다항식 덧셈하기
#if 0
#include <stdio.h>
#include "3-6addPoly.h"

int main()
{
	polynomial A = { 3, {4,3,5,0} };		// 다항식 A의 초기화, {최고차수, 각 항의 계수 배열}
	polynomial B = { 4, {3,1,0,2,1} };		// 다항식 B의 초기화, {최고차수, 각 항의 계수 배열}
	polynomial C;							// 덧셈 결과를 저장할 다항식 C

	C = addPoly(A, B);						// 다항식 A, B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출

	printf("\n A(x) =");	
	printPoly(A);							// 다항식 A 출력

	printf("\n B(x) =");
	printPoly(B);							// 다항식 A 출력

	printf("\n C(x) =");
	printPoly(C);							// 다항식 A 출력

	getchar();

	return 0;
}

#endif
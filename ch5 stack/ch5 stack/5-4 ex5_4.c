// 5-4 수식을 후위 표기법으로 연산하기
#if 0
#include <stdio.h>
#include "5-4 stackL.h"
#include "5-4 evalPostfix.h"

int main(void)
{
	int result;
	char* express = "35*62/-";
	printf("후위 표기식 : %s", express);

	result = evalPostfix(express);
	printf("\n연산 결과 => %d\n", result);

	getchar();

	return 0;
}
#endif
// 5-3 스택을 이용해 수식의 괄호 쌍 검사하기
#if 0
#include <stdio.h>
#include "5-3 stackL.h"
#include "5-3 testPair.h"

int main(void)
{
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);

	if (testPair(express) == 1)
		printf("\n\n수식의 괄호가 맞게 사용되었습니다!");
	else
		printf("\n\n수식의 괄호가 틀렸습니다!");

	getchar();

	return 0;
}

#endif
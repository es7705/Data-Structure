// 3-5 희소행렬의 전치 연산하기
#if 0
#include <stdio.h>
#include "3-5SmTranspose.h"

int main()
{
	term a[] = { {8,7,10}, {0,2,2}, {0,6,12}, {1,4,7}, {2,0,23}, {3,3,31}, {4,1,14}, 
				{4,5,25}, {5,6,6}, {6,0,52}, {7,4,11} };
	
	term b[sizeof(a) / sizeof(a[0])];		// 배열 원소 객수 계산, 전치행렬 b 생성
	int i;

	printf("<<희소행렬 a>>");	
	for ( i = 0; i <= a[0].value; i++)		// a[0].value : 0이 아닌 원소의 개수, 10이므로 11번 반복
	{
		printf("\n[%3d, %3d, %3d ] ", a[i].row, a[i].col, a[i].value);	// [행, 열, 원소]
	}

	smTranspose(a, b);

	printf("\n\n<<희소행렬 b>>");
	for (i = 0; i <= b[0].value; i++)		// b[0].vblue : 0이 아닌 원소의 개수, 10이므로 11번 반복
	{
		printf("\n[%3d, %3d, %3d ] ", b[i].row, b[i].col, b[i].value);	// [행, 열, 원소]
	}

	getchar();

	return 0;
}

#endif
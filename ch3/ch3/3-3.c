// 3-1 3차원 배열의 논리적, 물리적 순서 확인하기
#if 0
#include <stdio.h>

int main()
{
	int i, n = 0, * ptr;
	int sale[2][2][4] = { {{63, 84, 140, 130}, 
						{157, 209, 251, 312}}, 

						{{59, 80, 130 ,135}, 
						{149, 187, 239, 310}} };
	ptr = &sale[0][0][0];
	for ( i = 0; i < 16; i++)
	{
		printf("\n adderss : %u sale %2d = %3d", ptr, i, *ptr);
		ptr++;
	}

	getchar();
	return 0;
}

#endif
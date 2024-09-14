#include "3-5SmTranspose.h"	

void smTranspose(term a[], term b[])
{
	int m, n, v, i, j, p;				// m : 행 변수, n : 열 변수, v : 원소 변수, i : 행 인덱스, j : 열 인덱스, p : 전치행렬 b가 1행부터 시작하기 위한 변수

	m = a[0].row;						// 희소행렬 a의 행 수
	n = a[0].col;						// 희소행렬 a의 열 수
	v = a[0].value;						// 희소행렬 a에서 0이 아닌 원소 수	

	b[0].row = n;						// 전치행렬 b의 행 수
	b[0].col = m;						// 전치행렬 b의 열 수
	b[0].value = v;						// 전치행렬 b의 원소 수
		
	if (v > 0)							// 0이 아닌 원소가 있는 경우에만 전치 연산 수행
	{
		p = 1;							// 전치행렬 b의 전치 연산은 1행부터 시작
		for ( i = 0; i < n; i++)		// 희소행렬 a의 열별로 전치 반복 수행
		{
			for ( j = 0; j <= v; j++)	// 0이 아닌 원소 수에 대해서만 반복 수행
			{
				if (a[j].col == i)		// 현재 열에 속하는 원소가 있으면 b[]에 삽입, 만약 i = 0일 때 a{m, n, value}의 n값 즉 a[j].col 값이 0이면
				{						// b{n, m, value}으로 전치 연산
					b[p].row = a[j].col;// b{0, 2, 23}
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}

}
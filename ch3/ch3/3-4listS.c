#include "3-4listS.h"	

// 선형 리스트의 원소 삽입
int insertElement(int L[], int n, int x)
{
	int i, k = 0, move = 0;				// move는 자리 이동 횟수 카운터

	// 원소의 크기를 비교하여 삽입 위치 k 찾기
	for ( i = 0; i < n; i++)
	{
		if (L[i] <= x && L[i + i] > x)	// x가 L[i]의 값과 같거나 크고 L[i+1]보다 작은 위치의 인덱스 찾기
		{
			k = i + 1;
			break;
		}
	}
	if (i == n)							// 삽입 원소가 가장 큰 원소인 경우 원소의 갯수와 같은 인덱스에 추가(맨 끝에 삽입)
		k = n;

	// 마지막 원소부터 k + 1 원소까지 뒤로 자리 이동
	for ( i = n; i > k; i--)
	{
		L[i] = L[i - 1];
		move++;
	}

	L[k] = x;							// 자리 이동하여 만들 자리 k에 삽입 원소 저장
	return move;
}

// 선형 리스트의 원소 삭제
int deleteElement(int L[], int n, int x)
{
	int i, k = n, move = 0;				// move는 자리 이동 횟수 카운터
	// 원소의 크기를 비교하여 삭제 위치 k 찾기
	for ( i = 0; i < n; i++)
	{
		if (L[i] == x)					// 삭제할 데이터 x와 L[i]와 일치할 때 삭제할 원소 인덱스 k에 i 저장
		{
			k = i;
			break;
		}
	}

	if (i == n)							// 선형 리스트에서 삭제할 원소를 찾지 못했을 때 실행
	{
		move = n;
	}

	// k + 1부터 마지막 원소까지 앞으로 자리 이동
	for ( i = k; i < n - 1; i++)
	{
		L[i] = L[i + 1];				// 삭제한 원소 뒤의 원소를 앞으로 한 칸씩 이동
		move++;							// 이동 횟수 카운트
	}
	
	return move;
}
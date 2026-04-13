#pragma once
typedef struct {		// 행렬 원소를 저장하기 위한 구조체 term 정의
	int row;			// 행
	int col;			// 열
	int value;			// 값
} term;

void smTranspose(term a[], term b[]);
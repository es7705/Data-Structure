#if 0
#include <stdio.h>
#include <stdlib.h>
#include "6-4 deQue.h"

// 공백 데크를 생성하는 연산
DQueType* createDQue(void)
{
	DQueType* DQ;	// 데트 포인터 선언
	DQ = (DQueType*)malloc(sizeof(DQueType));	
	DQ->front = NULL;	// front 포인터 초기화 (데크의 앞쪽)
	DQ->rear = NULL;	// rear 포인터 초기화 (데크의 뒤쪽)
	return DQ;			// 생성된 데크 포인터 반환
}

// 데크가 공백 상태인지 검사하는 연산
int isDeQEmpty(DQueType* DQ)
{
	if (DQ->front == NULL)	// front가 NULL이면 데크가 비어있음
		return 1;			// 비어있으면 1을 반환
	else
		return 0;			// 비어있지 않으면 0을 반환
}

// 데크의 front 앞으로 원소를 삽입하는 연산
void insertFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));	// 새로운 노드를 위한 메모리 할당
	newNode->data = item;		// 노드의 데이터 필드에 item 저장
	if (isDeQEmpty(DQ))			// 데크가 비어있는 경우
	{
		DQ->front = newNode;	// front와 rear 모두 newNode를 가리킴
		DQ->rear = newNode;
		newNode->llink = NULL;	// 새로 생긴 하나의 노드이므로 왼쪽, 오른쪽 링크 필등 모드 NULL
		newNode->rlink = NULL;
	}
	else
	{
		DQ->front->llink = newNode;	// 현재 front의 왼쪽 링크를 새 노드로 설정
		newNode->rlink = DQ->front;	// 새 노드의 오른쪽 링크를 현재 front로 설정
		newNode->llink = NULL;		// 새 노드의 왼쪽에는 노드가 없으므로 NULL로 설정
		DQ->front = newNode;		// front는 새 노도를 가리킴
	}
}

// 데크의 rear 뒤로 원소를 삽입하는 연산
void insertRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));	// 새 노드를 위한 메모리 할당
	newNode->data = item;		// 노드의 데이터 필드에 item 저장
	if (isDeQEmpty(DQ))			// 데크가 공백 상태인 경우
	{
		DQ->front = newNode;	// front와 rear 모두 newNode로 설정
		DQ->rear = newNode;
		newNode->llink = NULL;	// 새 노드의 왼쪽, 오른쪽에는 노드가 없으므로 NULL로 설정
		newNode->rlink = NULL;
	}
	else
	{
		DQ->rear->rlink = newNode;	// 현재 rear의 오른쪽 링크를 새 노드로 설정
		newNode->llink = DQ->rear;	// 새 노드의 왼쪽 링크를 현재 rear로 설정
		newNode->rlink = NULL;		// 새 노드의 오른쪽에는 노드가 없으므로 NULL로 설정
		DQ->rear = newNode;			// rear은 새 노드를 가리킴
	}
}

// 데크의 front 노드를 삭제하고 반환하는 연산
element deleteFront(DQueType* DQ)
{
	DQNode* old = DQ->front;	// 삭제할 노드를 old에 저장
	element item;				// 반환할 데이터를 저장할 변수	
	if (isDeQEmpty(DQ))			// 데크가 비어있는 경우
	{
		printf("\n Linked deQue is empty! \n");		
		return;
	}
	else
	{
		item = old->data;		// 삭제할 노드의 데이터를 item에 저장
			
		if (DQ->front->rlink == NULL)	// 데크에 노드가 하나만 있는 경우
		{
			DQ->front = NULL;			// 노드를 삭제하고 나면 빈 데크가 되므로
			DQ->rear = NULL;			// front와 rear은 모두 NULL로 설정
		}
		else					// 여러 개의 노드가 있는 경우
		{
			DQ->front = DQ->front->rlink;	// front를 다음 노드로 업데이트
			DQ->front->llink = NULL;		// 가장 앞쪽의 노드가 되므로 왼쪽 링크를 NULL로 설정
		}
		free(old);		// 삭제할 노드 메모리 해제
		return item;	// 삭제한 노드의 데이터 반환
	}
}

// 데크의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType* DQ)
{
	DQNode* old = DQ->rear;	// 삭제할 노드를 old에 저장
	element item;			// 반환할 데이터를 저장할 변수
	if (isDeQEmpty(DQ))		// 데크가 비어있는 경우
	{
		printf("\n Linked deQue is empty! \n");
		return;
	}
	else
	{
		item = old->data;		// 삭제할 노드의 데이터를 item에 저장
		
		if (DQ->rear->llink == NULL)	// 데크에 노드가 하나만 있는 경우
		{
			DQ->front = NULL;			// 데크가 비어있므로
			DQ->rear = NULL;			// front와 rear는 가리킬 노드가 없음
		}
		else					// 여러 개으이 노드가 있는 경우
		{
			DQ->rear = DQ->rear->llink;	// rear를 이전 노드로 업데이트
			DQ->rear->rlink = NULL;		// rear이 가리키는 노드는 마지막 노드이므로 오른쪽 링크를 NULL로 설정
		}
		free(old);				// 삭제할 노드 메모리 해제
		return item;			// 삭제한 노드의 데이터 반환
	}
}

// 데크의 front 노드의 데이터 필드를 반환하는 연산
element peekFront(DQueType* DQ)
{
	element item;				// 반환할 데이터를 저장할 변수
	if (isDeQEmpty(DQ))			// 데크가 비어있는 경우
	{
		printf("\n Linked deQue is empty! \n");
		return;
	}
	else
	{
		item = DQ->front->data;		// front 노드의 데이터를 item에 저장
		return item;				// item 반환
	}
}

// 데크의 rear 노드의 데이터 필드를 반환하는 연산
element peekRear(DQueType* DQ)
{
	element item;		// 반환할 데이터를 저장할 변수
	if (isDeQEmpty(DQ))		// 데크가 비어있는 경우
	{
		printf("\n Linked deQue is empty! \n");
		return;
	}
	else
	{
		item = DQ->rear->data;	// rear 노드의 데이터를 item에 저장
		return item;			// item 반환
	}
}

// 데크의 front 노드부터 rear 노드까지 출력하는 연산
void printDQ(DQueType* DQ)
{
	DQNode* temp = DQ->front;	// 임시 포인터에 front를 저장
	printf("DeQue : [");		// 데크 출력 시작
	while (temp)				// 데크의 모든 노드를 순회하여 데이터 출력
	{
		printf("%3c", temp->data);	// 현재 노드의 데이터 출력
		temp = temp->rlink;			// 다음 노드로 이동
	}
	printf(" ] ");
}
#endif
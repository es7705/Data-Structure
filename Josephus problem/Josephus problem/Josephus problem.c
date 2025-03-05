// 요세푸스 문제
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node
{
	int value;
	struct node* next;
}node;

node* head = NULL;

node* createNode(int value);
void builCircularQueue(int n);
int josephus(int n, int k);

int main()
{
	int n, k;

	printf("\n\t\t*** 요세푸스 문제(Josephus problem) ***\n\n");
	printf("\t\t처형을 기다리는 사람은 몇 명 입니까? ");
	scanf("%d", &n);

	printf("\n\n\t\t1번~%d번의 처형 대기자가 있습니다.\n", n);
	printf("\t\t몇 번째 사람을 처형 시키겠습니까? ");
	scanf("%d", &k);

	printf("\n\n\t\t생존자는 %d번 입니다. \n", josephus(n, k));

	return 0;
}

node* createNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node));	 // 구조체 변수(노드) 생성
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void builCircularQueue(int n)
{
	node* tail;
	head = createNode(1);
	tail = head;

	for (int i = 2; i <= n; i++)
	{
		tail->next = createNode(i);
		tail = tail->next;
	}

	// 원형큐를 만들기 위한 코드
	tail->next = head;
}

int josephus(int n, int k)
{
	node* curNode, *delNode;
	builCircularQueue(n);

	curNode = head;		// 현재 가리키는 노드의 초기값은 head

	while (n > 1)		// 한 명만 남을 때까지
	{
		// 삭제할 노드 이전에서 멈춤
		for (int i = 0; i < k - 2; i++)
		{
			curNode = curNode->next;
		}
		delNode = curNode->next;

		// 재연결
		curNode->next = delNode->next;
		if (delNode == head)
		{
			head = head->next;
		}
		free(delNode);	// 노드 삭제
		n--;	// 노드의 개수를 1감소
		curNode = curNode->next;
	}
	return curNode->value;
}

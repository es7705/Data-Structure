// �似Ǫ�� ����
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

	printf("\n\t\t*** �似Ǫ�� ����(Josephus problem) ***\n\n");
	printf("\t\tó���� ��ٸ��� ����� �� �� �Դϱ�? ");
	scanf("%d", &n);

	printf("\n\n\t\t1��~%d���� ó�� ����ڰ� �ֽ��ϴ�.\n", n);
	printf("\t\t�� ��° ����� ó�� ��Ű�ڽ��ϱ�? ");
	scanf("%d", &k);

	printf("\n\n\t\t�����ڴ� %d�� �Դϴ�. \n", josephus(n, k));

	return 0;
}

node* createNode(int value)
{
	node* newNode = (node*)malloc(sizeof(node));	 // ����ü ����(���) ����
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

	// ����ť�� ����� ���� �ڵ�
	tail->next = head;
}

int josephus(int n, int k)
{
	node* curNode, *delNode;
	builCircularQueue(n);

	curNode = head;		// ���� ����Ű�� ����� �ʱⰪ�� head

	while (n > 1)		// �� �� ���� ������
	{
		// ������ ��� �������� ����
		for (int i = 0; i < k - 2; i++)
		{
			curNode = curNode->next;
		}
		delNode = curNode->next;

		// �翬��
		curNode->next = delNode->next;
		if (delNode == head)
		{
			head = head->next;
		}
		free(delNode);	// ��� ����
		n--;	// ����� ������ 1����
		curNode = curNode->next;
	}
	return curNode->value;
}

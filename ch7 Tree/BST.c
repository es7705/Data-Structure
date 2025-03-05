// 이진 검색 트리 BST
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	int value;	// 값
	struct treeNode* left;	// 왼쪽 자식 노드 포인터(8바이트)
	struct treeNode* right;	// 오른쪽 자식 노드 포인터(8바이트)
}treeNode;

treeNode* addNode(treeNode* t, int data);
void displayInorder(treeNode* t);
treeNode* searchNode(treeNode* t, int target);
treeNode* getMaxNode(treeNode* t);
treeNode* getMinNode(treeNode* t);
treeNode* removeNode(treeNode* t, int target);

int main()
{
	treeNode* root = NULL;		// 루트(최상의 노드)의 주소를 저장할 포인터(8바이트)
								// NULL은 아직 생성된 노드가 없다는 뜻
	treeNode* findNode;			// 검색하여 찾은 노드의 주소를 저장할 포인터
	int choice;
	int data;
	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Binary Search Tree(BST) ***\n\n");
		printf("1. 노드 삽입\n");
		printf("2. 노드 삭제\n");
		printf("3. 노드 검색\n");
		printf("4. 최댓값 구하기\n");
		printf("5. 최솟값 구하기\n");
		printf("6. 이진 검색 트리 출력(중위순회)\n");
		printf("0. 프로그램 종료\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
		
		switch (choice)
		{
		case 1:	// 노드 삽입
			printf("\n\n삽입할 정수 입력 : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			//addNode함수 : 노드를 생성한 후, 루트의 주소를 리턴
			root = addNode(root, data);
			break;

		case 2:	// 노드 삭제
			printf("\n\n삭제할 노드의 값 입력 : ");
			scanf("%d", &data);

			root = removeNode(root, data);
			break;

		case 3:	// 노드 검색
			printf("\n\n검색할 정수 입력 : ");
			scanf("%d", &data);		// 검색할 값 입력

			findNode = searchNode(root, data); 

			if (findNode == NULL)
				printf("\n\n\t\t찾는 값이 없습니다.\n");
			else
				printf("\n\n\t\t검색한 값은 존재합니다.\n");	
			break;

		case 4:	// 최댓값 구하기
			findNode = getMaxNode(root);
			if(findNode != NULL)
				printf("\n\n\t\t최댓값은 %d입니다.\n", findNode->value);
			break;

		case 5:	// 최솟값 구하기
			findNode = getMinNode(root);
			if (findNode != NULL)
				printf("\n\n\t\t최솟값은 %d입니다.\n", findNode->value);
			break;

		case 6: // 이진 검색 트리 출력(중위순회)
			printf("\n\n중위순회 출력(오름차순) : ");
			displayInorder(root);
			break;

		case 0:	// 프로그램 종료
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

treeNode* addNode(treeNode* t, int data)
{
	if (t == NULL)		// 트리가 비어있으면 새 노드 생성
	{
		t= (treeNode*)malloc(sizeof(treeNode));	// 트리 노드 생성
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}

	else if(t->value > data)		// 삽입할 정수가 더 작은 경우
	{
		t->left = addNode(t->left, data);	// 왼쪽에 삽입
	}

	else if (t->value < data)		// 삽입할 정수가 더 큰 경우
	{
		t->right = addNode(t->right, data); // 오른쪽에 삽입
	}

	else
	{
		printf("\n\n\t\t중복값은 삽입할 수 없습니다.\n");
	}
	return t;
}

void displayInorder(treeNode* t)
{
	if (t != NULL)
	{
		//printf("%d ", t->value);	// 전위순회
		displayInorder(t->left);			// 왼쪽 서브트리 방문
		//printf("(값 : %d, 노드의 주소 : %p) ", t->value, t);	// 중위순회
		printf("%d ", t->value);	// 중위순회
		displayInorder(t->right);			// 오른쪽 서브트리 방문
		//printf("%d ", t->value);	// 후위순회
	}
}

treeNode* searchNode(treeNode* t, int target)
{
	if (t == NULL)		// 트리가 비어 있으면 NULL 반환, 찾는 값이 없는 경우
		return NULL;
	if (t->value == target)
		return t;		// 찾는 값 노드의 주소를 리턴
	else if (t->value > target)	// 더 작으면 왼쪽으로 이동
		return searchNode(t->left, target);		
	else if (t->value < target)	// 더 크면 오른쪽으로 이동
		return searchNode(t->right, target);
}
treeNode* getMaxNode(treeNode* t)
{
	if (t == NULL)		// 노드가 생성되지 않은 경우
		return NULL;

	if (t->right != NULL)
	{
		return getMaxNode(t->right);
	}

	return t;	// 최댓값 노드의 주소를 리턴
}

treeNode* getMinNode(treeNode* t)
{
	if (t == NULL)		// 노드가 생성되지 않은 경우
		return NULL;

	if (t->left != NULL)
	{
		return getMinNode(t->left);
	}

	return t;	// 최솟값 노드의 주소를 리턴
}

treeNode* removeNode(treeNode* t, int target)
{
	treeNode* temp;

	if (t != NULL)
	{
		if (t->value == target)
		{
			// 노드를 삭제하는 코드
			if (t->left == NULL && t->right == NULL) // case 1. 자식 노드가 없는 경우
			{
				free(t);	// 노드 제거
				return NULL;
			}
			else if (t->left == NULL)	// case 2. 오른쪽 자식 노드만 있는 경우
			{
				temp = t->right;
				free(t);
				return temp;			// 오른쪽 자식 노드의 값을 리턴
			}
			else if (t->right == NULL)	// case 3. 왼쪽 자식 노드만 있는 경우
			{
				temp = t->left;
				free(t);
				return temp;			// 왼쪽 자식 노드의 값을 리턴
			}
			else						// case 4. 자식 노드가 둘 다 있는 경우
			{
				temp = getMaxNode(t->left); // 왼쪽 자식 노드 중 최댓값을 찾아
				t->value = temp->value;	// 왼쪽 자식 중 최댓값을 삭제 노드로 대입
				t->left = removeNode(t->left, temp->value);	// 다시 제거하러 출발
			}
		}
	}
	else if (t->value > target)
	{
		t->left = removeNode(t->left, target);				// 재귀호출
	}
	else
	{
		t->right = removeNode(t->right, target);			// 재귀호출
	}

	return t; 
}
#endif



// ���� �˻� Ʈ�� BST
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	int value;	// ��
	struct treeNode* left;	// ���� �ڽ� ��� ������(8����Ʈ)
	struct treeNode* right;	// ������ �ڽ� ��� ������(8����Ʈ)
}treeNode;

treeNode* addNode(treeNode* t, int data);
void displayInorder(treeNode* t);
treeNode* searchNode(treeNode* t, int target);
treeNode* getMaxNode(treeNode* t);
treeNode* getMinNode(treeNode* t);
treeNode* removeNode(treeNode* t, int target);

int main()
{
	treeNode* root = NULL;		// ��Ʈ(�ֻ��� ���)�� �ּҸ� ������ ������(8����Ʈ)
								// NULL�� ���� ������ ��尡 ���ٴ� ��
	treeNode* findNode;			// �˻��Ͽ� ã�� ����� �ּҸ� ������ ������
	int choice;
	int data;
	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Binary Search Tree(BST) ***\n\n");
		printf("1. ��� ����\n");
		printf("2. ��� ����\n");
		printf("3. ��� �˻�\n");
		printf("4. �ִ� ���ϱ�\n");
		printf("5. �ּڰ� ���ϱ�\n");
		printf("6. ���� �˻� Ʈ�� ���(������ȸ)\n");
		printf("0. ���α׷� ����\n");
		printf("\n�޴� ���� : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
		
		switch (choice)
		{
		case 1:	// ��� ����
			printf("\n\n������ ���� �Է� : ");
			scanf("%d", &data);
			while (getchar() != '\n');
			//addNode�Լ� : ��带 ������ ��, ��Ʈ�� �ּҸ� ����
			root = addNode(root, data);
			break;

		case 2:	// ��� ����
			printf("\n\n������ ����� �� �Է� : ");
			scanf("%d", &data);

			root = removeNode(root, data);
			break;

		case 3:	// ��� �˻�
			printf("\n\n�˻��� ���� �Է� : ");
			scanf("%d", &data);		// �˻��� �� �Է�

			findNode = searchNode(root, data); 

			if (findNode == NULL)
				printf("\n\n\t\tã�� ���� �����ϴ�.\n");
			else
				printf("\n\n\t\t�˻��� ���� �����մϴ�.\n");	
			break;

		case 4:	// �ִ� ���ϱ�
			findNode = getMaxNode(root);
			if(findNode != NULL)
				printf("\n\n\t\t�ִ��� %d�Դϴ�.\n", findNode->value);
			break;

		case 5:	// �ּڰ� ���ϱ�
			findNode = getMinNode(root);
			if (findNode != NULL)
				printf("\n\n\t\t�ּڰ��� %d�Դϴ�.\n", findNode->value);
			break;

		case 6: // ���� �˻� Ʈ�� ���(������ȸ)
			printf("\n\n������ȸ ���(��������) : ");
			displayInorder(root);
			break;

		case 0:	// ���α׷� ����
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}

treeNode* addNode(treeNode* t, int data)
{
	if (t == NULL)		// Ʈ���� ��������� �� ��� ����
	{
		t= (treeNode*)malloc(sizeof(treeNode));	// Ʈ�� ��� ����
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}

	else if(t->value > data)		// ������ ������ �� ���� ���
	{
		t->left = addNode(t->left, data);	// ���ʿ� ����
	}

	else if (t->value < data)		// ������ ������ �� ū ���
	{
		t->right = addNode(t->right, data); // �����ʿ� ����
	}

	else
	{
		printf("\n\n\t\t�ߺ����� ������ �� �����ϴ�.\n");
	}
	return t;
}

void displayInorder(treeNode* t)
{
	if (t != NULL)
	{
		//printf("%d ", t->value);	// ������ȸ
		displayInorder(t->left);			// ���� ����Ʈ�� �湮
		//printf("(�� : %d, ����� �ּ� : %p) ", t->value, t);	// ������ȸ
		printf("%d ", t->value);	// ������ȸ
		displayInorder(t->right);			// ������ ����Ʈ�� �湮
		//printf("%d ", t->value);	// ������ȸ
	}
}

treeNode* searchNode(treeNode* t, int target)
{
	if (t == NULL)		// Ʈ���� ��� ������ NULL ��ȯ, ã�� ���� ���� ���
		return NULL;
	if (t->value == target)
		return t;		// ã�� �� ����� �ּҸ� ����
	else if (t->value > target)	// �� ������ �������� �̵�
		return searchNode(t->left, target);		
	else if (t->value < target)	// �� ũ�� ���������� �̵�
		return searchNode(t->right, target);
}
treeNode* getMaxNode(treeNode* t)
{
	if (t == NULL)		// ��尡 �������� ���� ���
		return NULL;

	if (t->right != NULL)
	{
		return getMaxNode(t->right);
	}

	return t;	// �ִ� ����� �ּҸ� ����
}

treeNode* getMinNode(treeNode* t)
{
	if (t == NULL)		// ��尡 �������� ���� ���
		return NULL;

	if (t->left != NULL)
	{
		return getMinNode(t->left);
	}

	return t;	// �ּڰ� ����� �ּҸ� ����
}

treeNode* removeNode(treeNode* t, int target)
{
	treeNode* temp;

	if (t != NULL)
	{
		if (t->value == target)
		{
			// ��带 �����ϴ� �ڵ�
			if (t->left == NULL && t->right == NULL) // case 1. �ڽ� ��尡 ���� ���
			{
				free(t);	// ��� ����
				return NULL;
			}
			else if (t->left == NULL)	// case 2. ������ �ڽ� ��常 �ִ� ���
			{
				temp = t->right;
				free(t);
				return temp;			// ������ �ڽ� ����� ���� ����
			}
			else if (t->right == NULL)	// case 3. ���� �ڽ� ��常 �ִ� ���
			{
				temp = t->left;
				free(t);
				return temp;			// ���� �ڽ� ����� ���� ����
			}
			else						// case 4. �ڽ� ��尡 �� �� �ִ� ���
			{
				temp = getMaxNode(t->left); // ���� �ڽ� ��� �� �ִ��� ã��
				t->value = temp->value;	// ���� �ڽ� �� �ִ��� ���� ���� ����
				t->left = removeNode(t->left, temp->value);	// �ٽ� �����Ϸ� ���
			}
		}
	}
	else if (t->value > target)
	{
		t->left = removeNode(t->left, target);				// ���ȣ��
	}
	else
	{
		t->right = removeNode(t->right, target);			// ���ȣ��
	}

	return t; 
}
#endif



#if 0
#include <stdio.h>
#include <stdlib.h>
#include "7-1 traversalIBT.h"

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNdoe* makeRootNode(element data, treeNdoe* leftNode, treeNdoe* rightNode)
{
	treeNdoe* root = (treeNdoe*)malloc(sizeof(treeNdoe));	// 새로운 트로 노드를 위한 메모리 할당
	root->data = data;			// 루트 노트의 데이터 필드에 주어진 데이터 저장
	root->right = rightNode;	// 왼쪽 서브 트리 노드와 연결
	root->left = leftNode;		// 오른쪽 서브 트리 노드와 연결
	return root;				// 생성된 루트 노드의 포인터 반환
}

// 이진 트리에 대한 전위 순회 연산
void preorder(treeNdoe* root)
{
	if (root)						// 현재 노드가 NULL이 아닐 경우
	{
		printf("%c", root->data);	// 현재 노드의 데이터를 출력 (작업D)
		preorder(root->left);		// 왼쪽 서브 트리에 대해 전위 순회 (작업L)
		preorder(root->right);		// 오른쪽 서브 트레에 대해 전위 순회 (작업R)
	}
}

// 이진 트리에 대한 중위 순회 연산
void inorder(treeNdoe* root)
{
	if (root)						// 현재 노드가 NULL이 아닐 경우
	{
		inorder(root->left);		// 왼쪽 서브 트리에 대해 중위 순회 (작업L)
		printf("%c", root->data);	// 현재 노드의 데이터를 출력 (작업D)
		inorder(root->right);		// 오른쪽 서브 트리에 대해 중위 순회 (작업R)
	}
}

// 이진 트리에 대한 후위 순회 연산
void postorder(treeNdoe* root)
{
	if (root)						// 현재 노드가 NULL이 아닐 경우
	{
		postorder(root->left);		// 왼쪽 서브 트리에 대해 후위 순회 (작업L)
		postorder(root->right);		// 오른쪽 서브 트리에 대해 후위 순회 (작업R)
		printf("%c", root->data);	// 현재 노드의 데이터를 출력 (작업D)
	}
}
#endif



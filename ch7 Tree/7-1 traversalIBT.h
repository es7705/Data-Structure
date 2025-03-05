#if 0
#pragma once
typedef char element;

typedef struct treeNode			// 연결 자료구조로 구성하기 위해 트리의 노드 저으이
{
	element data;				// 데이터를 저장하는 데이터 필드
	struct treeNode* left;		// 왼쪽 서브 트리에 대한 링크 필드
	struct treeNode* right;		// 오른쪽 서브 트리에 대한 링크 필드
}treeNdoe;

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNdoe* makeRootNode(element data, treeNdoe* leftNode, treeNdoe* rightNode);
void preorder(treeNdoe* root);	// 이진 트리에 대한 전위 순회 연산
void inorder(treeNdoe* root);	// 이진 트리에 대한 중위 순회 연산
void postorder(treeNdoe* root); // 이진 트리에 대한 후위 순회 연산
#endif
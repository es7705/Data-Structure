#if 0
#pragma once
int FolderSize;

typedef struct treeNode
{
	int size;					// ������ �ʵ�
	struct treeNode* left;		// ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode* right;		// ������ ���� Ʈ���� ���� ��ũ �ʵ�
}treeNode;

treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode);
int postorder_FolderSize(treeNode* root);
#endif
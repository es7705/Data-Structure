#if 0
#pragma once
typedef char element;

typedef struct treeNode			// ���� �ڷᱸ���� �����ϱ� ���� Ʈ���� ��� ������
{
	element data;				// �����͸� �����ϴ� ������ �ʵ�
	struct treeNode* left;		// ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode* right;		// ������ ���� Ʈ���� ���� ��ũ �ʵ�
}treeNdoe;

// data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeNdoe* makeRootNode(element data, treeNdoe* leftNode, treeNdoe* rightNode);
void preorder(treeNdoe* root);	// ���� Ʈ���� ���� ���� ��ȸ ����
void inorder(treeNdoe* root);	// ���� Ʈ���� ���� ���� ��ȸ ����
void postorder(treeNdoe* root); // ���� Ʈ���� ���� ���� ��ȸ ����
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "7-1 traversalIBT.h"

// data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeNdoe* makeRootNode(element data, treeNdoe* leftNode, treeNdoe* rightNode)
{
	treeNdoe* root = (treeNdoe*)malloc(sizeof(treeNdoe));	// ���ο� Ʈ�� ��带 ���� �޸� �Ҵ�
	root->data = data;			// ��Ʈ ��Ʈ�� ������ �ʵ忡 �־��� ������ ����
	root->right = rightNode;	// ���� ���� Ʈ�� ���� ����
	root->left = leftNode;		// ������ ���� Ʈ�� ���� ����
	return root;				// ������ ��Ʈ ����� ������ ��ȯ
}

// ���� Ʈ���� ���� ���� ��ȸ ����
void preorder(treeNdoe* root)
{
	if (root)						// ���� ��尡 NULL�� �ƴ� ���
	{
		printf("%c", root->data);	// ���� ����� �����͸� ��� (�۾�D)
		preorder(root->left);		// ���� ���� Ʈ���� ���� ���� ��ȸ (�۾�L)
		preorder(root->right);		// ������ ���� Ʈ���� ���� ���� ��ȸ (�۾�R)
	}
}

// ���� Ʈ���� ���� ���� ��ȸ ����
void inorder(treeNdoe* root)
{
	if (root)						// ���� ��尡 NULL�� �ƴ� ���
	{
		inorder(root->left);		// ���� ���� Ʈ���� ���� ���� ��ȸ (�۾�L)
		printf("%c", root->data);	// ���� ����� �����͸� ��� (�۾�D)
		inorder(root->right);		// ������ ���� Ʈ���� ���� ���� ��ȸ (�۾�R)
	}
}

// ���� Ʈ���� ���� ���� ��ȸ ����
void postorder(treeNdoe* root)
{
	if (root)						// ���� ��尡 NULL�� �ƴ� ���
	{
		postorder(root->left);		// ���� ���� Ʈ���� ���� ���� ��ȸ (�۾�L)
		postorder(root->right);		// ������ ���� Ʈ���� ���� ���� ��ȸ (�۾�R)
		printf("%c", root->data);	// ���� ����� �����͸� ��� (�۾�D)
	}
}
#endif



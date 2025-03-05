#if 1
#pragma once
typedef struct treeThNode		// ������ ���� Ʈ���� ��� ����
{
	char data;						// ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeThreadNode* left;	// ������ ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeThreadNode* right;	// �ļ��ڿ� ���� ������ �±� �ʵ�
	int isThreadRight;
}treeThNode;

treeThNode* makeRootThNode(char data, treeThNode* leftNode, treeThNode* rightNode, int isThreadRight);
treeThNode* findThreadSuccessor(treeThNode* p);
void threadInorder(treeThNode* root);
#endif

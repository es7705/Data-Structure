// 7-1 ���� Ʈ�� ��ȸ�ϱ�
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "7-1 traversalIBT.h"

int main()
{
	// (A*B-C/D) ���� ���� Ʈ�� �����
	treeNdoe* n7 = makeRootNode('D', NULL, NULL);
	treeNdoe* n6 = makeRootNode('C', NULL, NULL);
	treeNdoe* n5 = makeRootNode('B', NULL, NULL);
	treeNdoe* n4 = makeRootNode('A', NULL, NULL);
	treeNdoe* n3 = makeRootNode('/', n6, n7);
	treeNdoe* n2 = makeRootNode('*', n4, n5);
	treeNdoe* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder : ");		// ���� ��ȸ
	preorder(n1);

	printf("\n inorder : ");		// ���� ��ȸ
	inorder(n1);

	printf("\n postorder : ");		// ���� ��ȸ
	postorder(n1);

	getchar();

	return 0;
}

#endif
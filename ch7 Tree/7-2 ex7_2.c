// ���� Ʈ���� ���� ��ȸ�� �̿��� ���� �뷮 ����ϱ�
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "7-2 folderSize.h"

int main()
{
	// ���� Ʈ�� �����ϱ�
	treeNode* F11 = makeRootNode(120, NULL, NULL);		// ����
	treeNode* F10 = makeRootNode(55, NULL, NULL);		// ������
	treeNode* F9 = makeRootNode(100, NULL, NULL);		// Java ���α׷�
	treeNode* F8 = makeRootNode(200, NULL, NULL);		// C ���α׷�
	treeNode* F7 = makeRootNode(68, F10, F11);			// �׸�
	treeNode* F6 = makeRootNode(40, NULL, NULL);		// ����
	treeNode* F5 = makeRootNode(15, NULL, NULL);		// �ڷ�
	treeNode* F4 = makeRootNode(2, F8, F9);				// ���α׷�
	treeNode* F3 = makeRootNode(10, F6, F7);			// D ����̺�
	treeNode* F2 = makeRootNode(0, F4, F5);				// C ����̺�
	treeNode* F1 = makeRootNode(0, F2, F3);				// �� ��ǻ��

	FolderSize = 0;
	printf("\n\n C:\\�� �뷮 : %d M \n", postorder_FolderSize(F2));

	FolderSize = 0;
	printf("\n D:\\�� �뷮 : %d M \n", postorder_FolderSize(F3));

	FolderSize = 0;
	printf("\n �� ��ǻ���� ��ü �뷮 : %d M \n", postorderS_FolderSize(F1));

	getchar();
	return 0;
}

#endif
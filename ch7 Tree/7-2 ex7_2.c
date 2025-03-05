// 이진 트리의 후위 순회를 이용해 폴더 용량 계산하기
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "7-2 folderSize.h"

int main()
{
	// 이진 트리 생성하기
	treeNode* F11 = makeRootNode(120, NULL, NULL);		// 사진
	treeNode* F10 = makeRootNode(55, NULL, NULL);		// 동영상
	treeNode* F9 = makeRootNode(100, NULL, NULL);		// Java 프로그램
	treeNode* F8 = makeRootNode(200, NULL, NULL);		// C 프로그램
	treeNode* F7 = makeRootNode(68, F10, F11);			// 그림
	treeNode* F6 = makeRootNode(40, NULL, NULL);		// 음악
	treeNode* F5 = makeRootNode(15, NULL, NULL);		// 자료
	treeNode* F4 = makeRootNode(2, F8, F9);				// 프로그램
	treeNode* F3 = makeRootNode(10, F6, F7);			// D 드라이브
	treeNode* F2 = makeRootNode(0, F4, F5);				// C 드라이브
	treeNode* F1 = makeRootNode(0, F2, F3);				// 내 컴퓨터

	FolderSize = 0;
	printf("\n\n C:\\의 용량 : %d M \n", postorder_FolderSize(F2));

	FolderSize = 0;
	printf("\n D:\\의 용량 : %d M \n", postorder_FolderSize(F3));

	FolderSize = 0;
	printf("\n 내 컴퓨터의 전체 용량 : %d M \n", postorderS_FolderSize(F1));

	getchar();
	return 0;
}

#endif
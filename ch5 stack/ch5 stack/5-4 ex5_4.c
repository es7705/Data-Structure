// 5-4 ������ ���� ǥ������� �����ϱ�
#if 0
#include <stdio.h>
#include "5-4 stackL.h"
#include "5-4 evalPostfix.h"

int main(void)
{
	int result;
	char* express = "35*62/-";
	printf("���� ǥ��� : %s", express);

	result = evalPostfix(express);
	printf("\n���� ��� => %d\n", result);

	getchar();

	return 0;
}
#endif
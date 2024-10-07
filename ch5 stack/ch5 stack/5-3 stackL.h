#if 0
#pragma once
#ifndef stackL__H_
#define stackL__H_
typedef char element;		// ���� ����(element)�� �ڷ����� char�� ����

typedef struct stackNode
{
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;	// ������ top ��带 �����ϱ� ���� ������ top ����

int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

#endif // !stackL__H_
#endif
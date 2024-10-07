#if 1
#include <stdio.h>
#include "5-1 stackS.h"

int top = -1;   

// ������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty(void)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// ������ ��ȭ �������� Ȯ���ϴ� ����
int isStackFull(void)
{   
    if (top == STACK_SIZE -1)      // ��ȭ ����
        return 1;
    else
        return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item)
{
    if (isStackFull())           // ������ ��ȭ ������ ���
    {
        printf("\n\n Stack is FULL! \n");
        return;
    }
    else
        stack[++top] = item;    // top�� ������Ų �� top�� ���� ����
}

// ���� top���� ���Ҹ� �����ϴ� ����
element pop(void)
{
    if (isStackEmpty())         // ������ ���� ������ ���
    {
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else
        return stack[top--];    // ���� top�� ���Ҹ� ������ �� top ����
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek(void)
{
    if (isStackEmpty())
    {
        printf("\n\n Stack is Empty !\n");
        return 0;
    }
    else
        return stack[top];      // ���� top�� ���� Ȯ��
}   

//  ���� ���Ҹ� ����ϴ� ����
void printStack(void)
{
    int i;
    printf("\n STACK [ ");
    for ( i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("] ");
}
#endif



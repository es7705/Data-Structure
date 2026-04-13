#include <stdio.h>
#include "5-1 stackS.h"

int top = -1;   

// 스택이 공백 상택인지 확인하는 연산
int isStackEmpty(void)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// 스택이 포화 상택인지 확인하는 연산
int isStackFull(void)
{   
    if (top == STACK_SIZE -1)      // 포화 상태
        return 1;
    else
        return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item)
{
    if (isStackFull())           // 스택이 포화 상태인 경우
    {
        printf("\n\n Stack is FULL! \n");
        return;
    }
    else
        stack[++top] = item;    // top를 증가시킨 후 top에 원소 삽입
}

// 스택 top에서 원소를 삭제하는 연산
element pop(void)
{
    if (isStackEmpty())         // 스택이 공백 상태인 경우
    {
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else
        return stack[top--];    // 현재 top의 원소를 삭제한 후 top 감수
}

// 스택의 top 원소를 검색하는 연산
element peek(void)
{
    if (isStackEmpty())
    {
        printf("\n\n Stack is Empty !\n");
        return 0;
    }
    else
        return stack[top];      // 현재 top의 원소 확인
}   

//  스택 원소를 출력하는 연산
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




#if 0
#include <stdio.h>
#include <string.h> 
#include "5-3 stackL.h"
#include "5-3 testPair.h"

// 수식의 괄호를 검사하는 연산
int testPair(char* exp)
{
    char symbol, open_pair; // symbol : 현재 읽과 있는 괄호, open_pair : 열린 괄호를 저장할 변수
    // char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
    int i, length = strlen(exp);
    top = NULL; // 스택의 초기화, 스택의 top 포인터를 NULL로 설정하여 비어 있는 상태로 초기화
    
    for ( i = 0; i < length; i++)   //  수식 길이만큼 반복
    {
        symbol = exp[i];            // 현재 문자를 저장

        // 현재 문자가 어떤 괄호인지 판단
        switch (symbol)
        {
            // (1) 왼쪽 괄호는 스택 삽입
        case '(':
        case '{':
        case '[':
            push(symbol);   // 스택에 열림 괄호를 삽입
            break;
            // (2) 오른쪽 괄호를 읽으면,
        case ')':
        case '}':
        case ']':
            if (isStackEmpty())
                return 0;   // 스택이 비어있다면 괄호 쌍이 틀림을 의미하므로 0 반환
            else
            {
                // (2)-1 스택에서 마지막으로 읽은 괄호를 꺼냄
                open_pair = pop();

                // 열린 괄호와 현재 읽고 있는 오른쪽 괄호가 쌍이 맞는지 확인
                if ((open_pair == '(' && symbol != ')') || (open_pair == '[' && symbol != ']') || (open_pair == '{' && symbol != '}'))
                {
                    // (2)-3 괄호 쌍이 틀리면 수식 오류
                    return 0;   // 0 반환하여 괄호 쌍이 맞지 않음을 알림
                }   
                // (2)-4 괄호 쌍이 맞으면 다음 symbol 검사를 계속함
                else
                    break;  // 다음 문자로 진행
            }
        }
    }

    // 수식 검사를 마친 후 스택이 공백인지 확인
    if (top == NULL)    // 수식 검사를 마친 후 스택이 공백이면 1을 반환
        return 1;       // 1 반환하여 올바른 괄호 쌍임을 알림
    else                // 공백이 아니면 0을 반환(수식 괄호 틀림)
        return 0;       // 0 반환하여 괄호 쌍이 틀림을 알림    
}
#endif
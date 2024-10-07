#if 0
#include <string.h>
#include "5-4 stackL.h"
#include "5-4 evalPostfix.h"

// 후위 표기법 수식을 계산하는 연산
element evalPostfix(char* exp)
{
    int opr1, opr2, value, i = 0;
    // char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
    int length = strlen(exp);   // 입력된 후위 수식의 길이를 계산
    char symbol;    // 현재 처리 중인 기호(숫자 또는 연산자)

    top = NULL;     // 스택 초기화

    // 후위 수식의 각 문자에 대해 반복
    for ( i = 0; i < length; i++)
    {
        symbol = exp[i];    // 현재 문자 저장

        // 현재 문자가 연산자가 아닐 경우 (숫자일 경우)
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
        {
            value = symbol - '0';   // 문자형 숫자를 정수형으로 변환
            push(value);            // 스택에 숫자 푸시
        }   
        else    // 현재 문자가 연산자일 경우
        {
            opr2 = pop();   // 스택에서 두 번째 피연산자 팝
            opr1 = pop();   // 스택에서 첫 번째 피연산자 팝

            // 변수 opr1과 opr2에 대해 symbol에 저장된 연산자를 연산
            switch (symbol)
            {
            case '+': push(opr1 + opr2);
                break;
            case '-': push(opr1 - opr2);
                break;
            case '*': push(opr1 * opr2);
                break;
            case '/': push(opr1 / opr2);
                break;
            }
        }
    }
    // 수식 exp에 대한 처리를 마친 후 스택에 남아 있는 결괏값을 pop하여 반환
    return pop();
}
#endif
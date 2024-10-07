#if 0
#include <stdio.h>
#include <string.h> 
#include "5-3 stackL.h"
#include "5-3 testPair.h"

// ������ ��ȣ�� �˻��ϴ� ����
int testPair(char* exp)
{
    char symbol, open_pair; // symbol : ���� �а� �ִ� ��ȣ, open_pair : ���� ��ȣ�� ������ ����
    // char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
    int i, length = strlen(exp);
    top = NULL; // ������ �ʱ�ȭ, ������ top �����͸� NULL�� �����Ͽ� ��� �ִ� ���·� �ʱ�ȭ
    
    for ( i = 0; i < length; i++)   //  ���� ���̸�ŭ �ݺ�
    {
        symbol = exp[i];            // ���� ���ڸ� ����

        // ���� ���ڰ� � ��ȣ���� �Ǵ�
        switch (symbol)
        {
            // (1) ���� ��ȣ�� ���� ����
        case '(':
        case '{':
        case '[':
            push(symbol);   // ���ÿ� ���� ��ȣ�� ����
            break;
            // (2) ������ ��ȣ�� ������,
        case ')':
        case '}':
        case ']':
            if (isStackEmpty())
                return 0;   // ������ ����ִٸ� ��ȣ ���� Ʋ���� �ǹ��ϹǷ� 0 ��ȯ
            else
            {
                // (2)-1 ���ÿ��� ���������� ���� ��ȣ�� ����
                open_pair = pop();

                // ���� ��ȣ�� ���� �а� �ִ� ������ ��ȣ�� ���� �´��� Ȯ��
                if ((open_pair == '(' && symbol != ')') || (open_pair == '[' && symbol != ']') || (open_pair == '{' && symbol != '}'))
                {
                    // (2)-3 ��ȣ ���� Ʋ���� ���� ����
                    return 0;   // 0 ��ȯ�Ͽ� ��ȣ ���� ���� ������ �˸�
                }   
                // (2)-4 ��ȣ ���� ������ ���� symbol �˻縦 �����
                else
                    break;  // ���� ���ڷ� ����
            }
        }
    }

    // ���� �˻縦 ��ģ �� ������ �������� Ȯ��
    if (top == NULL)    // ���� �˻縦 ��ģ �� ������ �����̸� 1�� ��ȯ
        return 1;       // 1 ��ȯ�Ͽ� �ùٸ� ��ȣ ������ �˸�
    else                // ������ �ƴϸ� 0�� ��ȯ(���� ��ȣ Ʋ��)
        return 0;       // 0 ��ȯ�Ͽ� ��ȣ ���� Ʋ���� �˸�    
}
#endif
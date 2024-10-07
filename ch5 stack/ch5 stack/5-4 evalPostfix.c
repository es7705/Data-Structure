#if 0
#include <string.h>
#include "5-4 stackL.h"
#include "5-4 evalPostfix.h"

// ���� ǥ��� ������ ����ϴ� ����
element evalPostfix(char* exp)
{
    int opr1, opr2, value, i = 0;
    // char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
    int length = strlen(exp);   // �Էµ� ���� ������ ���̸� ���
    char symbol;    // ���� ó�� ���� ��ȣ(���� �Ǵ� ������)

    top = NULL;     // ���� �ʱ�ȭ

    // ���� ������ �� ���ڿ� ���� �ݺ�
    for ( i = 0; i < length; i++)
    {
        symbol = exp[i];    // ���� ���� ����

        // ���� ���ڰ� �����ڰ� �ƴ� ��� (������ ���)
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
        {
            value = symbol - '0';   // ������ ���ڸ� ���������� ��ȯ
            push(value);            // ���ÿ� ���� Ǫ��
        }   
        else    // ���� ���ڰ� �������� ���
        {
            opr2 = pop();   // ���ÿ��� �� ��° �ǿ����� ��
            opr1 = pop();   // ���ÿ��� ù ��° �ǿ����� ��

            // ���� opr1�� opr2�� ���� symbol�� ����� �����ڸ� ����
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
    // ���� exp�� ���� ó���� ��ģ �� ���ÿ� ���� �ִ� �ᱣ���� pop�Ͽ� ��ȯ
    return pop();
}
#endif
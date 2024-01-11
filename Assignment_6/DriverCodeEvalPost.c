#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int Operand(char x)
{
    if (x == '-' || x == '+' || x == '/' || x == '*')
    {
        return 0;
    }
    return 1;
}

float Eval(char *exp,MyStack *s)
{
    float x1, x2, result;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (Operand(exp[i]))
        {
            push(s, exp[i] - '0');
        }
        else
        {
            x2 = pop(s);
            x1 = pop(s);
            switch (exp[i])
            {
            case '+':
                result = x1 + x2;
                break;
            case '-':
                result = x1 - x2;
                break;
            case '/':
                result = x1 / x2;
                break;
            case '*':
                result = x1 * x2;
                break;
            }
            push(s,result);
        }
    }
    return pop(s);
}

int main()
{
    MyStack s;
    char *postfix="234*-";
    printf("Result is %f\n",Eval(postfix,&s));

    return 0;
}


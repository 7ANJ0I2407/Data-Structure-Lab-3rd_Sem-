#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct MyStack
{
    int top;
    int maxSize;
    char *pStorage;
} MyStack;

int initStack(MyStack *pStack)
{
    pStack->top = -1;
    printf("Input max stack size: ");
    scanf("%d", &(pStack->maxSize));

    pStack->pStorage = (char *)malloc(pStack->maxSize * sizeof(char));

    if (pStack->pStorage == NULL)
    {
        return 0;
    }
    return 1;
}

void freeStack(MyStack *pStack)
{
    free(pStack->pStorage);
    pStack->pStorage = NULL;
}

int push(MyStack *pStack, char elem)
{
    if (pStack->top + 1 == pStack->maxSize)
    {
        return 0;
    }
    pStack->top++;
    pStack->pStorage[pStack->top] = elem;
    return 1;
}

int pop(MyStack *pStack, char *elem)
{
    if (pStack->top == -1)
    {
        return 0;
    }
    *elem = pStack->pStorage[pStack->top];
    pStack->top--;

    return 1;
}

int isCharStackEmpty(MyStack pStack)
{
    if (pStack.top == -1)
    {
        return 1;
    }
    return 0;
}

bool matchParenthesis(MyStack *pStack, char *expression)
{
    int len = strlen(expression);
    bool isValid = true;
    for (int i = 0; i < len; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(pStack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            char tempChar;
            if (isCharStackEmpty(*pStack))
            {
                return false;
            }
            if (pop(pStack, &tempChar) == 1)
            {
                if ((expression[i] == ')' && tempChar != '(') ||
                    (expression[i] == ']' && tempChar != '[') ||
                    (expression[i] == '}' && tempChar != '{'))
                {
                    freeStack(pStack);
                    return false;
                }
            }
            else
            {
                freeStack(pStack);
                return false;
            }
        }
    }
    isValid = isCharStackEmpty(*pStack);
    freeStack(pStack);
    return isValid;
}

int main()
{
    MyStack stack;
    initStack(&stack);
    char expression[50];
    printf("Enter a expression: ");
    getchar();
    fgets(expression, sizeof(expression), stdin);

    if (matchParenthesis(&stack, expression))
    {
        printf("The expression has valid parentheses.\n");
    }
    else
    {
        printf("The expression has invalid parentheses.\n");
    }
    return 0;
}

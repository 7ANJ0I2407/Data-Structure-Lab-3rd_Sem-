#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void push(MyStack *pStack, float elem)
{
    if (pStack->top + 1 == pStack->maxSize)
    {
        return ;
    }
    pStack->top++;
    pStack->pStorage[pStack->top] = elem;
}

float pop(MyStack *pStack)
{
    if (pStack->top == -1)
    {
        return 0;
    }
    float elem = -1;
    elem = pStack->pStorage[pStack->top];
    pStack->top--;

    return elem;
}

float stackTop(MyStack pStack)
{
    return pStack.pStorage[pStack.top];

}

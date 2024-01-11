#include<stdio.h>
#include<stdlib.h>

#include "stackC.h"

void initStackC (MyStack *s)
 {
    s->top = 0;
    s->maxSize = 50;
}
void pushC(MyStack *pStack, char elem)
{
    if (pStack->top + 1 == pStack->maxSize)
    {
        return ;
    }
    pStack->top++;
    pStack->pStorage[pStack->top] = elem;
}

char popC(MyStack *pStack)
{
    if (pStack->top == -1)
    {
        return 0;
    }
    int elem = -1;
    elem = pStack->pStorage[pStack->top];
    pStack->top--;

    return elem;
}

char stackTopC(MyStack pStack)
{
    return pStack.pStorage[pStack.top];

}
int isStackEmptyC(MyStack pStack)
{
    if (pStack.top == -1)
    {
        return 1;
    }
    return 0;
}

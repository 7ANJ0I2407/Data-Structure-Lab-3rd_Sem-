#ifndef __StackC_H__
#define __StackC_H__

typedef struct MyStack
{
    int top;
    int maxSize;
    char pStorage[100];
} MyStack;

void pushC(MyStack *pStack, char elem);
char popC(MyStack *pStack);
char stackTopC(MyStack pStack);
void initStackC (MyStack *s);
int isStackEmptyC(MyStack pStack);

#endif

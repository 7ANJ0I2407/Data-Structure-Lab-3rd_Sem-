#ifndef _Stack_
#define _Stack_

typedef struct MyStack
{
    int top;
    int maxSize;
    float pStorage[100];
} MyStack;

void push(MyStack *pStack, float elem);
float pop(MyStack *pStack);
float stackTop(MyStack pStack);

#endif

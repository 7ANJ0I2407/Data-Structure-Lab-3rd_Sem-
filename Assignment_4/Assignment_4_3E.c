#include <stdio.h>
#include <stdlib.h>

typedef struct MyStack
{
    int top;
    int maxSize;
    int *pStorage;
} MyStack;

int initStack(MyStack *pStack)
{
    pStack->top = -1;
    scanf("%d", &(pStack->maxSize));

    pStack->pStorage = (int *)malloc(pStack->maxSize * sizeof(int));

    if (pStack->pStorage == NULL)
    {
        printf("Memory Allocation Falied.\n");
        return 0;
    }
    return 1;
}

void freeStack(MyStack *pStack)
{
    free(pStack->pStorage);
}

int push(MyStack *pStack, int n)
{
    if (pStack->top + 1 == pStack->maxSize)
    {
        // That implies stack is full
        printf("Stack is full, cannot push\n");
        return 0;
    }
    pStack->top++;
    pStack->pStorage[pStack->top] = n;
    return 1;
}

int pop(MyStack *pStack)
{
    if (pStack->top == -1)
    {
        // Implies its an empty stack
        printf("Stack is empty, cannot pop\n");
        return 0;
    }
    int elem;
    elem = pStack->pStorage[pStack->top];
    pStack->top--;
    return elem;
}

int isIntStackFull(MyStack pStack)
{
    if (pStack.top + 1 == pStack.maxSize)
    {
        return 1;
    }
    return 0;
}
int isIntStackEmpty(MyStack pStack)
{
    if (pStack.top == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    MyStack stack1;
    MyStack stack2;
    printf("Enter stack 1 size : ");
    initStack(&stack1);
    printf("Enter stack 2 size : ");
    initStack(&stack2);
    printf("Enter the element you want to enter : ");
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        if (x > stack1.maxSize)
        {
            printf("Wrong Input\n");
            break;
        }
        int elt;
        printf("Enter the %d element\n", (i + 1));
        scanf("%d", &elt);
        push(&stack1, elt);
    }

    if (stack1.top == -1)
    {
        printf("Stack 1 is empty\n");
    }
    else
    {

        do
        {
            int poppedElt = pop(&stack1);
            push(&stack2, poppedElt);
        } while (stack1.top != -1);
    }

    do
    {
        int elt = pop(&stack2);
        printf("The popped elt is : %d\n", elt);

    } while (stack2.top != -1);

    return 0;
}

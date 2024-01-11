#include <stdio.h>
#include <stdlib.h>

typedef struct MyStack
{
    int top;
    int maxSize;
    int *pStorage;
    int count;
} MyStack;

int initStack(MyStack *pStack)
{
    pStack->top = -1;
    pStack->count = 0;
    printf("Input max stack size: ");
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

int push(MyStack *pStack)
{
    if (pStack->top + 1 == pStack->maxSize)
    {
        // That implies stack is full
        printf("Stack is full, cannot push\n");
        return 0;
    }

    int max_elt = 0;
    printf("Enter the number of elements you want to enter : ");
    scanf("%d", &max_elt);
    int n = 0;
    for (int i = 0; i < max_elt; i++)
    {
        if ((max_elt > pStack->maxSize))
        {
            printf("Wrong Input.\n");
            break;
        }
        printf("Enter the %d element : \n", (pStack->count + 1));
        scanf("%d", &n);
        pStack->top++;
        pStack->pStorage[pStack->top] = n;
        pStack->count++;
    }
    return 1;
}

int pop(MyStack *pStack, int *elem)
{
    if ((pStack->top == -1) && (pStack->count == 0))
    {
        // Implies its an empty stack
        printf("Stack is empty, cannot pop\n");
        return 0;
    }
    *elem = pStack->pStorage[pStack->top];
    pStack->top--;
    pStack->count--;

    return 1;
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
    if ((pStack.top == -1) && (pStack.count == 0))
    {
        return 1;
    }
    return 0;
}

int main()
{
    MyStack stack1;
    MyStack stack2;
    initStack(&stack1);
    initStack(&stack2);

    int Q = 0, Query = 0;
    printf("Enter the number of Queries : ");
    scanf("%d", &Q);
    while (Q)
    {
        printf("Enter 1 to push element to stack 1.\n");
        printf("Enter 2 to push element to stack 2.\n");
        printf("Enter 3 to check stack 1 status.\n");
        printf("Enter 4 to check stack 2 status.\n");
        printf("Enter 5 to pop from stack 1.\n");
        printf("Enter 6 to pop from stack 2.\n");
        printf("Enter 7 to free memory.\n");
        scanf("%d", &Query);

        if (Query == 1)
        {

            push(&stack1);
            if (isIntStackFull(stack1) == 1)
            {

                push(&stack2);
            }
        }

        else if (Query == 2)
        {

            push(&stack2);
        }
        else if (Query == 3)
        {
            printf("The number of element of Stack 1 is %d\n", stack1.count);
            if (isIntStackFull(stack1) == 1)
            {
                printf("Stack 1 is full\n");
            }
            else
            {
                printf("Stack 1 is empty\n");
            }
        }
        else if (Query == 4)
        {
            printf("The number of element of Stack 2 is %d\n", stack2.count);
            if (isIntStackFull(stack2) == 1)
            {
                printf("Stack 2 is full\n");
            }
            else
            {
                printf("Stack 2 is empty\n");
            }
        }
        else if (Query == 5)
        {
            int m = 0;
            printf("Enter number of elements to pop\n");
            scanf("%d", &m);
            if (isIntStackEmpty(stack1) != 1)
            {
                for (int i = 0; i < m; i++)
                {
                    if (m > stack1.maxSize)
                    {
                        printf("Invalid Input\n");
                        break;
                    }
                    int elt = 0;
                    pop(&stack1, &elt);
                    printf("The popped element: %d\n", elt);
                }
            }
            printf("Stack is empty.\n");
        }
        else if (Query == 6)
        {
            int m = 0;
            printf("Enter number of elements to pop\n");
            scanf("%d", &m);
            if (isIntStackEmpty(stack2) != 1)
            {
                for (int i = 0; i < m; i++)
                {
                    if (m > stack2.maxSize)
                    {
                        printf("Invalid Input\n");
                        break;
                    }
                    int elt = 0;
                    pop(&stack2, &elt);
                    printf("The popped element: %d\n", elt);
                }
            }
            printf("Stack is empty.\n");
        }
        else if (Query == 7)
        {
            freeStack(&stack1);
            printf("Stack 1 Memory Deallocated Successfully.\n");
            freeStack(&stack2);
            printf("Stack 2 Memory Deallocated Successfully.\n");
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }

        if ((isIntStackFull(stack1) == 1) && (isIntStackFull(stack2) == 1))
        {
            while (stack2.top != -1)
            {
                int elt = 0;
                pop(&stack2, &elt);
                printf("The popped element from stack 2 is : %d\n", elt);
            }
            while (stack1.top != -1)
            {
                int elt = 0;
                pop(&stack1, &elt);
                printf("The popped element from stack 1 is : %d\n", elt);
            }
        }

        Query--;
    }

    return 0;
}

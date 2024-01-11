#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int front;
    int rear;
    int size;
} queue;

queue createIntegerQueue(queue *q, int queueSize)
{
    q->data = (int *)malloc(sizeof(int) * queueSize);
    if (q->data == NULL)
    {
        free(q->data);
    }

    q->front = 0;
    q->rear = 0;
    q->size = queueSize;

    return *q;
}

int enqueueInteger(queue *q, int d)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full.\n");
        return 0;
    }

    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = d;

    return 1;
}

int dequeueInteger(queue *q, int *dp)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty.\n");
    }

    q->front = (q->front + 1) % q->size;
    *dp = q->data[q->front];

    return 1;
}

int freeIntegerQueue(queue *q)
{
    if (!q)
    {
        return 0;
    }

    free(q->data);
    return 1;
}

int isIntegerQueueFull(queue q)
{
    if ((q.rear + 1) % q.size == q.front)
    {
        return 1;
    }
    return 0;
}

int isIntegerQueueEmpty(queue q)
{
    if (q.front == q.rear)
    {
        return 1;
    }
    return 0;
}

void display(queue p)
{
    for (int i = p.front + 1; i <= p.rear; i++)
    {
        printf("The element is : %d\n", p.data[i]);
    }
}

int main()
{
    int queueSize = 5;
    queue q;
    queue *m = &q;
    q = createIntegerQueue(m, queueSize);
    enqueueInteger(&q, 12);
    enqueueInteger(&q, 18);
    enqueueInteger(&q, 15);
    enqueueInteger(&q, 10);
    enqueueInteger(&q, 123);
    enqueueInteger(&q, 154);

    if (isIntegerQueueFull(q))
    {
        printf("Queue is Full.\n");
    }
    else
    {
        printf("Queue is empty.\n");
    }

    //     queue q;
    //     queue *m = &q;
    //     int size;
    //     printf("Enter the size : ");
    //     scanf("%d", &size);
    //     q = createIntegerQueue(m, size);
    //     int num;

    //     do
    //     {
    //         scanf("%d", &num);
    //         enqueueInteger(&q, num);
    //     } while (!isIntegerQueueFull(q));

    //    display(q);

    //     while(!isIntegerQueueEmpty(q)){
    //     int qElement;
    //     dequeueInteger(&q, &qElement);
    //     printf("Dequeued value is : %d\n", qElement);
    //     if(qElement >= 0) {
    //         int rValue;
    //         rValue = 1 + (rand()%10);
    //         qElement = qElement - rValue;
    //         printf("The dequed element is positive.So enqueuing the element after modification.\n");
    //         enqueueInteger(&q,qElement);
    //     }
    //     else {
    //         printf("Element is negative.\n");
    //     }
    //     }

    //      if (isIntegerQueueFull(q))
    //     {
    //         printf("Queue is Full.\n");
    //     }
    //     else
    //     {
    //         printf("Queue is empty.\n");
    //     }

    // display(q);

    // freeIntegerQueue(*q);
    return 0;
}

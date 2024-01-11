#include <stdio.h>
#include <stdlib.h>

struct intNode
{
    int element;
    struct intNode *next;
} intNode;

struct intNode *addIntNodeSorted(struct intNode *start, int elem)
{
    struct intNode *t = NULL;
    if (start == NULL)
    {
        start = (struct intNode *)malloc(sizeof(struct intNode));
        start->element = elem;
        start->next = NULL;
        t = start;
        return start;
    }
    else if (start->element > elem)
    {
        t = (struct intNode *)malloc(sizeof(struct intNode));
        t->element = elem;
        t->next = start;
        start = t;
        return start;
    }
    struct intNode *head = start, *tail = start;
    while (head != NULL)
    {
        if (head->element > elem)
        {
            break;
        }
        tail = head;
        head = head->next;
    }
    t = (struct intNode *)malloc(sizeof(struct intNode));
    t->element = elem;
    t->next = head;
    tail->next = t;
    return start;
}

int isPresentIntNodeSorted(struct intNode *start, int elem)
{
    struct intNode *head = start;
    int count = 0;
    while (head != NULL)
    {
        if (head->element == elem)
        {
            break;
        }
        count++;
        head = head->next;
    }
    if (head == NULL)
    {
        return 0;
    }
    return (count + 1);
}

struct intNode *deleteIntNodeSorted(struct intNode *start, int elem)
{
    struct intNode *tail = NULL;
    if (start->element == elem)
    {
        tail = start;
        start = start->next;
        free(tail);
        return start;
    }
    struct intNode *head = start;
    while (head != NULL)
    {
        if (head->element == elem)
        {
            break;
        }
        tail = head;
        head = head->next;
    }
    if (head == NULL)
    {
        printf("Invalid Element\n");
        return start;
    }
    tail->next = head->next;
    free(head);
    return start;
}

void printLL(struct intNode *start)
{
    struct intNode *head = start;
    while (head != NULL)
    {
        printf("%d -> ", head->element);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct intNode *start = NULL;
    int Queries = 0, Option = -1;
    printf("Enter Number of queries : ");
    scanf("%d", &Queries);
    while (Queries)
    {
        printf("Enter 1 to Add Element to Node\n");
        printf("Enter 2 to Check an Element in List\n");
        printf("Enter 3 to Delete an Element from Node\n");
        printf("Enter 4 to Print All the Elements\n");
        scanf("%d", &Option);

        if (Option == 1)
        {
            printf("Enter the Number of Elements\n");
            int x = 0, ele = -1;
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
            {
                printf("Enter %d Element\n", (i + 1));
                scanf("%d", &ele);
                start = addIntNodeSorted(start, ele);
            }
        }
        else if (Option == 2)
        {
            printf("Enter the Element to Search\n");
            int ele = -1;
            scanf("%d", &ele);
            int pos = isPresentIntNodeSorted(start, ele);
            printf("\n The index is %d \n", pos);
        }
        else if (Option == 3)
        {
            printf("Enter the Element\n");
            int ele = -1;
            scanf("%d", &ele);
            struct intNode *y = deleteIntNodeSorted(start, ele);
            start = y;
        }
        else if (Option == 4)
        {
            printLL(start);
        }
        else
        {
            printf("Invalid Option\n");
            break;
        }
        Queries--;
    }

    return 0;
}

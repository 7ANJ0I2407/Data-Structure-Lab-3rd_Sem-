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
struct intNode *freeIntNodeSorted(struct intNode *start)
{
    struct intNode *p = NULL;

    if (start == NULL)
    {
        return NULL;
    }
    p = start;
    start = start->next;
    free(p);
    return freeIntNodeSorted(start);
}

struct intNode *reverseIntNodeSorted(struct intNode *start)
{

    struct intNode *prev = NULL;
    struct intNode *curr = start;
    struct intNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void updateIntNode(struct intNode *start)
{
    struct intNode *head = start;
    while (head != NULL)
    {
        head->element += (rand() % 10);
        head = head->next;
    }
}

// struct intNode* deleteNodeHighest(struct intNode* head) {
//     if (head == NULL) {
//         printf("Linked list is empty\n");
//         return NULL;
//     }

//     struct intNode* curr = head;
//     struct intNode* prev = NULL;
//     struct intNode* maxNode = head;
//     int maxValue = head->element;

    // Traverse the linked list to find the highest element and its previous node
//     while (curr->next != NULL) {
//         if (curr->next->element > maxValue) {
//             maxValue = curr->next->element;
//             prev = curr;
//             maxNode = curr->next;
//         }
//         curr = curr->next;
//     }

//     // If the highest element is in the first node, update the head
//     if (prev == NULL) {
//         head = head->next;
//     } else {
//         prev->next = maxNode->next;
//     }
//     maxNode->next = NULL;

//     return maxNode;
// }

// struct intNode *sortIntNode(struct intNode *start)
// {
//         struct intNode *modified = NULL,*temp = NULL,*head = start;
//     while(head != NULL) {
//         temp = deleteNodeHighest(start);
//         if(modified == NULL) {
//             modified = temp;
//         }
//         else {
//             temp->next = modified;
//             modified = temp;
//         }
//     }
//     return modified;


    // if (start == NULL)
    // {
    //     return NULL;
    // }
    // int count = 0;
    // struct intNode *temp = start;
    // while (temp)
    // {
    //     temp = temp->next;
    //     count++;
    // }
    // struct intNode *head = start, *tail = NULL;
    // int i = 0;
    // do
    // {
    //     while (head->next != tail)
    //     {
    //         if (head->element > head->next->element)
    //         {
    //             swapNode(head, head->next);
    //         }
    //         head = head->next;
    //     }
    //     count++;
    // } while (i < count);
    // return start;
// }

struct intNode *mergeSNodeSorted(struct intNode *start1, struct intNode *start2)
{
    struct intNode *last = NULL, *third = NULL;
    if (start1->element < start2->element)
    {
        third = last = start1;
        start1 = start1->next;
        third->next = NULL;
    }
    else
    {
        third = last = start2;
        start2 = start2->next;
        third->next = NULL;
    }
    while (start1 && start2)
    {
        if (start1->element < start2->element)
        {
            last->next = start1;
            last = start1;
            start1 = start1->next;
            last->next = NULL;
        }
        else
        {
            last->next = start2;
            last = start2;
            start2 = start2->next;
            last->next = NULL;
        }
    }
    if (start1)
    {
        last->next = start1;
    }
    if (start2)
    {
        last->next = start2;
    }
    return third;
}

int main()
{
    struct intNode *start = NULL;
    int Queries = 0, Option = -1;
    printf("Enter Number of queries : ");
    scanf("%d", &Queries);
    while (Queries)
    {
        printf("Enter 1 to Add Element a Node\n");
        printf("Enter 2 to Check an Element in List\n");
        printf("Enter 3 to Delete a Element from Node\n");
        printf("Enter 4 to Print All the Elements\n");
        printf("Enter 5 to Free All Nodes\n");
        printf("Enter 6 to Reverse All Nodes\n");
        printf("Enter 7 to Add Random Number\n");
        // printf("Enter 8 to Reverse List\n");
        printf("Enter 8 to Merge Two Lists\n");
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
            printf("\n %d \n", pos);
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
        else if (Option == 5)
        {

            struct intNode *FreeNode = freeIntNodeSorted(start);
        }
        else if (Option == 6)
        {

            start = reverseIntNodeSorted(start);
        }
        else if (Option == 7)
        {
            updateIntNode(start);
        }
        // else if (Option == 8)
        // {
        //     struct intNode *new = sortIntNode(start);
        //     printLL(new);
        // }
        else if (Option == 8)
        {
            struct intNode *start1 = NULL, *start2 = NULL;
            printf("Enter the Number of Elements for L1\n");
            int x = 0, ele = -1;
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
            {
                printf("Enter %d Element\n", (i + 1));
                scanf("%d", &ele);
                start1 = addIntNodeSorted(start1, ele);
            }
            printLL(start1);
            printf("Enter the Number of Elements for L2\n");
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
            {
                printf("Enter %d Element\n", (i + 1));
                scanf("%d", &ele);
                start2 = addIntNodeSorted(start2, ele);
            }
            printLL(start2);
            struct intNode *merge = mergeSNodeSorted(start1, start2);
            printf("Merged List is ...\n");
            printLL(merge);
        }
        // else if (Option == 5) { }
        else
        {
            printf("Invalid Option\n");
            break;
        }
        Queries--;
    }

    return 0;
}

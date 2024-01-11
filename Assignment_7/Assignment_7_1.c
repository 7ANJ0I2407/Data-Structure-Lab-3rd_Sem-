#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int val;
    struct treenode *lchild;
    struct treenode *rchild;

} treenode;

treenode *insertNode(treenode *t, int val)
{
    treenode *r = t, *m = NULL, *q = t;
    if (r == NULL)
    {
        m = (treenode *)malloc(sizeof(treenode));
        m->val = val;
        m->lchild = m->rchild = NULL;
        t = m;
        return t;
    }
    while (r != NULL)
    {
        q = r;
        if (r->val == val)
        {
            return t;
        }
        else if (r->val > val)
        {
            r = r->lchild;
        }
        else
        {
            r = r->rchild;
        }
    }

    m = (treenode *)malloc(sizeof(treenode));
    m->val = val;
    m->lchild = m->rchild = NULL;
    if (q->val > m->val)
    {
        q->lchild = m;
    }
    else
    {
        q->rchild = m;
    }
    return t;
}

int isEmpty(treenode *t)
{
    if (t == NULL)
    {
        return 1;
    }
    return 0;
}
int count = 0;

int getCount(treenode *t)
{
    treenode *temp = t;
    if (temp)
    {
        getCount(temp->lchild);
        getCount(temp->rchild);
        count++;
    }
    return count;
}

int inorder(treenode *t)
{
    treenode *temp = t;
    if (temp)
    {
        inorder(temp->lchild);
        printf("%d ", temp->val);
        inorder(temp->rchild);
    }
    return 0;
}

int preorder(treenode *t)
{
    treenode *temp = t;
    if (temp)
    {
        printf("%d ", temp->val);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
    return 0;
}

int postorder(treenode *t)
{
    treenode *temp = t;
    if (temp)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d ", temp->val);
    }
    return 0;
}

int main()
{

    int Queries = 0;
    treenode *tree1 = NULL;
    printf("Enter The number of Queries : ");
    scanf("%d", &Queries);
    while (Queries)
    {
        printf("Enter 1 to Insert a Node\n");
        printf("Enter 2 to check isEmpty\n");
        printf("Enter 3 to get getCount\n");
        printf("Enter 4 to InOrder Traversal\n");
        printf("Enter 5 to PreOrder Traversal\n");
        printf("Enter 6 to PostOrder Traversal\n");
        int Options;
        scanf("%d", &Options);

        if (Options == 1)
        {
    int root;

            printf("Enter the root value : ");
            scanf("%d", &root);
            tree1 = insertNode(tree1,root);
            int elt;
            printf("Enter the number of Nodes : ");
            scanf("%d", &elt);
            for (int i = 0; i < elt; i++)
            {
                printf("Enter the %d values : ", i + 1);
                scanf("%d", &root);
                insertNode(tree1, root);
            }
        }
        else if (Options == 2)
        {
            if (isEmpty(tree1))
            {
                printf("Tree is Empty\n");
            }
            else
            {
                printf("Not Empty\n");
            }
        }
        else if (Options == 3)
        {
            printf("Count is %d\n", getCount(tree1));
        }
        else if (Options == 4)
        {
            printf("Inorder Traversal \n");

            inorder(tree1);
            printf("\n");
        }
        else if (Options == 5)
        {
            printf("Preorder Traversal \n");

            preorder(tree1);
            printf("\n");
        }
        else if (Options == 6)
        {
            printf("PostOrder Traversal \n");

            postorder(tree1);
            printf("\n");
        }
        Queries--;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    struct treenode *lchild;
    int val;
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
    if (t)
    {
        return 0;
    }
    return 1;
}
int count = 0;

int getCount(treenode *t)
{
    treenode *temp = t;
    int x,y;
    if(temp)
    {
        x = getCount(temp->lchild);
        y = getCount(temp->rchild);
        return (x+y+1);
    }
    return 0;
}

int fun(treenode *t)
{
    treenode *temp = t;
    int x,y;
    if(temp)
    {
        x = fun(temp->lchild);
        y = fun(temp->rchild);
        if(x>y)
        return x+1;
        else
        return y+1;
    }
    return 0;
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

int min(treenode *t)
{
    treenode *temp = t;
    while (temp->lchild != NULL)
    {
        temp = temp->lchild;
    }
    return temp->val;
}

int max(treenode *t)
{
    treenode *temp = t;
    while (temp->rchild != NULL)
    {
        temp = temp->rchild;
    }
    return temp->val;
}

int height(treenode *t)
{
    if (t == NULL)
    {
        return 0;
    }
    int x = 0, y = 0;
    x = height(t->lchild);
    y = height(t->rchild);
    return (x > y) ? x + 1 : y + 1;
}

treenode *insucc(treenode *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    treenode *temp = t;
    while (temp->lchild != NULL)
    {
        temp = temp->lchild;
    }
    return temp;
}

treenode *inpre(treenode *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    treenode *temp = t;
    while (temp->rchild != NULL)
    {
        temp = temp->rchild;
    }
    return temp;
}

treenode *deleteNode(treenode *t, int val)
{
    treenode *q = NULL;

    if (t == NULL)
    {
        return NULL;
    }
    if ((t->lchild == NULL) && (t->rchild == NULL))
    {
        free(t);
        t = NULL;
        return NULL;
    }
    if (val < t->val)
    {
        t->lchild = deleteNode(t->lchild, val);
    }
    else if (val > t->val)
    {
        t->rchild = deleteNode(t->rchild, val);
    }
    else
    {
        if (height(t->lchild) > height(t->rchild))
        {
            q = inpre(t->lchild);
            t->val = q->val;
            t->lchild = deleteNode(t->lchild, q->val);
        }
        else
        {
            q = insucc(t->rchild);
            t->val = q->val;
            t->rchild = deleteNode(t->rchild, q->val);
        }
    }
    return t;
}

int equal(treenode *t1, treenode *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return 1;
    }
    if (t1 == NULL || t2 == NULL)
    {
        return 0;
    }
    if (t1->val != t2->val)
    {
        return 0;
    }
    return (equal(t1->lchild, t2->lchild) && equal(t1->rchild, t2->rchild));
}

int main()
{

    treenode *tree1 = NULL;
    int root;

    tree1 = insertNode(tree1, 20);

    insertNode(tree1, 12);
    insertNode(tree1, 45);
    insertNode(tree1, 98);
    insertNode(tree1, 91);
    insertNode(tree1, 15);
    insertNode(tree1, 36);

    treenode *tree2 = NULL;
    int root2;
    tree2 = insertNode(tree2, 20);

    insertNode(tree2, 12);
    insertNode(tree2, 45);
    insertNode(tree2, 98);
    insertNode(tree2, 91);
    insertNode(tree2, 15);
    insertNode(tree2, 36);

    printf("Inorder Traversal of Tree 1 \n");
    inorder(tree1);
    printf("\n");

    printf("Preorder Traversal of Tree 1\n");
    preorder(tree1);
    printf("\n");

    printf("PostOrder Traversal of Tree 1\n");
    postorder(tree1);
    printf("\n");

    if (isEmpty(tree1))
    {
        printf("Tree 1 is Empty\n");
    }
    else
    {
        printf("Tree 1 is Not Empty\n");
    }

    printf("Inorder Traversal of Tree 2 \n");
    inorder(tree2);
    printf("\n");

    printf("The Number of Nodes are %d\n",getCount(tree1));

    printf("The maximum value is %d\n", max(tree1));
    printf("The minimum value is %d\n", min(tree1));
    printf("The height is %d\n", height(tree1));

    treenode *deleted = deleteNode(tree1, 12);

    printf("Inorder Traversal After Deleting A Node \n");
    inorder(tree1);
    printf("\n");

    if (equal(tree1, tree2))
    {
        printf("The trees are equal\n");
    }
    else
    {
        printf("they are not equal\n");
    }

    treenode *nn = inpre(tree1->lchild);
    printf("The inorder predecesor of Tree 1 is %d\n", nn->val);

    treenode *nnn = insucc(tree1->rchild);
    printf("The inorder predecesor of Tree 1 is %d\n", nnn->val);
    return 0;
}

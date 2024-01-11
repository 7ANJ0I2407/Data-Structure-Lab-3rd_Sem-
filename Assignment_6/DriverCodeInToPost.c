#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackC.h"

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *InToPost(char *infix,MyStack *s)
{
    int i = 0, j = 0;
    char *postfix;
    long len = strlen(infix);
    postfix = (char *)malloc((len+2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(stackTopC(*s)))
                pushC(s,infix[i++]);
            else
            {
                postfix[j++] = popC(s);
            }
        }
    }
    while (!isStackEmptyC(*s))
        postfix[j++] = popC(s);
    postfix[j] = '\0';
    return postfix;
}


int main()
{
    MyStack s;
    initStackC(&s);
    char *infix = "a+b*c-d/e";
    pushC(&s,'#');
    char *postfix = InToPost(infix,&s);
    int length = strlen(postfix)-1;
    for(int i=0;i<length;i++) {
    printf("%c",postfix[i]);
    }
    printf("\n");
    return 0;
}

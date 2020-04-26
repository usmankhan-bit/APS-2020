#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 5
#define TRUE 1
#define FALSE 0

struct stack
{
    int top1;
    int top2;
    int items[STACKSIZE];
};
typedef struct stack STACK;
int empty(STACK *s)
{
    if(s->top1==-1 && s->top2==STACKSIZE)
        return TRUE;
    else
        return FALSE;
}
int full(STACK *s)
{
    if(s->top2==(s->top1+1))
        return TRUE;
    else
        return FALSE;
}
void pusha(STACK *s)
{
    if(full(s))
    {
        printf("Stack is Full\n");
        return;
    }
    int x;
    printf("Enter item to be pushed\n");
    scanf("%d",&x);
    s->top1++;
    s->items[s->top1]=x;
    return;
}
void printa(STACK s)
{

    if(empty(&s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int i;
    for(i=s.top1;i>=0;i--)
    {
        printf("|%d|\n",s.items[i]);
    }
}
void peeka(STACK *s)
{
    if(empty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int x;
    x=s->items[s->top1];
    printf("%d is peeked Item\n",x);
    return;
}
void popa(STACK *s)
{
    if(empty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int x;
    x=s->items[s->top1];
    s->top1--;
    printf("Popped %d\n",x);
    return;
}

void pushb(STACK *s)
{
    if(full(s))
    {
        printf("Stack is Full\n");
        return;
    }
    int x;
    printf("Enter item to be pushed\n");
    scanf("%d",&x);
    s->top2--;
    s->items[s->top2]=x;
    return;
}
void printb(STACK s)
{

    if(empty(&s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int i;
    for(i=s.top2;i<STACKSIZE;i++)
    {
        printf("|%d|\n",s.items[i]);
    }
}
void peekb(STACK *s)
{
    if(empty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int x;
    x=s->items[s->top2];
    printf("%d is peeked Item\n",x);
    return;
}
void popb(STACK *s)
{
    if(empty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    int x;
    x=s->items[s->top2];
    s->top2++;
    printf("Popped\n");
    return;
}
int main()
{
    STACK s;
    s.top1 = -1;
    s.top2=STACKSIZE;
    int c;
    int choice =0;
    while(1)
    {
        printf("* MENU *\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-PRINT\n5-EXIT");
        printf("* ** *\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("Push(a/b)\n");
            scanf("%d",&c);
            if(c==1)
                pusha(&s);
            else
                pushb(&s);

            break;
            case 2:printf("Pop:");
            scanf("%d",&c);
            if(c==1)
                popa(&s);
            else
                popb(&s);
            break;
            case 3:printf("Peek(a\b)");
            scanf("%d",&c);
            if(c==1)
                peeka(&s);
            else
                peekb(&s);
            break;
            case 4:printf("Print(a\b)");
            scanf("%d",&c);
            if(c==1)
                printa(s);
            else
                printb(s);
            break;
            case 5:printf("terminating\n");
                   exit(0);

        }
    }

    return 0;
}

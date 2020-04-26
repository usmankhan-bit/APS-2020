#include <stdio.h>
#include <stdlib.h>
#define MAXSTACKSIZE 5
#define TRUE 1
#define FALSE 0
typedef struct {
    int top;
    int items[MAXSTACKSIZE];

}STACK;

int empty(STACK *s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return TRUE;
    }
    else {
        return FALSE;
    }

}

int full(STACK *s){
    if(s->top==MAXSTACKSIZE-1){
        printf("Stack is full\n");
        return TRUE;
    }
    else{
        return FALSE;
    }

}

void push(STACK *s){
    if(full(s)){
        return;
    }
    int x;
    printf("enter the item to be pushed\n");
    scanf("%d",&x);
    s->top++;
    s->items[s->top]=x;
    printf("push successful\n");
    return;
}

void pop(STACK *s){
    if(empty(s)){
        return;
    }
    int x;
    x=s->items[s->top];
    printf("%d popped\n", x);
    s->top--;
    return;

}
void peek(STACK *s){
    if(empty(s)){
        return;
    }
    int x;
    x=s->items[s->top];
    printf("%d is peeked element\n", x );

}

void print(STACK s){
    if(empty(&s)){
        return;
    }
    int i;
    for(i=s.top;i>=0;i--){
        printf("|%d|\n",s.items[i]);

    }

}
int main()
{   STACK s;
    s.top=-1;
   int choice =0;
    while(1)
    {
        printf("* MENU *\n");
        printf("1-PUSH\n2-POP\n3-PEEK\n4-PRINT\n5-EXIT\n");
        printf("****\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:push(&s);
            break;
            case 2:pop(&s);
            break;
            case 3:peek(&s);
            break;
            case 4:print(s);
            break;
            case 5:printf("terminating\n");
                   exit(0);

        }
    }

    return 0;
}

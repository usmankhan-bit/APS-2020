#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0
struct cqueue {
    int front;
    int rear;
    int items[MAXQUEUE];
};
typedef struct cqueue CQUEUE;
void Enqueue(CQUEUE *);
void Dequeue(CQUEUE *);
int empty(CQUEUE *);
int full(CQUEUE *);
void display(CQUEUE *);
int main() {
    int choice =0;
    CQUEUE cq;
    cq.front = MAXQUEUE - 1;
    cq.rear = MAXQUEUE - 1;
    while(1) {
        printf("\n**** MENU ****\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Display\n");
        printf("4 - Exit\n");
        printf("**************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
                Enqueue(&cq);
                break;
        case 2: Dequeue(&cq);
                break;
        case 3: display(&cq);
                break;
        case 4: printf("Program will Exit. \n");
                exit(0);
}
}
return 0;
}
int empty(CQUEUE *pcq) {
    if(pcq->front == pcq->rear)
        return TRUE;
    else
        return FALSE;
}
int full(CQUEUE *pcq){
    if(pcq->front == (pcq->rear+1) % MAXQUEUE)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(CQUEUE *pcq) {
    if(full(pcq)){
        printf("Queue full\n");
    }
    else {
        int x;
        printf("Enter item to insert:\t");
        scanf("%d", &x);
        pcq->rear = (pcq->rear+1) % MAXQUEUE;
        pcq->items[pcq->rear] = x;
        printf("Insertion Successful\n");
    }
}
void Dequeue(CQUEUE *pcq)
{
    if(empty(pcq)){
        printf("Queue empty\n");
    }
    else {
        int x;
        pcq->front=(pcq->front+1)% MAXQUEUE;
        x = pcq->items[pcq->front];
        printf("%d Dequeued\n", x);
    }
}
void display(CQUEUE *pcq)
{
    if(empty(pcq))
        printf("Queue Empty\n");
    else {
        int i;
        printf("Queue Contents are:\n");
        i = (pcq->front + 1) % MAXQUEUE;
        while(i != pcq->rear)
        {
            printf("%d\n", pcq->items[i]);
            i = (i+1) % MAXQUEUE;
        }
        printf("%d\n", pcq->items[i]);
        printf("\n");
    }
}

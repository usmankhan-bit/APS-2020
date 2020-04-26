#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0
struct dequeue {
    int items[MAXQUEUE];
    int front;
    int rear;
};
typedef struct dequeue DEQUEUE;

void EnqueueFront(DEQUEUE *);
void DequeueFront(DEQUEUE *);
void EnqueueRear(DEQUEUE *);
void DequeueRear(DEQUEUE *);
int empty(DEQUEUE *);
int full(DEQUEUE *);
void Display(DEQUEUE *);


int main() {
    int choice =0;
    DEQUEUE dq;
    dq.front=MAXQUEUE-1;
    dq.rear=MAXQUEUE-1;
    while(1)
    {
        printf("\n **** MENU ****\n");
        printf("1 - Enqueue Front\n");
        printf("2 - Enqueue Rear\n");
        printf("3 - Dequeue Front\n");
        printf("4 - Dequeue Rear\n");
        printf("5 - Display\n");
        printf("6 - Exit\n");
        printf("****************\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
    switch(choice)
    {
    case 1: EnqueueFront(&dq);
            break;
    case 2: EnqueueRear(&dq);
            break;
    case 3: DequeueFront(&dq);
            break;
    case 4: DequeueRear(&dq);
            break;
    case 5: Display(&dq);
            break;
    case 6: printf("Program will exit\n");
            exit(0);
    }
    }
    return 0;
}

int empty(DEQUEUE *pdq) {
    if(pdq->front == pdq->rear)
        return TRUE;
    else
        return FALSE;
}
int full(DEQUEUE *pdq){
if(pdq->front == (pdq->rear+1)% MAXQUEUE)
    return TRUE;
else
    return FALSE;
}
void EnqueueFront(DEQUEUE *pdq) {
    if(full(pdq))
        printf("Queue Full\n");
    else {
        int x;
        printf("Enter Enqueue Item\n");
        scanf("%d", &x);
        pdq->items[pdq->front] = x;
        pdq->front = (pdq->front - 1 + MAXQUEUE)% MAXQUEUE;
    }
}
void EnqueueRear(DEQUEUE *pdq) {
    if(full(pdq))
        printf("Queue Full\n");
    else {

        int x;
        printf("Enter Enqueue Item\n");
        scanf("%d", &x);
        pdq->rear = (pdq->rear + 1) % MAXQUEUE;
        pdq->items[pdq->rear] = x;
    }
}
void DequeueFront(DEQUEUE *pdq) {
    if(empty(pdq))
        printf("Queue Empty\n");
    else {
        int x;
        pdq->front = (pdq->front+1) % MAXQUEUE;
        x = pdq->items[pdq->front];
        printf("%d Dequeued\n", x);
    }
}
void DequeueRear(DEQUEUE *pdq) {
    if(empty(pdq))
        printf("Queue Empty\n");
    else {
        int x;
        x= pdq->items[pdq->rear];
        pdq->rear = (pdq->rear - 1 + MAXQUEUE) % MAXQUEUE;
        printf("%d Dequeued\n", x);
    }
}
void Display(DEQUEUE *pdq) {
    if(empty(pdq))
        printf("Queue Empty\n");
    else {
        int i;
        printf("Queue Contents are:\n");
        i = (pdq->front + 1) % MAXQUEUE;
        while(i != pdq->rear) {
            printf("%d\n", pdq->items[i]);
            i = (i+1) % MAXQUEUE;
        }
        printf("%d\n", pdq->items[i]);
    }
}

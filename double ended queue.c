#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0
struct dqueue {
int front;
int rear;
int items[MAXQUEUE];
};

typedef struct dqueue DQUEUE;
void EnqueueRear(DQUEUE *);
void DequeueFront(DQUEUE *);
void EnqueueFront(DQUEUE *);
void DequeueRear(DQUEUE *);
void Display(DQUEUE *);
int empty(DQUEUE *);
int full(DQUEUE *);

int main() {
    int choice =0, x = 0;
    DQUEUE q;
    q.front=0;
    q.rear=-1;
    while(1) {
        printf("\n**** MENU ****\n");
        printf("1 - Enqueue Rear\n");
        printf("2 - Enqueue Front\n");
        printf("3 - Dequeue Rear\n");
        printf("4 - Dequeue Front\n");
        printf("5 - Display\n");
        printf("6 - Exit\n");
        printf("**************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1: EnqueueRear(&q);
                break;
        case 2: EnqueueFront(&q);
                break;
        case 3: DequeueRear(&q);
                break;
        case 4: DequeueFront(&q);
                break;
        case 5: Display(&q);
                break;
        case 6: printf("Program will Exit. \n");
                exit(0);
}
}
return 0;
}

// Increment Rear and Insert
void EnqueueRear(DQUEUE *pdq)
{
    if(full(pdq))
        printf("Queue full\n");
    else {
        int x;
        printf("Enter Enqueue Item\n");
        scanf("%d", &x);
        (pdq->rear)++;
        pdq->items[pdq->rear]=x;
    }
}
// Decrement front and Insert
void EnqueueFront(DQUEUE *pdq)
{
// We can insert at front only if front is not equal to zero
if (pdq->front != 0){
    int x;
    printf("Enter Enqueue Item\n");
    scanf("%d", &x);
    (pdq->front)--;
    pdq->items[pdq->front]=x;
}
else
    printf("Enqueue Invalid\n");
}
// Remove and Increment front
void DequeueFront(DQUEUE *pdq)
{
if(empty(pdq))
    printf("Empty Queue\n");
else {
    int x;
    x = pdq->items[pdq->front];
    (pdq->front)++;
    printf("%d Dequeued\n", x);
}
}
// Remove and Decrement rear
void DequeueRear(DQUEUE *pdq)
{
if(empty(pdq))
    printf("Empty Queue\n");
else
{
    int x;
    x = pdq->items[pdq->rear];
    (pdq->rear)--;
    printf("%d Dequeued\n", x);
    }
}
int empty(DQUEUE *pdq)
{
    if(pdq->front > pdq->rear)
        return TRUE;
    else
        return FALSE;
}
int full(DQUEUE *pdq)
{
    if(pdq->rear == MAXQUEUE-1)
        return TRUE;
    else
        return FALSE;
}
void Display(DQUEUE *pdq)
{
    if(empty(pdq))
        printf("Empty Queue\n");
    else{
        int i= 0;
        printf("Queue Items are:\n");
        for(i=pdq->front; i<=pdq->rear; i++)
        printf("%d\n", pdq->items[i]);
    }
}

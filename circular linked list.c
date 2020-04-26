#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
typedef struct node NODE;
int currnodes = 0;
NODE * insert_at_start(NODE * last);
NODE * insert_at_end(NODE * last);
NODE * delete_from_start(NODE * last);
NODE * delete_from_end(NODE * last);
NODE * getnode();
void getdata(NODE *);
void display_list(NODE *last);
int main( ) {
    NODE * last=NULL;
    int choice = 0;
    while(1) {
    printf("\n\n* * * * * * Menu * * * * * *\n");
    printf("1. Insert node at start\n");
    printf("2. Insert node at End\n");
    printf("3. Delete node from start\n");
    printf("4. Delete node from end\n");
    printf("5. Display List\n");
    printf("6. Exit\n");
    printf("* * * * * * ******** * * * * * *\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1: last = insert_at_start(last);
                break;
        case 2: last = insert_at_end(last);
                break;
        case 3: last = delete_from_start(last);
                break;
        case 4: last = delete_from_end(last);
                break;
        case 5: display_list(last);
                break;
        case 6: printf("Exiting program\n\n");
                exit(0);
    }
    }
    return 0;
}
NODE * getnode() {
    NODE * newnode;
    newnode = (NODE *) malloc(sizeof(NODE));
    if(newnode == NULL)
        printf("Memory allocation failed.\n");
    return newnode;
}
void getdata(NODE * newnode) {
    printf("Enter the information of node:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}
NODE * insert_at_start(NODE * last) {
    NODE * newnode;
    newnode = getnode();
    if(newnode == NULL)
        return last;
    getdata(newnode);
    if(last == NULL)
    {
        newnode->next=newnode;
        last = newnode;
    }
    else{
    newnode->next = last->next;
    last->next = newnode;
    }
    currnodes++;
    printf("%d is inserted at front of the circular list\n\n", newnode->data);
    return last;
}
NODE * insert_at_end(NODE * last) {
    NODE * newnode;
    newnode = getnode();
    if(newnode == NULL)
        return last;
    getdata(newnode);
    if(last == NULL){
        newnode->next=newnode;
        last = newnode;
    }
    else{
    newnode->next = last->next;
    last->next = newnode;
    last=newnode;
    }
    currnodes++;

    printf("%d is inserted at the end of the list\n\n", newnode->data);
    return newnode;
}
NODE * delete_from_start(NODE * last) {
    NODE * tempnode;
    if(last == NULL)
        printf("List is Empty!\n");
    else {
    if(last->next == last) {
    tempnode = last;
    last = NULL;
    }
    else {
    tempnode = last->next;
    last->next = tempnode->next;
    }
    printf("%d is deleted from front of the list\n\n", tempnode->data);
    free(tempnode);
    currnodes--;
    }
    return last;
}
NODE * delete_from_end(NODE * last) {
    NODE *prevnode = NULL,*tempnode;
    if(last == NULL){
    printf("List is Empty!\n");
    return last;
    }
    else {
    if(currnodes == 1) {
        printf("%d is deleted from end of the list.\n", last->data);
        free(last);
        currnodes--;
        return NULL;
    }
    else {
    prevnode = last->next;
    while(prevnode->next != last)
        prevnode = prevnode->next;
    tempnode=last;
    prevnode->next = last->next;
    last=prevnode;
    printf("%d is deleted from end of the list.\n", tempnode->data);
    free(tempnode);
    currnodes--;
    return last;
    }
    }
}

void display_list(NODE *last)
{
    NODE * tempnode;
    if(last == NULL)
        printf("List is Empty!\n");
    else
    {
        tempnode = last->next;
        printf("The list contents are:\n");
        while(tempnode != last)
        {
        printf("%d --> ", tempnode->data);
        tempnode = tempnode->next;
        }
        printf("%d --> ", tempnode->data);
    }
}

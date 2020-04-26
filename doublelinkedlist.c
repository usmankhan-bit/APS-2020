#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
int currnodes = 0;
// Function prototypes same as singly linked list

NODE * getnode() {
    NODE * newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    if(newnode == NULL)
        printf("Memory Allocation Failed\n");
    return newnode;
}

void getdata(NODE * newnode)
{
    printf("Enter the information for linked list\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
}

NODE * insert_at_start(NODE * start) {
    NODE * newnode;
    newnode = getnode();
    if(newnode == NULL)
        return start;
    getdata(newnode);
    if(start == NULL)
        start = newnode;
    else {
        newnode->next= start;
        start->prev=newnode;
        start = newnode;
    }
    currnodes++;
    printf("%d info is inserted at the start of the doubly linked list\n", newnode->data);
    return start;
}
NODE * insert_at_end(NODE * start) {
    NODE * newnode, *tempnode;
    newnode = getnode();
    if(newnode == NULL)
        return start;
    getdata(newnode);
    if(start == NULL)
        start = newnode;
    else {
        tempnode = start;
        while(tempnode->next != NULL)
            tempnode = tempnode->next;
        tempnode->next = newnode;
        newnode->prev = tempnode;
    }
    currnodes++;
    printf("%d info is inserted at the End of the doubly linked list\n", newnode->data);
    return start;
}
NODE * insert_at_position(NODE * start) {
// Refer Activity Book
}
NODE * delete_from_start(NODE * start) {
    NODE * tempnode;
    if(start == NULL)
        printf("List is empty\n");
    else {
    if(currnodes == 1) // or start->next == NULL
    {
        tempnode = start;
        start = NULL;
    }
    else {
        tempnode = start;
        start = start->next;
        start->prev = NULL;
    }
    printf("Node %d deleted from the start of the Doubly linked list\n", tempnode->data);
    free(tempnode);
    currnodes--;
    }
    return start;
}
NODE * delete_from_end( NODE * start) {
    NODE * tempnode, *prevnode;
    if(start == NULL)
        printf("List is empty\n");
    else {
    if(currnodes == 1)
    {
        tempnode = start;
        start = NULL;
    }
    else
    {
        tempnode = start;
        while(tempnode->next != NULL)
            tempnode = tempnode->next;
        prevnode = tempnode;
        prevnode = prevnode->prev;
        prevnode->next = NULL;
        }
        printf("Node %d deleted from the end of the Doubly linked list\n", tempnode->data);
        free(tempnode);
        currnodes--;
    }
    return start;
}
NODE * delete_from_position(NODE * start) {
// Refer Activity Book
}
void display_list(NODE * start) {
    NODE * tempnode;
    if(currnodes == 0)
        printf("List Empty\n");
    else {
        tempnode = start;
        printf("The list contents are:\n");
        printf("\nNULL <--> ");

        while(tempnode != NULL) {
            printf(" %d <--> ", tempnode->data);
        tempnode = tempnode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    NODE * start=NULL;
    int choice = 0;
    while(1) {
        printf("\n\n* * * * * * Menu * * * * * *\n");
        printf("1. Insert node at start\n");
        printf("2. Insert node at End\n");
        printf("3. Insert node at a Position\n");
        printf("4. Delete node from start\n");
        printf("5. Delete node from end\n");
        printf("6. Delete node from a Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("* * * * * * ******** * * * * * *\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice){
        case 1: start = insert_at_start(start);
                break;
        case 2: start = insert_at_end(start);
                break;
        case 3: start = insert_at_position(start);
                break;
        case 4: start = delete_from_start(start);
                break;
        case 5: start = delete_from_end(start);
                break;
        case 6: start = delete_from_position(start);
                break;
        case 7: display_list(start);
                break;
        case 8: printf("Exiting program\n\n");
                exit(0);
        }
    }
    return 0;
}

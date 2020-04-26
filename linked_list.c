#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;
// Maintain the number of nodes in the list in a global variable
int currnodes = 0;
NODE * insert_at_start(NODE * start);
NODE * insert_at_end(NODE * start);
NODE * delete_from_start(NODE * start);
NODE * delete_from_end(NODE * start);
NODE * getnode();
void getdata(NODE *);
void display_list(NODE *start);
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
            case 3: start = delete_from_start(start);
                    break;
            case 4: start = delete_from_end(start);
                    break;
            case 5: display_list(start);
                    break;
            case 6: printf("Exiting program\n\n");
                    exit(0);
        }
    }
    return 0;
}

// Function to allocate the memory for the struct node
NODE * getnode() 
{
    NODE * newnode;
    newnode = (NODE *) malloc(sizeof(NODE));
    // If the memory allocation fails malloc will return NULL
    if(newnode == NULL)
    printf("Memory allocation failed.\n");
    // Return the newnode at any case
    return newnode;
}

void getdata(NODE * newnode) {
    // Get the information from the user, Initialize the next pointer to NULL
    printf("Enter the information of node:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}

NODE * insert_at_start(NODE * start) {
    NODE * newnode;
    newnode = getnode();
    // Memory allocation failed
    if(newnode == NULL)
        return start;
    // Get the data from the user
    getdata(newnode);
    // If the list is empty, newnode is the start of the list
    if(start == NULL)
        start = newnode;
    else {
    // Add the newnode at the beginning and update the start
        newnode->next = start;
        start = newnode;
    }
    // Increment currnodes, print a message and return updated start
    currnodes++;
    printf("%d is inserted at front of the list\n\n", newnode->data);
    return start;
}

NODE * delete_from_start(NODE * start) {
    if(start == NULL)
        printf("List is Empty!\n");
    else {
        NODE * tempnode = start;
        start=start->next;
        printf("%d is deleted from front of the list\n", tempnode->data);
        free(tempnode); 
        currnodes--;
    }
    return start;
}

NODE * insert_at_end(NODE * start) 
{
    NODE * newnode, * nextnode;
    newnode = getnode();
    if(newnode == NULL)
        return start;
    getdata(newnode);
    if(start == NULL)
        start = newnode;
    else {
        nextnode = start;
        while(nextnode->next != NULL)
        nextnode = nextnode->next;
        nextnode->next = newnode;
    }
    currnodes++;
    printf("%d is inserted at the end of the list\n\n", newnode->data);
    return start;
}

NODE * delete_from_end(NODE * start) {
    NODE *prevnode, *nextnode;
    if(start == NULL)
    printf("List is Empty!\n");
    else {
        if(currnodes == 1) { // or start->next == NULL
            nextnode = start;
            start=NULL;
        }
        else {
            nextnode = start;
            prevnode = NULL;
            while(nextnode->next!=NULL) {
                prevnode = nextnode;
                nextnode = nextnode->next;
            }
            prevnode->next = NULL;
        }
        printf("%d is deleted from end of the list.\n", nextnode->data);
        free(nextnode);
        currnodes--;
    }
    return start;
}



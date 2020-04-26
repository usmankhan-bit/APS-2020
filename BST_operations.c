#include <stdio.h>
#include <stdlib.h>

struct tree{
int data;
struct tree *left;
struct tree *right;
struct tree *gl;
struct tree *gr;
};

typedef struct tree TREE;
int count=0,leaf=0,k=0,intern=0;

TREE *insert_in_tree(TREE *root)
{
    TREE *newnode;
    newnode=(TREE *)malloc(sizeof(TREE));
    if(newnode==NULL){
        printf("memory allocation failed\n");
        return root;
    }
    printf("enter the data\n");
    scanf("%d", &newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->gl=NULL;
    newnode->gr=NULL;
    if(root==NULL){
        root=newnode;
        printf("newnode created\n");
        return root;
    }
    TREE *curr, *prev,*parent;
    curr=root;
    prev=NULL;
    parent=NULL;
    while(curr!=NULL){
        parent=prev;
        prev=curr;
        if(newnode->data < curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(newnode->data < prev->data)
    {
        prev->left=newnode;

    }
    else
        {
            prev->right=newnode;

        }
    if(parent!=NULL){
    if(parent->left==prev&&prev->left==newnode){
    if(parent->left->left!=NULL)
        {
            parent->gl=newnode;
            printf("%d %d\n",parent->data,parent->gl->data);
        }}
    if(parent->right==prev&&prev->right==newnode){
    if(parent->right->right!=NULL)
            {
                parent->gr=newnode;
                printf("%d %d\n",parent->data,parent->gr->data);
            }
    }}
    printf("node inserted\n");
    return root;


}

void inorder(TREE *root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }

}

void preorder(TREE *root)
{
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

void postorder(TREE *root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }

}

TREE * delete_from_BST(TREE * root, int item)
{
    TREE * currnode, *parent, *successor, *p;

    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    parent = NULL;
    currnode = root;
    while (currnode != NULL && item != currnode->data)
    {
        parent = currnode;
        if(item < currnode->data)
            currnode  = currnode->left;
        else
            currnode = currnode->right;
    }

    if(currnode == NULL)  {
        printf("Item not found\n");
        return root;
    }

    if(currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else
    {
        successor = currnode->right;
        while(successor->left != NULL)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    if (parent == NULL) {
        free(currnode);
        return p;
    }

    if(currnode == parent ->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    return root;
}

void count_nodes(TREE *root){
    if(root!=NULL){
        count_nodes(root->left);
        count_nodes(root->right);
        count++;
    }

}
void leaf_count(TREE *root)
{
    if(root!=NULL){
    if(root->left==NULL && root->right==NULL){
        leaf++;
    }
    leaf_count(root->left);
    leaf_count(root->right);
    }
}

void count_k(TREE *root, int element)
{
    if(root!=NULL)
    {
        count_k(root->left,element);
        count_k(root->right,element);
        if(root->data>element){
            k++;
        }
    }

}

void min(TREE *root){
    if(root->left!=NULL){
        root=root->left;
        min(root);
    }
    printf("%d\n",root->data);

}

void max(TREE *root){
    if(root->right!=NULL){
        root=root->right;
        max(root);
    }
    printf("%d\n",root->data);

}
TREE * copy(TREE *root){
    TREE *copy;
    copy=root;
    return copy;

}
int level1(TREE *root){
    if(root==NULL){
        return 0;
    }
    if(root->left!=NULL && root->right!=NULL){
        return 2;
    }
    else if((root->left!=NULL && root->right==NULL)||(root->left==NULL && root->right!=NULL)){
        return 1;
    }
    else if(root->left==NULL && root->right==NULL){
        return 0;
    }

}
void internal(TREE *root)
{
        if(root->left!=NULL||root->right!=NULL){
            intern++;
        }
        internal(root->left);
        internal(root->right);


}



int main()
{
    TREE *root, *dup;
    root=NULL;
    int choice,item, element,x,size;
    while(1){
        printf("\nmenu\n 1.insert\n 2.inorder\n 3.pre order\n 4. post order\n 5.delete\n 6.address of root\n 7.count the nodes\n");
        printf(" 8.leaf count\n 9.edges in tree\n 10.nodes greater than a value\n 11. min value\n 12.max value\n 13.copy tree\n");
        printf(" 14.level 1 elements\n 15.internal nodes in a tree\n 16.size of tree\n 17.out degree of root node\n");
        printf("enter the choice\n");
        scanf("%d", &choice);

        switch (choice){
            case 1: root=insert_in_tree(root);
                    break;
            case 2: inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: printf("enter the element to be deleted\n");
                    scanf("%d",&item);
                    root=delete_from_BST(root,item);
                    break;
            case 6: printf("%p\n",root);
                    break;
            case 7: count_nodes(root);
                    printf("%d\n",count);
                    break;
            case 8: leaf_count(root);
                    printf("%d\n",leaf);
                    break;
            case 9: printf("%d",count-1);
                    break;
            case 10: printf("enter the element\n");
                     scanf("%d",&element);
                     count_k(root, element);
                     printf("the no. of nodes are %d\n",k);
                     break;
            case 11: min(root);
                     break;
            case 12: max(root);
                     break;
            case 13: dup=copy(root);
                     inorder(dup);
                     break;
            case 14: x=level1(root);
                     printf("%d\n",x);
                     break;
            case 15:internal(root);
                    printf("%d\n",intern);
                    break;
            case 16: count_nodes(root);
                     size = count*sizeof(TREE);
                     printf("%d\n",size);
                     break;
            case 17: x=level1(root);
                     printf("%d\n",x);
                     break;
        }
    }
    return 0;
}

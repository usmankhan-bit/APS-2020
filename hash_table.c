#include<stdio.h>
#include<stdlib.h>

struct item {
    int data;
    int key;
};

struct item * hasharray[20];

void search(int key){
    int hashkey=key%20;

    while(hasharray[hashkey]!=NULL){
        if(hasharray[hashkey]->key==key){
            printf("%d",hasharray[hashkey]->data);
            break;
        }
        hashkey++;
        hashkey=hashkey%20;
    }
}

void insert(int key,int data){
    struct item *temp=(struct item *)malloc(sizeof(struct item));
    temp->data=data;
    temp->key=key;

    int hashkey=key%20;

    while(hasharray[hashkey]!=NULL && hasharray[hashkey]->key!=-1){
        hashkey++;
        hashkey=hashkey%20;
    }

    hasharray[hashkey]=temp;

}

void print(){
    int i;
    for(i=0;i<20;i++){
        if(hasharray[i]!=NULL){
            printf("Key = %d value = %d\n",hasharray[i]->key,hasharray[i]->data);
        }
        else{
            printf("----\n");
        }
    }
}

int main(){
    insert(1,2);
    insert(2,4);
    insert(4,6);
    insert(5,10);
    print();
    search(5);
    return 0;
}
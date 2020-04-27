#include<stdio.h>
#include<string.h>

int main(){

    char string[100];

    scanf("%[^\n]s",string);

    char *p=strtok(string," ");
    while(p!=NULL){

        printf("%s\n",p);
        p=strtok(NULL," ");
        
    }
    return 0;
}
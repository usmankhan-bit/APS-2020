#include<stdio.h>

int main(){
    int a=50,b=20;
    
    a=a^b;
    printf("a = %d b = %d",a,b);
    b=a^b;
    printf("a = %d b = %d",a,b);
    a=a^b;

    printf("a = %d b = %d",a,b);
    
    return 0;
}

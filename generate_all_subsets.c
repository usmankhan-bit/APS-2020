#include<stdio.h>

int main()
{
    char a[]={'a','b','c'};
    int N = 3;
    for(int i=0;i<(1<<N);i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i&(1<<j))
                printf("%c",a[j]);
        }
        printf("\n");
    }
}
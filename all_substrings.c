#include<string.h>
void compute(char str[],int n)
#include<stdio.h>
{
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j = i+len-1;
            for(int k=i;k<=j;k++)
                printf("%c",str[k]);
            printf("\n");
        }
    }
}

int main()
{
    char str[]="abc";
    compute(str,strlen(str));
}

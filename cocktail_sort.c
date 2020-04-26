#include<stdio.h>
#include<stdlib.h>


void sort(int a[],int n)
{
    int i,j,temp;
    int swap=1;
    int start=0,end=n-1;
    while(swap)
    {
        swap=0;
        for(i=start;i<end;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
                swap=1;
            }

        }
        if(!swap)
                break;
        end--;
        for(i=end-1;i>=start;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
                swap=1;
            }
        }
        start++;
    }
}

int main()
{
    int i;
    int a[5]={4,3,5,6,7};
    sort(a,5);
    for(i=0;i<5;i++)
        printf("%d\t",a[i]);
}

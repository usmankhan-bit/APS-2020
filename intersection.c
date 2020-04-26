#include<stdio.h>
#include<stdlib.h>

void intersect(int a1[10],int a2[10],int m,int n)
{
    int i,j,v;
    for(i=0;i<m;i++)
    {
        v=a1[i];
        for(j=0;j<n;j++)
        {
            if(v==a2[j])
                printf("%d\t",v);
        }
    }
}



int main()
{
    int a1[10],a2[10];
    int m,n,i,j;
    printf("enter the no.of elements in set1 and set2\n");
    scanf("%d%d",&m,&n);
    printf("enter the elements\n");
    for(i=0;i<m;i++)
        scanf("%d",&a1[i]);
    for(i=0;i<n;i++)
        scanf("%d",&a2[i]);
    intersect(a1,a2,m,n);
}

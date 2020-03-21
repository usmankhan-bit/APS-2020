#include<iostream>
#include<math.h>

using namespace std;

int table[50][50];

int query(int low,int high,int *a)
{
    int l = high - low + 1;
    int k = log2(l);
    if(a[table[low][k]]<=a[table[low+l-(1<<k)][k]])
        return a[table[low][k]];
    else
        return a[table[low+l-(1<<k)][k]];
}

void preprocess(int *arr , int n)
{
    for(int i=0;i<n;i++)
        table[i][0]=i;
    
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;(i+(1<<j)-1)<n;i++)
        {
            if(arr[table[i][j-1]]<arr[table[i+(1<<j-1)][j-1]])
                table[i][j]=table[i][j-1];
            else
            {
                table[i][j]=table[i+(1<<j-1)][j-1];
            }
            
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;(1<<j)<=n;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
}


int main()
{
    int n=6;
    int arr[]={4,6,1,5,7,3};

    preprocess(arr,n);

    cout<<query(0,5,arr)<<endl;
    cout<<query(3,5,arr)<<endl;
    cout<<query(0,1,arr)<<endl;


}
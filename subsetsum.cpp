#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=8;
    int arr[]={1,3,5,7,9,11,13,15};
    int sum=30;
    bool matrix[n+1][sum+1];

    memset(matrix,0,sizeof(matrix));

    for(int i=0;i<=n;i++)
        matrix[i][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-arr[i-1]>=0)
            {
                matrix[i][j]=matrix[i-1][j]||matrix[i-1][j-arr[i-1]];
            }
            else
                matrix[i][j]=matrix[i-1][j];
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
            
        cout<<endl;
    }
    int subset[5],val;
    int ind=0;
    int j=sum;

    if(matrix[n][sum]==0)
    {
        cout<<"No subsets"<<endl;
        exit(0);
    }
    
    for(int i=n;i>0;i--)
    {
        if(matrix[i-1][j]==0)//check top is false
        {
            if(matrix[i][j-arr[i-1]]==1)//check left is true
            {
                subset[ind]=arr[i-1];
                ind++;
                j=j-arr[i-1];
            }
            else
            {
                break;
            } 
        }
        else
        {
            continue;
        }
        
    }

    for(int i=0;i<ind;i++)
        cout<<subset[i]<<endl;

}

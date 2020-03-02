#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int weight[n] , values[n];

    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>values[i];
    }
    int total;
    cin>>total;

    int matrix[n+1][total+1];
    memset(matrix,0,sizeof(matrix));

    for(int i=0;i<=n;i++)
        matrix[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=total;j++)
        {
            if(j-weight[i-1]>=0)
            {
                matrix[i][j]=max(matrix[i-1][j],matrix[i-1][j-weight[i-1]]+values[i-1]);
            }
            else
            {
                matrix[i][j]=matrix[i-1][j];
            }
            
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=total;j++)
    //         cout<<matrix[i][j]<<" ";
    //     cout<<endl;
    // }
    int subset[n];
    int sub_values[n];
    int j=total;
    int ind=0;
    for(int i=n;i>0;i--)
    {
        if(matrix[i-1][j]!=matrix[i][j])//check top element
        {
            subset[ind]=weight[i-1];
            sub_values[ind]=values[i-1];
            ind++;
            j=j-weight[i-1];
        }
        else
        {
            continue;
        }
        
    }
    //cout<<matrix[n][total]<<endl; //to print max value

    for(int i=0;i<ind;i++)
        cout<<subset[i]<<" "<<sub_values[i]<<endl;
}
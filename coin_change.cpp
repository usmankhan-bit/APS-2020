#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void max_ways(vector<int> vec,int sum,int n)
{
    int table[n][sum+1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            table[i][j]=0;
        }
    }

    for(int i=0;i<n;i++)
        table[i][0]=1;
    for(int i=1;i<=sum;i++)
    {
        if(i%vec[0]==0)
            table[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<vec[i])
                table[i][j]=table[i-1][j];
            else
                table[i][j]=table[i-1][j]+table[i][j-vec[i]];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    int row=n-1;
    int col=sum;
    while(row)
    {
        if(table[row][col]!=table[row-1][col])
        {
            if(table[row-1][col]==1)
            {
                if(table[row-2][col]==0)
                {
                    cout<<"only "<<vec[row-1]<<endl;
                }
                else
                {
                    cout<<vec[row-1]<<" "<<vec[row-2]<<endl;
                }
                
            }
            else
            {
                
            }
            
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector <int> temp;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        temp.push_back(no);
    }
    int sum;
    cin>>sum;
    max_ways(temp,sum,n);
}
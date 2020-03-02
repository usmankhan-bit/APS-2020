#include<iostream>
#include<vector>
using namespace std;

int generateTable(vector<int> arr,int sum)
{
    int table[arr.size()+1][sum+1];
    for(int i=0;i<=sum;i++)
        table[0][i]=0;
    for(int i=1;i<=arr.size();i++)
    {
        table[i][0]=1;
    }
    for(int i=0;i<arr.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i])
            {
                table[i+1][j]=table[i][j];
            }
            else
            {
                table[i+1][j]=table[i][j]+table[i+1][j-arr[i]];
            }
            
        }
    }

    for(int i=0;i<=arr.size();i++)
    {
        for(int j=0;j<=sum;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }

    return table[arr.size()][sum];
}

int main()
{
    vector<int> vec = {3,5,10};
    int sum=15;
    cout<<generateTable(vec,sum)<<endl;
}
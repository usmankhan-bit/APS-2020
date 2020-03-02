#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int generate(int n,int k)
{
    int array[n+1];
    memset(array,0,sizeof(array));
    array[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,k);j!=0;j--)
        {
            array[j] = array[j-1] + array[j];
        }
    }
    for(auto i:array)
        cout<<i<<" ";
    cout<<endl;
    return array[k];
}

int main()
{
    cout<<generate(5,4)<<endl;
}
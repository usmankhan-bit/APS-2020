#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void max_cutting_rod(int n)
{
    int arr[n+1];
    memset(arr,0,sizeof(arr));

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            int temp=max(arr[i],j*(i-j));
            arr[i]=max(temp,j*arr[i-j]);
        }
    }

    for(int i=0;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    
}


int main()
{
    int n;
    cin>>n;
    max_cutting_rod(n);

}
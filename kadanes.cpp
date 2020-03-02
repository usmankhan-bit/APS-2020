#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int arr[]={-2,-3,-4,-1,-2,-1,-5,-3};
    int n=8;
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    int start=0,end=-1,s=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here+=arr[i];

        if(max_ending_here<0)
        {
            s=i+1;
            max_ending_here=0;
        }

        if(max_so_far<max_ending_here)
        {
            max_so_far=max_ending_here;
            start=s;
            end=i;
        }
    }

    if(end==0)
    {
        max_so_far=arr[0];
        int i;
        for(i=0;i<n;i++)
        {
            if(max_so_far<arr[i])
            {
                max_so_far=arr[i];
                start=i;
                end=i;
            }
                
        }
        
        
    }

    cout<<"max sum is "<<max_so_far<<endl;
    for(int i=start;i<=end;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
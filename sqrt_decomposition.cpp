#include<iostream>
#include<math.h>
using namespace std;
int blk_arr[100];
int blk_size;
int inp_arr[10000];

int query(int l , int r)
{
    int sum=0;
    while(l<r and l%blk_size!=0 and l!=0)
    {
        sum+=inp_arr[l];
        l++;
    }
    cout<<sum<<endl;
    while(l+blk_size<=r)
    {
        sum+=blk_arr[l/blk_size];
        l+=blk_size;
    }
    cout<<sum<<endl;
    while(l<=r)
    {
        sum+=inp_arr[l];
        l++;
    }
    cout<<sum<<endl;
    return sum;
}


void build_blk_array(int *inp,int n)
{
    int blk_idx = -1;
    blk_size = sqrt(n);

    for(int i=0;i<n;i++)
    {
        inp_arr[i] = inp[i];
        if(i%blk_size==0)
            blk_idx++;
        blk_arr[blk_idx]+=inp_arr[i];
    }
}





int main()
{
    int size = 9;
    int arr[] = {1,2,3,4,5,6,7,8,9};

    build_blk_array(arr,size);

    cout<<query(2,8)<<endl;



}
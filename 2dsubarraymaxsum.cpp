#include<iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> kadanes(int arr[],int n)
{
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    int start=0,end=-1,s=0;
    vector<int> ret_vec;
    for(int i=0;i<n;i++)
    {
        max_ending_here+=arr[i];

        if(max_ending_here<0)
        {
            s=i+1;
            max_ending_here=0;
        }

        else if(max_so_far<max_ending_here)
        {
            max_so_far=max_ending_here;
            start=s;
            end=i;
        }
    }

    if(end==-1)
    {
        max_so_far=INT_MIN;
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
    ret_vec.push_back(start);
    ret_vec.push_back(end);
    ret_vec.push_back(max_so_far);

    return ret_vec;   
}

int main()
{
    int m,n;
    cin>>m>>n;
    int matrix[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }
    int max_left=0,max_right=0,max_up=0,max_down=0;
    int max_sum=INT_MIN;
    int temp_arr[m];
    memset(temp_arr,0,sizeof(temp_arr));
    for(int i=0;i<n;i++)
    {
        memset(temp_arr,0,sizeof(temp_arr));
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                temp_arr[k]+=matrix[k][j];
            }
            vector<int> temp_vec=kadanes(temp_arr,m);
            if(temp_vec[2]>max_sum)
            {
                max_sum=temp_vec[2];
                max_left=i;
                max_right=j;
                max_up=temp_vec[0];
                max_down=temp_vec[1];
            }

        }
    }
    // for(int i=max_up;i<=max_down;i++)
    // {
    //     for(int j=max_left;j<=max_right;j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    //cout<<max_up<<max_down<<max_right<<max_left<<endl;
    int number=(max_down+1-max_up)*(max_right+1-max_left);

    cout<<max_sum<<endl<<number<<endl;

}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),greater<int>());

    while(!arr.empty()){

    cout<<arr.size()<<endl;
    
    for(int i = 0; i<arr.size();++i)
        arr[i]-=arr[arr.size()-1];
    
    while(arr.back() ==0 && !arr.empty())
        arr.pop_back();

    }
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_common_subsequence(string s1,string s2)
{
    int len1=s1.length();
    int len2=s2.length();
    int arr[len1+1][len2+1];

    string str;

    memset(arr,0,sizeof(arr));

    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                str.push_back(s1[i-1]);
                arr[i][j]=arr[i-1][j-1]+1;

            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
            
        }
    }

    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return arr[len1][len2];

    
}


int main()
{
    string s1,s2,temp;
    getline(cin,temp);
    s1=temp;
    reverse(temp.begin(),temp.end());
    s2=temp;
    int length = max_common_subsequence(s1,s2);
    cout<<s1.length()-length<<endl;


}
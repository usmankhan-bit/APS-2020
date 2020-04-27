#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n , m;
    cin >> n;
    vector<int> first(n);
    for(int i = 0; i < n; i++)
        cin >> first[i];
    cin >> m;
    vector<int> second(m);
    for(int i = 0; i < m; i++)
        cin >> second[i];
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    vector<int> res;
    int i = 0, j = 0;
    while(j < m){
        if(first[i]==second[j]){
            i++; j++;
        }
        else{
            res.push_back(second[j]);
            j++;
        }
    }
    vector<int> arr;
    arr.push_back(res[0]);
    for(int i = 1; i < res.size(); i++){
        if(res[i]!=res[i-1])
            arr.push_back(res[i]);
    }
    for(auto a : arr)
        cout << a << " ";
}
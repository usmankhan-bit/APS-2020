#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
vector<int> tree;

int getNext(int x)
{
    x = x + (x & (-x));
    return x;
}

int getParent(int x)
{
    x = x - (x & (-x));
    return x;
}

void updateTree(int el,int i)
{
    //cout<<el<<" "<<i<<endl;
    while(i<tree.size())
    {
        tree[i]+=el;
        i=getNext(i);
    }
}

void createTree()
{
    for(int i=1;i<=vec.size();i++)
    {
        updateTree(vec[i-1],i);
    }
}

int query(int index)
{
    index+=1;
    int sum=0;
    while(index>0)
    {
        sum+=tree[index];
        index=getParent(index);
    }
    return sum;
}



int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<=n+1;i++)
        tree.push_back(0);

    for(int i=0;i<n;i++)
    {
        int n;
        cin>>n;
        vec.push_back(n);
    }

    createTree();

    for(int i=0;i<tree.size();i++)
        cout<<tree[i]<<" ";
    cout<<endl;

    int l = 2;
    int r = 6;
    cout<<query(r) - query(l-1)<<endl;
    

    
}
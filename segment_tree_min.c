#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int tree[100000000];
int A[1000000];

int minVal(int x, int y) { return (x < y)? x: y; } 

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node]=minVal(tree[2*node],tree[2*node+1]);
    }
}



int query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l)
    {
        // range represented by a node is completely outside the given range
        return INT_MAX;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    return minVal(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
    
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    build(1,1,n);
    int l,r;
    for(int i=0;i<m;i++)
    {
        
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,1,n,l+1,r+1));
    }

    
}
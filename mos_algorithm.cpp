#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int block;

struct query
{
    int L,R;
};

bool compare(query a , query b)
{
    if(a.L/block!=b.L/block)
        return a.L/block<b.L/block;
    
    return a.R<b.R;
}

void query_execute(int *a,int n,query *q,int m)
{
    block = sqrt(n);

    sort(q,q+m,compare); 
    int currL = 0, currR = 0; 
    int currSum = 0; 
  
    // Traverse through all queries 
    for (int i=0; i<m; i++) 
    { 
        int L = q[i].L, R = q[i].R; 

        while (currL < L) 
        { 
            currSum -= a[currL]; 
            currL++; 
        } 

        while (currL > L) 
        { 
            currSum += a[currL-1]; 
            currL--; 
        } 
        while (currR <= R) 
        { 
            currSum += a[currR]; 
            currR++; 
        } 

        while (currR > R+1) 
        { 
            currSum -= a[currR-1]; 
            currR--; 
        } 
  
        cout << "Sum of [" << L << ", " << R 
             << "] is "  << currSum << endl; 
    } 
}


int main()
{
    int n=6;
    int a[]={1,2,3,1,2,6};
    int m=3;
    query q[]={{1,3},{0,5},{3,5}};

    query_execute(a,n,q,m);


}
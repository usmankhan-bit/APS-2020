#include<iostream>
#include<vector>
using namespace std;

vector<vector <int>> BIT2D;

void update(int value, int x, int y)
{
    for(int i=x;i<BIT2D.size();i+=(i&-i))
    {
        for(int j=y; j<BIT2D[0].size();j+=(j&-j))
        {
            BIT2D[i][j]+=value;
        }       
    }

}

int query(int x, int y)
{
    int sum=0;
    for(int i=x;i>0;i-=(i&-i))
    {
        for(int j=y; j>0;j-=(j&-j))
            sum+=BIT2D[i][j];
    }

    return sum;
}

int answer_query(int x1 , int y1, int x2, int y2)
{
    return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
}


void create_fenwick_tree(int matrix[][1000],int m, int n)
{
    BIT2D.assign(m+1, vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            update(matrix[i][j],i+1,j+1);
        }
    }

}


int main()
{
    int n,m,t;
    cin>>m>>n>>t;
    int matrix[1000][1000];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }

    create_fenwick_tree(matrix,m,n);

    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans = answer_query(x1,y1,x2,y2) ;
        cout<<ans<<endl;
        if(ans>m)
            cout<<"Dangerous"<<endl;
        else
        {
            cout<<"Safe"<<endl;
        }
        

    }

}
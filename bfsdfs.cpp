#include<iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        int V;
        list<int> *adj;

        Graph(int v)
        {
            V=v;
            adj=new list<int> [V];
        }

        void addEdge(int v,int w)
        {
            adj[v].push_back(w);
        }

        void BFS(int s)
        {
            bool visited[V];
            memset(visited,0,sizeof(visited));
            list<int> queue;

            queue.push_back(s);
            visited[s]=true;

            while(!queue.empty())
            {
                int s=queue.front();
                visited[s]=true;
                cout<<s<<" ";
                queue.pop_front();

                list<int>::iterator i;
                for(i=adj[s].begin();i!=adj[s].end();i++)
                {
                    if(!visited[*i])
                    {
                        queue.push_back(*i);
                        
                    }
                }

            }
        }

        void DFSUtil(int v,bool *visited)
        {
            visited[v]=true;
            cout<<v<<" ";

            list<int>::iterator i;
            for(i=adj[v].begin();i!=adj[v].end();i++)
            {
                if(!visited[*i])
                    DFSUtil(*i,visited);
            }
        }

        void DFS(int s)
        {
            bool *visited=new bool[V];
            for(int i=0;i<V;i++)
                visited[i]=false;
            DFSUtil(s,visited);
        }

        void print()
        {
            for(int i=0;i<V;i++)
            {
                cout<<i<<" ";
                for(auto x:adj[i])
                    cout<<x<<" ";
                cout<<endl;
            }
        }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    // g.BFS(2);
    // cout<<endl;
     g.DFS(2);

    //g.print();
}

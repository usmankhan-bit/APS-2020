from collections import defaultdict
graph = defaultdict(list)


def addEdge(u,v):
    global graph
    graph[u].append(v)

def dfs(v,visited):
    global graph
    visited[v]=True
    #print(visited)
    print(v,end=" ")

    for i in graph[v]:
        if visited[i]==False:
            dfs(i,visited)

n=int(input())
visited = [False]*(n+1)
edj=int(input())
for _ in range(edj):
    x,y=map(int,input().split())
    addEdge(x,y)
s=int(input())
dfs(s,visited)




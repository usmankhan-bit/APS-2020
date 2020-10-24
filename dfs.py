from collections import defaultdict
graph = defaultdict(list)
level = 0

def addEdge(u,v):
    global graph
    graph[u].append(v)

def dfs(v,visited):
    global graph,level
    visited[v]=True
    #print(visited)

    for i in graph[v]:
        if visited[i]==False:
            level_nodes[i] = level_nodes[v]+1
            dfs(i,visited)

n=int(input())
level_nodes = [0]*(n+1)
visited = [False]*(n+1)
edj = n-1
for _ in range(edj):
    x,y=map(int,input().split())
    addEdge(x,y)
s=1
dfs(s,visited)
q = int(input())
minn = n+3
index = n+2
for _ in range(q):
    lover = int(input())
    temp_min = level_nodes[lover]
    if minn==temp_min:
        if lover<index:
            index = lover
    elif temp_min<minn:
        minn = temp_min 
        index = lover

print(index)

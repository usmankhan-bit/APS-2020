from collections import defaultdict
graph = defaultdict(list)
visited = []
count=0


def addEdge(u,v):
    global graph
    graph[u].append(v)
    graph[v].append(u)


def dfs(v,summ):
    global graph,visited,m,cats,count
    visited[v]=True
    if summ>m:
        return 0


    if len(graph[v]) == 1 and v != 1 and summ <= m:
        print(v)
        count+=1

    for i in graph[v]:
        if visited[i]==False and i!=v:
            if cats[i-1] == 0:
                dfs(i,0)
            else:
                dfs(i,summ+cats[i-1])

#Main Function
n,m=map(int,input().split())
cats = list(map(int,input().split()))
visited = [False]*(n+1)
edj=n-1
for _ in range(edj):
    x,y=map(int,input().split())
    addEdge(x,y)
s=1
dfs(s,cats[s-1])
print(count)

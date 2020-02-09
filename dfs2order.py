from collections import defaultdict
graph = defaultdict(list)
weights = defaultdict(list)
count=0

def addEdge(u,v):
    global graph
    graph[u].append(v)
    graph[v].append(u)

def dfs(v,visited):
    global graph
    global weights
    global count
    visited[v]=True
    count+=1
    weights[v].append(count)
    #print(visited)
    print(v,end=" ")

    for i in graph[v]:
        if visited[i]==False:
            dfs(i,visited)
            count+=1
            weights[i].append(count) 

n=int(input())
visited = [False]*(n+1)
edj=int(input())
for _ in range(edj):
    x,y=map(int,input().split())
    addEdge(x,y)
s=int(input())
for ele in graph.values():
    ele.sort()


dfs(s,visited)
count+=1
weights[s].append(count)
print(weights)




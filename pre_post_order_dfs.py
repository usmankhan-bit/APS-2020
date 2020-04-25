from collections import defaultdict
import sys
sys.setrecursionlimit(10000)
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
    weights[v][0]=count
    #print(visited)
    #print(v,end=" ")

    for i in graph[v]:
        if visited[i]==False:
            dfs(i,visited)
            count+=1
            weights[i][1]=count 

n,edj=map(int,input().split(' '))
visited = [False]*(n+1)
for _ in range(edj):
    x,y=map(int,input().split())
    addEdge(x,y)
s=int(input())
for _ in range(1,n+1):
    weights[_]=[0,0]
for ele in graph.values():
    ele.sort()
dfs(s,visited)
count+=1
weights[s][1]=count
#print(weights)
vertex = int(input())
range1 = weights[vertex]
for k,v in weights.items():
    if k==vertex:
        print(k,end=" ")
    elif v[0]>=range1[0] and v[1]<=range1[1]:
        print(k,end=" ")